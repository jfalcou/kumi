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
  using backwards = kumi::tuple<char, float, double, int>;

  __global__ void reversed(backwards* out)
  {
    *out = kumi::reverse(kumi::tuple{1, 2., 3.4f, '5'});
  }

  // The host test moves a moveonly through reverse; compiling the kernel is that check.
  __global__ void reversed_moveonly(char* out)
  {
    auto t = kumi::tuple{1, 'x', moveonly{}};
    *out = kumi::get<1>(kumi::reverse(std::move(t)));
  }
}

TTS_CASE("Check reverse device behavior")
{
  backwards out;

  TTS_EXPECT(run_on_device(reversed, out));
  TTS_EQUAL(out, (backwards{'5', 3.4f, 2., 1}));
};

TTS_CASE("Check reverse device behavior on a moveonly element")
{
  char out = 0;

  TTS_EXPECT(run_on_device(reversed_moveonly, out));
  TTS_EQUAL(out, 'x');
};
