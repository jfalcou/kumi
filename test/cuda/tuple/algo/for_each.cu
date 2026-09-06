//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/for_each.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  __global__ void accumulate(int* out)
  {
    auto t = kumi::make_tuple(1, 2, 3);
    int count = 0;

    kumi::for_each([&](auto v) { count += v; }, t);
    *out = count;
  }
}

TTS_CASE("Check for_each device behavior")
{
  int out = 0;

  TTS_EXPECT(run_on_device(accumulate, out));
  TTS_EQUAL(out, 6);
};
