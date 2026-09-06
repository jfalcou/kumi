//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/map.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  __global__ void twice(kumi::tuple<int, int, int>* out)
  {
    *out = kumi::map([](auto v) { return v * 2; }, kumi::make_tuple(1, 2, 3));
  }
}

TTS_CASE("Check map(f, tuple) device behavior")
{
  kumi::tuple<int, int, int> out;

  TTS_EXPECT(run_on_device(twice, out));
  TTS_EQUAL(out, (kumi::tuple{2, 4, 6}));
};
