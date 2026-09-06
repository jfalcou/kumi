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
  __global__ void largest(char* flags)
  {
    auto t0 = kumi::tuple{'e', 2, 7894.5, short{55}, 'z'};

    flags[0] = (kumi::max(t0) == 7894.5);
    flags[1] = (kumi::max(t0, [](auto m) { return sizeof(m); }) == sizeof(double));

    auto f0 = kumi::tuple{'e', 2., kumi::tuple{1., short{55}, 'u'}, 3.f, 'z'};
    flags[2] = (kumi::max(f0, [](auto m) { return sizeof(m); }) == 2 * sizeof(double));
    flags[3] = (kumi::max_flat(f0, [](auto m) { return sizeof(m); }) == sizeof(double));
  }
}

TTS_CASE("Check tuple::max/max_flat device behavior")
{
  auto r = run_on_device(largest, 4);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
  TTS_EXPECT(r[2]);
  TTS_EXPECT(r[3]);
};
