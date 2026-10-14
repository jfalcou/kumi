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
  // The host test checks the reference types; a kernel checks them too, and writes through them.
  __global__ void references_bind(kumi::array<char, 2>* out)
  {
    auto made = kumi::make_array('1', '2', '3');
    auto made_lref = kumi::to_ref(made);

    static_assert(std::is_same_v<std::tuple_element_t<0, decltype(made_lref)>, char&>);
    static_assert(std::is_same_v<std::tuple_element_t<1, decltype(made_lref)>, char&>);
    static_assert(std::is_same_v<std::tuple_element_t<2, decltype(made_lref)>, char&>);

    kumi::get<0>(made_lref) = 'x';

    char c{};
    char d{};
    auto tied = kumi::tie(c, d);

    static_assert(std::is_same_v<std::tuple_element_t<0, decltype(tied)>, char&>);

    kumi::get<1>(tied) = 'y';

    *out = {kumi::get<0>(made), d};
  }
}

TTS_CASE("Check to_ref and tie device behavior")
{
  kumi::array<char, 2> out;

  TTS_EXPECT(run_on_device(references_bind, out));
  TTS_EQUAL(out, (kumi::array<char, 2>{'x', 'y'}));
};
