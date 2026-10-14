//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/scan.hpp>
#include <tts/tts.hpp>
#include "device.hpp"
#include "types.hpp"

namespace
{
  using sizes = kumi::array<std::size_t, 4>;
  using both = kumi::array<sizes, 2>;

  __global__ void running(both* out)
  {
    auto t = kumi::array{2, 3, 4, 5};

    *out = {kumi::inclusive_scan_left([](auto, auto m) { return sizeof(m); }, t, std::size_t{0}),
            kumi::inclusive_scan_left([](auto acc, auto m) { return acc + m; }, t, std::size_t{0})};
  }
}

TTS_CASE("Check inclusive_scan_left device behavior")
{
  both out;

  TTS_EXPECT(run_on_device(running, out));
  TTS_EQUAL(out, (both{sizes{4, 4, 4, 4}, sizes{2, 5, 9, 14}}));
};
