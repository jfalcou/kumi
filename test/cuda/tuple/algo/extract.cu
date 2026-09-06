//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/extract.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  using namespace kumi::literals;

  using whole = kumi::tuple<char, double, float, int>;
  using head = kumi::tuple<char, double>;
  using one = kumi::tuple<char>;
  using slices = kumi::tuple<whole, head, one>;

  __global__ void cut(slices* out)
  {
    kumi::tuple t = {'1', 2., 3.f, 4};

    *out = {kumi::extract(t, 0_c), kumi::extract(t, 0_c, 2_c), kumi::extract(t, 0_c, 1_c)};
  }
}

TTS_CASE("Check extract device behavior")
{
  slices out;

  TTS_EXPECT(run_on_device(cut, out));
  TTS_EQUAL(out, (slices{whole{'1', 2., 3.f, 4}, head{'1', 2.}, one{'1'}}));
};
