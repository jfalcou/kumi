//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/push_pop.hpp>
#include <tts/tts.hpp>
#include "device.hpp"
#include "types.hpp"

namespace
{
  // Both pushes keep the array homogeneous: pushing an int into an int array.
  __global__ void both_ends(kumi::array<int, 3>* out)
  {
    auto front = kumi::push_front(kumi::array{3, 5}, 9); // {9,3,5}
    auto back = kumi::push_back(kumi::array{3, 5}, 9);   // {3,5,9}
    auto popped = kumi::pop_front(front);                // {3,5}

    // One representative value per operation: front's first element, back's last element,
    // and popped's first element.
    *out = {kumi::get<0>(front), kumi::get<2>(back), kumi::get<0>(popped)};
  }
}

TTS_CASE("Check push_front/push_back device behavior")
{
  kumi::array<int, 3> out;

  TTS_EXPECT(run_on_device(both_ends, out));
  TTS_EQUAL(out, (kumi::array<int, 3>{9, 9, 3}));
};
