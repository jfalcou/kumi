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
  // Issue #192: flatten on a record.
  __global__ void flatten_nested(char* flags)
  {
    auto inner = kumi::record{"a"_id = 1, "b"_id = 2};
    auto flat = kumi::flatten(kumi::record{"x"_id = 0, "y"_id = inner});

    flags[0] = (flat.size() == 3);
    flags[1] = (flat["x"_id] == 0);
    flags[2] = (flat["y.a"_id] == 1) && (flat["y.b"_id] == 2);
  }
}

TTS_CASE("Check record::flatten device behavior")
{
  auto r = run_on_device(flatten_nested, 3);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
  TTS_EXPECT(r[2]);
};
