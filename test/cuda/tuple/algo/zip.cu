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
  using pair = kumi::tuple<int, char>;
  using zipped = kumi::tuple<pair, pair, pair, pair>;

  __global__ void pairs(zipped* out)
  {
    auto numbers = kumi::tuple{1, 2, 3, 4};
    auto letters = kumi::tuple{'a', 'b', 'c', 'd'};

    *out = kumi::zip(numbers, letters);
  }
}

TTS_CASE("Check zip device behavior")
{
  zipped out;

  TTS_EXPECT(run_on_device(pairs, out));
  TTS_EQUAL(out, (zipped{pair{1, 'a'}, pair{2, 'b'}, pair{3, 'c'}, pair{4, 'd'}}));
};
