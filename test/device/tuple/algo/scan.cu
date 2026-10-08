//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/scan.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  using sizes = kumi::tuple<std::size_t, std::size_t, std::size_t, std::size_t>;
  using both = kumi::tuple<sizes, sizes>;

  __global__ void running(both* out)
  {
    auto t = kumi::tuple{2., 1, short{55}, 'z'};

    *out = {kumi::inclusive_scan_left([](auto, auto m) { return sizeof(m); }, t, 0),
            kumi::inclusive_scan_left([](auto acc, auto m) { return acc + sizeof(m); }, t, 0)};
  }
}

TTS_CASE("Check inclusive_scan_left device behavior")
{
  both out;

  TTS_EXPECT(run_on_device(running, out));
  TTS_EQUAL(out, (both{sizes{8, 4, 2, 1}, sizes{8, 12, 14, 15}}));
};
