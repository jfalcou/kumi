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
  __global__ void sums(char* flags)
  {
    auto t = kumi::make_tuple(1, 2, 3);

    flags[0] = (kumi::fold_left([](auto a, auto b) { return a + b; }, t, 0) == 6);
    flags[1] = (kumi::fold_right([](auto a, auto b) { return a + b; }, t, 0) == 6);
  }
}

TTS_CASE("Check tuple::fold_left device behavior")
{
  auto r = run_on_device(sums, 2);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
};
