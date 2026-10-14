//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/zip.hpp>
#include <tts/tts.hpp>
#include "device.hpp"
#include "types.hpp"

namespace
{
  using pair = kumi::array<int, 2>;
  using zipped = kumi::array<pair, 4>;

  __global__ void pairs(zipped* out)
  {
    auto numbers = kumi::array{1, 2, 3, 4};
    auto letters = kumi::array{5, 6, 7, 8};

    *out = kumi::zip(numbers, letters);
  }
}

TTS_CASE("Check zip device behavior")
{
  zipped out;

  TTS_EXPECT(run_on_device(pairs, out));
  TTS_EQUAL(out, (zipped{pair{1, 5}, pair{2, 6}, pair{3, 7}, pair{4, 8}}));
};
