//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/cartesian_product.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  using row = kumi::tuple<bool, char, double>;
  using ends = kumi::tuple<std::size_t, row, row>;

  __global__ void every_tuple(ends* out)
  {
    auto p =
      kumi::cartesian_product(kumi::tuple{true, false}, kumi::tuple{'a', 'b', 'c'}, kumi::tuple{1.0, 2.1, 4.2, 8.4});

    *out = {p.size(), kumi::get<0>(p), kumi::get<23>(p)};
  }
}

TTS_CASE("Check cartesian_product device behavior")
{
  ends out;

  TTS_EXPECT(run_on_device(every_tuple, out));
  TTS_EQUAL(out, (ends{24ULL, row{true, 'a', 1.0}, row{false, 'c', 8.4}}));
};
