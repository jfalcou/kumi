//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/for_each.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  __global__ void accumulate(char* flags)
  {
    auto t     = kumi::make_tuple(1, 2, 3);
    int  count = 0;

    kumi::for_each([&](auto v) { count += v; }, t);
    flags[0] = (count == 6);
  }
}

TTS_CASE("Check for_each device behavior")
{
  auto r = run_on_device(accumulate, 1);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
};
