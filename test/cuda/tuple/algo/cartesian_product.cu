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
  __global__ void every_tuple(char* flags)
  {
    auto status = kumi::tuple{true, false};
    auto id     = kumi::tuple{'a', 'b', 'c'};
    auto value  = kumi::tuple{1.0, 2.1, 4.2, 8.4};

    auto p = kumi::cartesian_product(status, id, value);

    flags[0] = (p.size() == 24);

    auto first = kumi::get<0>(p);
    flags[1] = (kumi::get<0>(first) == true) && (kumi::get<1>(first) == 'a') && (kumi::get<2>(first) == 1.0);

    auto last = kumi::get<23>(p);
    flags[2] = (kumi::get<0>(last) == false) && (kumi::get<1>(last) == 'c') && (kumi::get<2>(last) == 8.4);
  }
}

TTS_CASE("Check cartesian_product device behavior")
{
  auto r = run_on_device(every_tuple, 3);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
  TTS_EXPECT(r[2]);
};
