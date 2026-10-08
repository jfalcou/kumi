//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/push_pop.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  using pushed_front = kumi::tuple<int, double, char>;
  using pushed_back = kumi::tuple<double, char, int>;
  using popped = kumi::tuple<double, char>;
  using ends = kumi::tuple<pushed_front, pushed_back, popped>;

  __global__ void both_ends(ends* out)
  {
    auto front = kumi::push_front(kumi::tuple{3.5, 'e'}, 4);

    *out = {front, kumi::push_back(kumi::tuple{3.5, 'e'}, 4), kumi::pop_front(front)};
  }
}

TTS_CASE("Check push_front/push_back device behavior")
{
  ends out;

  TTS_EXPECT(run_on_device(both_ends, out));
  TTS_EQUAL(out, (ends{pushed_front{4, 3.5, 'e'}, pushed_back{3.5, 'e', 4}, popped{3.5, 'e'}}));
};
