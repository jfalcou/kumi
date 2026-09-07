//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  using made = kumi::tuple<std::size_t, int, float, char>;

  __global__ void make_and_read(made* out)
  {
    auto t = kumi::make_tuple(1, 2.f, '3');
    *out = made{t.size(), kumi::get<0>(t), kumi::get<1>(t), kumi::get<2>(t)};
  }

  __global__ void copy_is_independent(kumi::tuple<int, int>* out)
  {
    auto t = kumi::make_tuple(1, 2.f, '3');
    auto copy = t;
    kumi::get<0>(copy) = 42;
    *out = {kumi::get<0>(copy), kumi::get<0>(t)};
  }

  // Constant evaluation is where nvcc and clang diverge most, and a kernel is where it is never tested.
  __global__ void constant_evaluation(kumi::tuple<std::size_t, int>* out)
  {
    constexpr auto t = kumi::make_tuple(1, 2.f, '3');
    static_assert(kumi::get<2>(kumi::make_tuple(1, 2.f, '3')) == '3');
    *out = {t.size(), kumi::get<0>(t)};
  }
}

TTS_CASE("Check construction of kumi::tuple via device make_tuple")
{
  made out;

  TTS_EXPECT(run_on_device(make_and_read, out));
  TTS_EQUAL(out, (made{3ULL, 1, 2.f, '3'}));
};

TTS_CASE("Check copy of kumi::tuple in device code")
{
  kumi::tuple<int, int> out;

  TTS_EXPECT(run_on_device(copy_is_independent, out));
  TTS_EQUAL(out, (kumi::tuple{42, 1}));
};

TTS_CASE("Check construction of kumi::tuple via constexpr device make_tuple")
{
  kumi::tuple<std::size_t, int> out;

  TTS_EXPECT(run_on_device(constant_evaluation, out));
  TTS_EQUAL(out, (kumi::tuple{3ULL, 1}));
};
