//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <functional>
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>

using namespace kumi::literals;

TTS_CASE("Check tuple_element of kumi::to_ref result")
{
  float const f{};
  double d;
  std::reference_wrapper<float const> rf = f;
  std::reference_wrapper<double> rd = d;

  auto made = kumi::make_record("a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = rf, "e"_id = rd);
  auto made_lref = kumi::to_ref(made);
  auto made_rref = kumi::to_ref(std::move(made));
  auto made_cref = kumi::to_ref(std::as_const(made));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_lref)>), (kumi::field<kumi::name<"a">, char&>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_lref)>), (kumi::field<kumi::name<"b">, double&>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_lref)>), (kumi::field<kumi::name<"c">, float&>));
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(made_lref)>), (kumi::field<kumi::name<"d">, float const&>));
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(made_lref)>), (kumi::field<kumi::name<"e">, double&>));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_rref)>), (kumi::field<kumi::name<"a">, char&&>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_rref)>), (kumi::field<kumi::name<"b">, double&&>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_rref)>), (kumi::field<kumi::name<"c">, float&&>));
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(made_rref)>), (kumi::field<kumi::name<"d">, float const&>));
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(made_rref)>), (kumi::field<kumi::name<"e">, double&>));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_cref)>), (kumi::field<kumi::name<"a">, char const&>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_cref)>), (kumi::field<kumi::name<"b">, double const&>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_cref)>), (kumi::field<kumi::name<"c">, float const&>));
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(made_cref)>), (kumi::field<kumi::name<"d">, float const&>));
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(made_cref)>), (kumi::field<kumi::name<"e">, double&>));
};
