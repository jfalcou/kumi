//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/zip.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  __global__ void pairs(char* flags)
  {
    auto numbers = kumi::tuple{1, 2, 3, 4};
    auto letters = kumi::tuple{'a', 'b', 'c', 'd'};
    auto ratio = kumi::tuple{1.f, 0.5f, 0.25, 0.01};

    auto z = kumi::zip(numbers, letters);
    flags[0] = (z.size() == 4);
    flags[1] = (kumi::get<0>(kumi::get<0>(z)) == 1) && (kumi::get<1>(kumi::get<0>(z)) == 'a');
    flags[2] = (kumi::get<0>(kumi::get<3>(z)) == 4) && (kumi::get<1>(kumi::get<3>(z)) == 'd');

    auto three = kumi::zip(numbers, letters, ratio);
    flags[3] = (kumi::get<0>(kumi::get<2>(three)) == 3) && (kumi::get<1>(kumi::get<2>(three)) == 'c') &&
               (kumi::get<2>(kumi::get<2>(three)) == 0.25);
  }
}

TTS_CASE("Check zip device behavior")
{
  auto r = run_on_device(pairs, 4);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
  TTS_EXPECT(r[2]);
  TTS_EXPECT(r[3]);
};
