//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <functional>
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check tuple_element of kumi::to_ref result")
{
  float const f{};
  double d;
  std::reference_wrapper<float const> rf = f;
  std::reference_wrapper<double> rd = d;

  auto made = kumi::make_tuple('1', 2., 3.f, rf, rd);
  auto made_lref = kumi::to_ref(made);
  auto made_rref = kumi::to_ref(std::move(made));
  auto made_cref = kumi::to_ref(std::as_const(made));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_lref)>), char&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_lref)>), double&);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_lref)>), float&);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(made_lref)>), float const&);
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(made_lref)>), double&);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_rref)>), char&&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_rref)>), double&&);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_rref)>), float&&);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(made_rref)>), float const&);
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(made_rref)>), double&);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made_cref)>), char const&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made_cref)>), double const&);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made_cref)>), float const&);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(made_cref)>), float const&);
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(made_cref)>), double&);
};
