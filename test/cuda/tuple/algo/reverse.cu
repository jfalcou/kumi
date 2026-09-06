//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/reverse.hpp>
#include <tts/tts.hpp>
#include "device.hpp"
#include "test.hpp"

namespace
{
  __global__ void backwards(char* flags)
  {
    auto t = kumi::tuple{1, 2., 3.4f, '5'};
    auto r = kumi::reverse(t);

    flags[0] = (kumi::get<0>(r) == '5') && (kumi::get<1>(r) == 3.4f);
    flags[1] = (kumi::get<2>(r) == 2.) && (kumi::get<3>(r) == 1);
    flags[2] = (kumi::reverse(kumi::tuple<>{}).size() == 0);

    // The host test moves a moveonly through reverse; the kernel does the same, and compiling is the check.
    auto t2 = kumi::tuple{1, 'x', moveonly{}};
    flags[3] = (kumi::get<1>(kumi::reverse(std::move(t2))) == 'x');
  }
}

TTS_CASE("Check reverse device behavior")
{
  auto r = run_on_device(backwards, 4);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
  TTS_EXPECT(r[2]);
  TTS_EXPECT(r[3]);
};
