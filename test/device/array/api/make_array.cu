//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <tts/tts.hpp>
#include "device.hpp"
#include "types.hpp"

namespace
{
  using made = kumi::array<std::size_t, 4>;

  __global__ void make_and_read(made* out)
  {
    auto t = kumi::make_array(1, 2, 3);
    *out = {t.size(), kumi::get<0>(t), kumi::get<1>(t), kumi::get<2>(t)};
  }

  __global__ void copy_is_independent(kumi::array<int, 2>* out)
  {
    auto t = kumi::make_array(1, 2, 3);
    auto copy = t;
    kumi::get<0>(copy) = 42;
    *out = {kumi::get<0>(copy), kumi::get<0>(t)};
  }

  // Constant evaluation is where nvcc and clang diverge most, and a kernel is where it is never tested.
  __global__ void constant_evaluation(kumi::array<std::size_t, 2>* out)
  {
    constexpr auto t = kumi::make_array(1, 2, 3);
    static_assert(kumi::get<2>(kumi::make_array(1, 2, 3)) == 3);
    *out = {t.size(), kumi::get<0>(t)};
  }
}

TTS_CASE("Check construction of kumi::array via device make_array")
{
  made out;

  TTS_EXPECT(run_on_device(make_and_read, out));
  TTS_EQUAL(out, (made{3ULL, 1, 2, 3}));
};

TTS_CASE("Check copy of kumi::array in device code")
{
  kumi::array<int, 2> out;

  TTS_EXPECT(run_on_device(copy_is_independent, out));
  TTS_EQUAL(out, (kumi::array<int, 2>{42, 1}));
};

TTS_CASE("Check construction of kumi::array via constexpr device make_array")
{
  kumi::array<std::size_t, 2> out;

  TTS_EXPECT(run_on_device(constant_evaluation, out));
  TTS_EQUAL(out, (kumi::array<std::size_t, 2>{3ULL, 1}));
};
