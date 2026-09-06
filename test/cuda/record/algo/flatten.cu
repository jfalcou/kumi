//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/record.hpp>
#include <kumi/algorithm/flatten.hpp>
#include <tts/tts.hpp>
#include "device.hpp"
#include "test.hpp"

namespace
{
  using flattened = kumi::tuple<std::size_t, int, int, int>;

  // Issue #192: flatten on a record.
  __global__ void flatten_nested(flattened* out)
  {
    auto inner = kumi::record{"a"_id = 1, "b"_id = 2};
    auto flat = kumi::flatten(kumi::record{"x"_id = 0, "y"_id = inner});

    *out = {flat.size(), flat["x"_id], flat["y.a"_id], flat["y.b"_id]};
  }
}

TTS_CASE("Check record::flatten device behavior")
{
  flattened out;

  TTS_EXPECT(run_on_device(flatten_nested, out));
  TTS_EQUAL(out, (flattened{3ULL, 0, 1, 2}));
};
