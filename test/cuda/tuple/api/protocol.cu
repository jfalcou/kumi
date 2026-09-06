//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  __global__ void bindings(kumi::tuple<int, double, char, int>* out)
  {
    auto t = kumi::make_tuple(1, 2.5, 'c');

    auto [a, b, c] = t;

    auto& [d, e, f] = t;
    d = 42;

    *out = {a, b, c, kumi::get<0>(t)};
  }
}

TTS_CASE("Check structured bindings device behavior")
{
  kumi::tuple<int, double, char, int> out;

  TTS_EXPECT(run_on_device(bindings, out));
  TTS_EQUAL(out, (kumi::tuple{1, 2.5, 'c', 42}));
};
