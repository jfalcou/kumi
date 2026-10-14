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
  using largest = kumi::array<std::size_t, 4>;

  __global__ void biggest(largest* out)
  {
    auto t0 = kumi::array{5, 2, 8, 3};
    auto f0 = kumi::array{9, 1, 7, 4};
    auto size = [](auto m) { return sizeof(m); };

    *out = {kumi::max(t0), kumi::max(t0, size), kumi::max(f0, size), kumi::max_flat(f0, size)};
  }
}

TTS_CASE("Check array::max/max_flat device behavior")
{
  largest out;

  TTS_EXPECT(run_on_device(biggest, out));
  TTS_EQUAL(out, (largest{8, sizeof(int), sizeof(int), sizeof(int)}));
};
