//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/cat.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  using joined = kumi::tuple<int, double, float, int, short, double>;

  __global__ void concatenate(joined* out)
  {
    short s = 55;
    *out = kumi::cat(kumi::tuple{1, 2.}, kumi::tuple{3.f, 4}, kumi::tuple{s, 6.7});
  }
}

TTS_CASE("Check cat device behavior")
{
  joined out;

  TTS_EXPECT(run_on_device(concatenate, out));
  TTS_EQUAL(out, (joined{1, 2., 3.f, 4, short{55}, 6.7}));
};
