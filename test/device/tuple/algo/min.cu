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
  using smallest = kumi::tuple<double, std::size_t, std::size_t, std::size_t>;

  __global__ void tiniest(smallest* out)
  {
    auto t0 = kumi::tuple{'e', 2, 1., short{55}, 'z'};
    auto f0 = kumi::tuple{2., 1., kumi::tuple{'u', 'z'}, 3.f};
    auto size = [](auto m) { return sizeof(m); };

    *out = {kumi::min(t0), kumi::min(t0, size), kumi::min(f0, size), kumi::min_flat(f0, size)};
  }
}

TTS_CASE("Check tuple::min/min_flat device behavior")
{
  smallest out;

  TTS_EXPECT(run_on_device(tiniest, out));
  TTS_EQUAL(out, (smallest{1., sizeof(char), 2 * sizeof(char), sizeof(char)}));
};
