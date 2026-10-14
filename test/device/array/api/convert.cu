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
  struct Int
  {
    int value = 0;

    Int() = default;

    __host__ __device__ Int(int v) : value(v) {}
  };

  // Issue #192: a member whose constructor is explicit.
  struct ExpInt
  {
    int value = 0;

    ExpInt() = default;

    __host__ __device__ explicit ExpInt(int v) : value(v) {}
  };

  __global__ void convert(kumi::array<int, 2>* out)
  {
    auto in = kumi::array{1, 2};
    auto to = static_cast<kumi::array<Int, 2>>(in);

    *out = {kumi::get<0>(to).value, kumi::get<1>(to).value};
  }

  // nvcc 13.2.51 rejects this conversion, in host code as much as in a kernel; clang and g++ accept it.
#if !defined(__NVCC__)
  __global__ void convert_explicit(kumi::array<int, 2>* out)
  {
    auto in = kumi::array{1, 2};
    auto to = static_cast<kumi::array<ExpInt, 2>>(in);

    *out = {kumi::get<0>(to).value, kumi::get<1>(to).value};
  }
#endif
}

TTS_CASE("Check array to constructible type device conversion")
{
  kumi::array<int, 2> out;

  TTS_EXPECT(run_on_device(convert, out));
  TTS_EQUAL(out, (kumi::array<int, 2>{1, 2}));
};

#if !defined(__NVCC__)
TTS_CASE("Check array to explicitly constructible type device conversion")
{
  kumi::array<int, 2> out;

  TTS_EXPECT(run_on_device(convert_explicit, out));
  TTS_EQUAL(out, (kumi::array<int, 2>{1, 2}));
};
#endif
