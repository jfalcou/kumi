//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <functional>
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>

using namespace kumi::literals;

TTS_CASE("Check tuple_element of kumi::to_ref result")
{
  float const                         f {};
  double                              d;
  std::reference_wrapper<float const> rf = f;
  std::reference_wrapper<double>      rd = d;

  auto made = kumi::make_record("a"_f = '1', "b"_f = 2., "c"_f = 3.f, "d"_f = rf, "e"_f = rd);
  auto made_lref = kumi::to_ref(made);
  auto made_rref = kumi::to_ref(std::move(made));
  auto made_cref = kumi::to_ref(std::as_const(made));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_lref)>), (kumi::field_capture<"a", char&>          ));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_lref)>), (kumi::field_capture<"b", double&>        ));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_lref)>), (kumi::field_capture<"c", float&>         ));
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(made_lref)>), (kumi::field_capture<"d", float const&>   ));
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(made_lref)>), (kumi::field_capture<"e", double&>        ));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_rref)>), (kumi::field_capture<"a", char&&>         ));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_rref)>), (kumi::field_capture<"b", double&&>       ));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_rref)>), (kumi::field_capture<"c", float&&>        ));
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(made_rref)>), (kumi::field_capture<"d", float const&>   ));
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(made_rref)>), (kumi::field_capture<"e", double&>        ));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_cref)>), (kumi::field_capture<"a", char const&>    ));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_cref)>), (kumi::field_capture<"b", double const&>  ));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_cref)>), (kumi::field_capture<"c", float const&>   ));
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(made_cref)>), (kumi::field_capture<"d", float const&>   ));
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(made_cref)>), (kumi::field_capture<"e", double&>        ));
};

