//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <tts/tts.hpp>
#include "device.hpp"
#include "types.hpp"

namespace
{
  __global__ void sizes(kumi::array<std::size_t, 2>* out)
  {
    // A device laying the type out otherwise reports another size here than the host does.
    *out = {sizeof(kumi::array<int, 1>), sizeof(kumi::array<int, 2>)};
  }
}

TTS_CASE("Check EBO device behavior of kumi::array construction")
{
  kumi::array<std::size_t, 2> out;

  TTS_EXPECT(run_on_device(sizes, out));
  TTS_EQUAL(out, (kumi::array<std::size_t, 2>{sizeof(int), 2 * sizeof(int)}));
};
