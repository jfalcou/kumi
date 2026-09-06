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
  // Issue #192: a member whose constructor is explicit.
  struct ExpInt
  {
    int value = 0;

    ExpInt() = default;

    __host__ __device__ explicit ExpInt(int v) : value(v) {}
  };

  // nvcc 13.2.51 rejects this conversion, in host code as much as in a kernel; clang and g++ accept it.
#if !defined(__NVCC__)
  __global__ void convert(kumi::tuple<int, int>* out)
  {
    auto in = kumi::tuple{1, 2};
    auto to = static_cast<kumi::tuple<ExpInt, ExpInt>>(in);
    *out = {kumi::get<0>(to).value, kumi::get<1>(to).value};
  }
#endif
}

#if !defined(__NVCC__)
TTS_CASE("Check tuple to constructible type device conversion")
{
  kumi::tuple<int, int> out;

  TTS_EXPECT(run_on_device(convert, out));
  TTS_EQUAL(out, (kumi::tuple{1, 2}));
};
#endif
