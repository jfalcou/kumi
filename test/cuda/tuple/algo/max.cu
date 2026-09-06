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
  using largest = kumi::tuple<double, std::size_t, std::size_t, std::size_t>;

  __global__ void biggest(largest* out)
  {
    auto t0 = kumi::tuple{'e', 2, 7894.5, short{55}, 'z'};
    auto f0 = kumi::tuple{'e', 2., kumi::tuple{1., short{55}, 'u'}, 3.f, 'z'};
    auto size = [](auto m) { return sizeof(m); };

    *out = {kumi::max(t0), kumi::max(t0, size), kumi::max(f0, size), kumi::max_flat(f0, size)};
  }
}

TTS_CASE("Check tuple::max/max_flat device behavior")
{
  largest out;

  TTS_EXPECT(run_on_device(biggest, out));
  TTS_EQUAL(out, (largest{7894.5, sizeof(double), 2 * sizeof(double), sizeof(double)}));
};
