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
#include <array>
#include "test.hpp"

TTS_CASE("Check tuple_element of kumi::to_ref result")
{
  auto made = kumi::make_array('1', '2', '3');
  auto made_lref = kumi::to_ref(made);
  auto made_rref = kumi::to_ref(std::move(made));
  auto made_cref = kumi::to_ref(std::as_const(made));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_lref)>), char&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_lref)>), char&);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_lref)>), char&);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_rref)>), char&&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_rref)>), char&&);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_rref)>), char&&);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_cref)>), char const&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_cref)>), char const&);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_cref)>), char const&);
};

TTS_CASE("Check to_ref result binds to the source array")
{
  auto made = kumi::make_array(1, 2, 3);
  auto refs = kumi::to_ref(made);

  get<1>(refs) = 42;

  TTS_EQUAL((kumi::array{1, 42, 3}), made);
  TTS_EQUAL(get<1>(made), 42);
};
