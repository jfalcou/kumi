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
  __global__ void both_ends(char* flags)
  {
    auto front = kumi::push_front(kumi::tuple{3.5, 'e'}, 4);
    flags[0] = (front.size() == 3) && (kumi::get<0>(front) == 4) && (kumi::get<1>(front) == 3.5);

    auto back = kumi::push_back(kumi::tuple{3.5, 'e'}, 4);
    flags[1] = (back.size() == 3) && (kumi::get<2>(back) == 4);

    auto popped = kumi::pop_front(front);
    flags[2] = (popped.size() == 2) && (kumi::get<0>(popped) == 3.5) && (kumi::get<1>(popped) == 'e');
  }
}

TTS_CASE("Check push_front/push_back device behavior")
{
  auto r = run_on_device(both_ends, 3);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
  TTS_EXPECT(r[2]);
};
