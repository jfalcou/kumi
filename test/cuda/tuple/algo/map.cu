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
  __global__ void twice(char* flags)
  {
    auto t = kumi::make_tuple(1, 2, 3);
    auto u = kumi::map([](auto v) { return v * 2; }, t);

    flags[0] = (kumi::get<0>(u) == 2);
    flags[1] = (kumi::get<1>(u) == 4);
    flags[2] = (kumi::get<2>(u) == 6);
  }
}

TTS_CASE("Check map(f, tuple) device behavior")
{
  auto r = run_on_device(twice, 3);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
  TTS_EXPECT(r[2]);
};
