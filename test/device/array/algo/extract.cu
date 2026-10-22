//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/extract.hpp>
#include <tts/tts.hpp>
#include "device.hpp"
#include "types.hpp"

namespace
{
  using namespace kumi::literals;

  using whole = kumi::array<int, 4>;

  __global__ void cut(kumi::array<int, 3>* out)
  {
    kumi::array t = {1, 2, 3, 4};

    auto full = kumi::extract(t, 0_c);      // {1,2,3,4}
    auto head = kumi::extract(t, 0_c, 2_c); // {1,2}
    auto once = kumi::extract(t, 0_c, 1_c); // {1}

    // One representative value per slice: whole's last, head's last, and once's only element.
    *out = {kumi::get<3>(full), kumi::get<1>(head), kumi::get<0>(once)};
  }
}

TTS_CASE("Check extract device behavior")
{
  kumi::array<int, 3> out;

  TTS_EXPECT(run_on_device(cut, out));
  TTS_EQUAL(out, (kumi::array<int, 3>{4, 2, 1}));
};
