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
  // The host test checks the reference types; a kernel can check them too, and write through them.
  __global__ void references_bind(char* flags)
  {
    auto made      = kumi::make_tuple('1', 2., 3.f);
    auto made_lref = kumi::to_ref(made);

    static_assert(std::is_same_v<std::tuple_element_t<0, decltype(made_lref)>, char&>);
    static_assert(std::is_same_v<std::tuple_element_t<1, decltype(made_lref)>, double&>);
    static_assert(std::is_same_v<std::tuple_element_t<2, decltype(made_lref)>, float&>);

    kumi::get<0>(made_lref) = 'x';
    flags[0] = (kumi::get<0>(made) == 'x');

    char c{};
    double d{};
    auto tied = kumi::tie(c, d);

    static_assert(std::is_same_v<std::tuple_element_t<0, decltype(tied)>, char&>);

    kumi::get<1>(tied) = 2.5;
    flags[1] = (d == 2.5);
  }
}

TTS_CASE("Check to_ref and tie device behavior")
{
  auto r = run_on_device(references_bind, 2);

  TTS_EXPECT(r.ran);
  TTS_EXPECT(r[0]);
  TTS_EXPECT(r[1]);
};
