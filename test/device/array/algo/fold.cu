//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/fold.hpp>
#include <tts/tts.hpp>
#include "device.hpp"
#include "types.hpp"

namespace
{
  __global__ void sums(kumi::array<int, 2>* out)
  {
    auto t = kumi::make_array(1, 2, 3);
    auto add = [](auto a, auto b) { return a + b; };

    *out = {kumi::fold_left(add, t, 0), kumi::fold_right(add, t, 0)};
  }
}

TTS_CASE("Check array::fold_left device behavior")
{
  kumi::array<int, 2> out;

  TTS_EXPECT(run_on_device(sums, out));
  TTS_EQUAL(out, (kumi::array<int, 2>{6, 6}));
};
