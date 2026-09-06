//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/scan.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  __global__ void running(char* flags)
  {
    auto t = kumi::tuple{2., 1, short{55}, 'z'};

    auto sizes = kumi::inclusive_scan_left([](auto, auto m) { return sizeof(m); }, t, 0);
    flags[0] = (kumi::get<0>(sizes) == 8) && (kumi::get<1>(sizes) == 4);
    flags[1] = (kumi::get<2>(sizes) == 2) && (kumi::get<3>(sizes) == 1);

    auto accumulated = kumi::inclusive_scan_left([](auto acc, auto m) { return acc + sizeof(m); }, t, 0);
    flags[2] = (kumi::get<0>(accumulated) == 8) && (kumi::get<1>(accumulated) == 12);
    flags[3] = (kumi::get<2>(accumulated) == 14) && (kumi::get<3>(accumulated) == 15);
  }
}

TTS_CASE("Check inclusive_scan_left device behavior")
{
  auto r = run_on_device(running, 4);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
  TTS_EXPECT(r[2]);
  TTS_EXPECT(r[3]);
};
