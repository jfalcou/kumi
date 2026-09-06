//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/minmax.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  __global__ void smallest(char* flags)
  {
    auto t0 = kumi::tuple{'e', 2, 1., short{55}, 'z'};

    flags[0] = (kumi::min(t0) == 1.);
    flags[1] = (kumi::min(t0, [](auto m) { return sizeof(m); }) == sizeof(char));

    auto f0 = kumi::tuple{2., 1., kumi::tuple{'u', 'z'}, 3.f};
    flags[2] = (kumi::min(f0, [](auto m) { return sizeof(m); }) == 2 * sizeof(char));
    flags[3] = (kumi::min_flat(f0, [](auto m) { return sizeof(m); }) == sizeof(char));
  }
}

TTS_CASE("Check tuple::min/min_flat device behavior")
{
  auto r = run_on_device(smallest, 4);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
  TTS_EXPECT(r[2]);
  TTS_EXPECT(r[3]);
};
