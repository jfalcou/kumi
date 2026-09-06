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
  __global__ void convert(char* flags)
  {
    auto in = kumi::tuple{1, 2};
    auto out = static_cast<kumi::tuple<ExpInt, ExpInt>>(in);

    flags[0] = (kumi::get<0>(out).value == 1);
    flags[1] = (kumi::get<1>(out).value == 2);
  }
#endif
}

#if !defined(__NVCC__)
TTS_CASE("Check tuple to constructible type device conversion")
{
  auto r = run_on_device(convert, 2);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
};
#endif
