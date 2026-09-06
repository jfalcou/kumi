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

  __global__ void slices(char* flags)
  {
    kumi::tuple t = {'1', 2., 3.f, 4};

    auto whole = kumi::extract(t, 0_c);
    auto head  = kumi::extract(t, 0_c, 2_c);
    auto one   = kumi::extract(t, 0_c, 1_c);

    flags[0] = (whole.size() == 4) && (kumi::get<3>(whole) == 4);
    flags[1] = (head.size() == 2) && (kumi::get<0>(head) == '1') && (kumi::get<1>(head) == 2.);
    flags[2] = (one.size() == 1) && (kumi::get<0>(one) == '1');
  }
}

TTS_CASE("Check extract device behavior")
{
  auto r = run_on_device(slices, 3);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
  TTS_EXPECT(r[2]);
};
