//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <tts/tts.hpp>
#include "device.hpp"
#include "types.hpp"

namespace
{
  __global__ void bindings(kumi::array<int, 4>* out)
  {
    auto t = kumi::make_array(1, 2, 3);

    auto [a, b, c] = t;

    auto& [d, e, f] = t;
    d = 42;

    *out = {a, b, c, kumi::get<0>(t)};
  }
}

TTS_CASE("Check structured bindings device behavior")
{
  kumi::array<int, 4> out;

  TTS_EXPECT(run_on_device(bindings, out));
  TTS_EQUAL(out, (kumi::array<int, 4>{1, 2, 3, 42}));
};
