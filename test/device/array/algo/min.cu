//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/minmax.hpp>
#include <tts/tts.hpp>
#include "device.hpp"
#include "types.hpp"

namespace
{
  using smallest = kumi::array<std::size_t, 4>;

  __global__ void tiniest(smallest* out)
  {
    auto t0 = kumi::array{5, 2, 8, 3};
    auto f0 = kumi::array{9, 1, 7, 4};
    auto size = [](auto m) { return sizeof(m); };

    *out = {kumi::min(t0), kumi::min(t0, size), kumi::min(f0, size), kumi::min_flat(f0, size)};
  }
}

TTS_CASE("Check array::min/min_flat device behavior")
{
  smallest out;

  TTS_EXPECT(run_on_device(tiniest, out));
  TTS_EQUAL(out, (smallest{2, sizeof(int), sizeof(int), sizeof(int)}));
};
