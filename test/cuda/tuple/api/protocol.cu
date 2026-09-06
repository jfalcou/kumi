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
  __global__ void bindings(char* flags)
  {
    auto t = kumi::make_tuple(1, 2.5, 'c');

    auto [a, b, c] = t;
    flags[0] = (a == 1) && (b == 2.5) && (c == 'c');

    auto& [d, e, f] = t;
    d = 42;
    flags[1] = (kumi::get<0>(t) == 42) && (e == 2.5) && (f == 'c');
  }
}

TTS_CASE("Check structured bindings device behavior")
{
  auto r = run_on_device(bindings, 2);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
};
