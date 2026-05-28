//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/record.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check tuple_element of kumi::to_ref result")
{
  using namespace kumi::literals;

  auto made = kumi::make_record("a"_id = '1', "b"_id = 2., "c"_id = 3.f);
  auto made_lref = kumi::to_ref(made);
  auto made_rref = kumi::to_ref(std::move(made));
  auto made_cref = kumi::to_ref(std::as_const(made));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_lref)>), (kumi::field<kumi::name<"a">, char&>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_lref)>), (kumi::field<kumi::name<"b">, double&>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_lref)>), (kumi::field<kumi::name<"c">, float&>));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_rref)>), (kumi::field<kumi::name<"a">, char&&>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_rref)>), (kumi::field<kumi::name<"b">, double&&>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_rref)>), (kumi::field<kumi::name<"c">, float&&>));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_cref)>), (kumi::field<kumi::name<"a">, char const&>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_cref)>), (kumi::field<kumi::name<"b">, double const&>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_cref)>), (kumi::field<kumi::name<"c">, float const&>));
};
