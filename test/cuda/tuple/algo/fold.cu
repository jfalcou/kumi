//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/fold.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  __global__ void sums(kumi::tuple<int, int>* out)
  {
    auto t = kumi::make_tuple(1, 2, 3);
    auto add = [](auto a, auto b) { return a + b; };

    *out = {kumi::fold_left(add, t, 0), kumi::fold_right(add, t, 0)};
  }
}

TTS_CASE("Check tuple::fold_left device behavior")
{
  kumi::tuple<int, int> out;

  TTS_EXPECT(run_on_device(sums, out));
  TTS_EQUAL(out, (kumi::tuple{6, 6}));
};
