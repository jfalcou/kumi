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
#include "test.hpp"
#include <array>

TTS_CASE("Check tuple_element of the output of result::builder_make_t")
{
  using arr = kumi::builder_make_t<kumi::array<int, 5>, int, int, int, int, int>;
  TTS_TYPE_IS(arr, (kumi::array<int, 5>));
  TTS_TYPE_IS((std::tuple_element_t<0, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<1, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<2, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<3, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<4, arr>), int);

  using dbl = kumi::builder_make_t<kumi::array<double, 3>, double, double, double>;
  TTS_TYPE_IS(dbl, (kumi::array<double, 3>));
  TTS_TYPE_IS((std::tuple_element_t<0, dbl>), double);
  TTS_TYPE_IS((std::tuple_element_t<1, dbl>), double);
  TTS_TYPE_IS((std::tuple_element_t<2, dbl>), double);
};

TTS_CASE("Check tuple_element of the output of builder")
{
  using arr = decltype(kumi::builder<kumi::array<int, 5>>::make(1, 2, 3, 4, 5));
  TTS_TYPE_IS((arr), (kumi::array<int, 5>));
  TTS_TYPE_IS((std::tuple_element_t<0, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<1, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<2, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<3, arr>), int);
  TTS_TYPE_IS((std::tuple_element_t<4, arr>), int);

  using arr2 = decltype(kumi::builder<kumi::array<int, 5>>::build(1, 2, 3, 4, 5));
  TTS_TYPE_IS((arr2), (kumi::array<int, 5>));
  TTS_TYPE_IS((std::tuple_element_t<0, arr2>), int);
  TTS_TYPE_IS((std::tuple_element_t<4, arr2>), int);

  using ft = decltype(kumi::builder<kumi::array<>>::build());
  TTS_TYPE_IS((ft), (kumi::array<>));
};

TTS_CASE("Check constexpr tuple_element of the output of builder")
{
  constexpr auto arr = kumi::builder<kumi::array<int, 5>>::make(1, 2, 3, 4, 5);
  TTS_TYPE_IS((decltype(arr)), (kumi::array<int, 5> const));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(arr)>), int const);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(arr)>), int const);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(arr)>), int const);
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(arr)>), int const);
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(arr)>), int const);

  constexpr auto arr2 = kumi::builder<kumi::array<int, 5>>::build(1, 2, 3, 4, 5);
  TTS_TYPE_IS((decltype(arr2)), (kumi::array<int, 5> const));
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(arr2)>), int const);

  constexpr auto ft = kumi::builder<kumi::array<>>::build();
  TTS_TYPE_IS((decltype(ft)), (kumi::array<> const));
};
