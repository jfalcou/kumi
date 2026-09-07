//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/apply.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  // Issue #192: a lambda through the requires clause of kumi::apply.
  __global__ void sum(kumi::tuple<int, std::size_t>* out)
  {
    auto t = kumi::make_tuple(1, 2, 3);

    *out = {kumi::apply([](auto... v) { return (v + ...); }, t),
            kumi::apply([](auto... v) { return sizeof...(v); }, t)};
  }
}

TTS_CASE("Check apply device behavior")
{
  kumi::tuple<int, std::size_t> out;

  TTS_EXPECT(run_on_device(sum, out));
  TTS_EQUAL(out, (kumi::tuple{6, 3ULL}));
};
