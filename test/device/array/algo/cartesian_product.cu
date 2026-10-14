//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/cartesian_product.hpp>
#include <tts/tts.hpp>
#include "device.hpp"
#include "types.hpp"

namespace
{
  using row = kumi::array<int, 3>;
  using rows = kumi::array<row, 3>;

  // {1,2} x {3,4} x {5,6} yields 8 rows of three ints.
  __global__ void every_cell(rows* out)
  {
    auto p = kumi::cartesian_product(kumi::array{1, 2}, kumi::array{3, 4}, kumi::array{5, 6});

    *out = {kumi::get<0>(p), kumi::get<7>(p), kumi::get<4>(p)};
  }
}

TTS_CASE("Check cartesian_product device behavior")
{
  rows out;

  TTS_EXPECT(run_on_device(every_cell, out));
  TTS_EQUAL(out, (rows{row{1, 3, 5}, row{2, 4, 6}, row{2, 3, 5}}));
};
