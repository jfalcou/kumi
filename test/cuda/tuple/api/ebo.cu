//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>
#include "device.hpp"

namespace
{
  __global__ void sizes(char* flags)
  {
    // A device laying the type out otherwise reports another size here than the host does.
    flags[0] = (sizeof(kumi::tuple<int>) == sizeof(int));
    flags[1] = (sizeof(kumi::tuple<int, double>) == sizeof(double) * 2);
  }
}

TTS_CASE("Check EBO device behavior of kumi::tuple construction")
{
  auto r = run_on_device(sizes, 2);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
};
