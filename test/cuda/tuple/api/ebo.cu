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
  __global__ void sizes(kumi::tuple<std::size_t, std::size_t>* out)
  {
    // A device laying the type out otherwise reports another size here than the host does.
    *out = {sizeof(kumi::tuple<int>), sizeof(kumi::tuple<int, double>)};
  }
}

TTS_CASE("Check EBO device behavior of kumi::tuple construction")
{
  kumi::tuple<std::size_t, std::size_t> out;

  TTS_EXPECT(run_on_device(sizes, out));
  TTS_EQUAL(out, (kumi::tuple{sizeof(int), 2 * sizeof(double)}));
};
