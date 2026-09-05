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
  __global__ void make_and_read(char* flags)
  {
    auto t = kumi::make_tuple(1, 2.f, '3');

    flags[0] = (t.size() == 3);
    flags[1] = (kumi::get<0>(t) == 1);
    flags[2] = (kumi::get<1>(t) == 2.f);
    flags[3] = (kumi::get<2>(t) == '3');

    auto copy          = t;
    kumi::get<0>(copy) = 42;
    flags[4]           = (kumi::get<0>(copy) == 42) && (kumi::get<0>(t) == 1);
  }
}

TTS_CASE("Check construction of kumi::tuple via device make_tuple")
{
  auto r = run_on_device(make_and_read, 5);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
  TTS_EXPECT(r[2]);
  TTS_EXPECT(r[3]);
  TTS_EXPECT(r[4]);
};
