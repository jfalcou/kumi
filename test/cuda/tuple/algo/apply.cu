//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/apply.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  // Issue #192: a lambda through the requires clause of kumi::apply.
  __global__ void sum(char* flags)
  {
    auto t = kumi::make_tuple(1, 2, 3);

    flags[0] = (kumi::apply([](auto... v) { return (v + ...); }, t) == 6);
    flags[1] = (kumi::apply([](auto... v) { return sizeof...(v); }, t) == 3);
  }
}

TTS_CASE("Check apply device behavior")
{
  auto r = run_on_device(sum, 2);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
};
