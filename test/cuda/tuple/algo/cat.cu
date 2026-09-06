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
  __global__ void concatenate(char* flags)
  {
    short s = 55;
    auto  c = kumi::cat(kumi::tuple{1, 2.}, kumi::tuple{3.f, 4}, kumi::tuple{s, 6.7});

    flags[0] = (c.size() == 6);
    flags[1] = (kumi::get<0>(c) == 1) && (kumi::get<1>(c) == 2.) && (kumi::get<2>(c) == 3.f);
    flags[2] = (kumi::get<3>(c) == 4) && (kumi::get<4>(c) == 55) && (kumi::get<5>(c) == 6.7);

    flags[3] = (kumi::cat(kumi::tuple{1, 2.}, kumi::tuple{}).size() == 2);
  }
}

TTS_CASE("Check cat device behavior")
{
  auto r = run_on_device(concatenate, 4);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
  TTS_EXPECT(r[2]);
  TTS_EXPECT(r[3]);
};
