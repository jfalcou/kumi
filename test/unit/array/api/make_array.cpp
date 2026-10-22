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

TTS_CASE("Check tuple_element of kumi::array")
{
  using made = decltype(kumi::make_array('1', '2', '3'));

  TTS_TYPE_IS((std::tuple_element_t<0, made>), char);
  TTS_TYPE_IS((std::tuple_element_t<1, made>), char);
  TTS_TYPE_IS((std::tuple_element_t<2, made>), char);
};

TTS_CASE("Check construction of kumi::array via make_array")
{
  auto t1 = kumi::make_array(1);
  auto t2 = kumi::make_array(1, 2);
  auto t3 = kumi::make_array(1., 2., 3.);
  auto t4 = kumi::make_array('1', '2', '3', '4');

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t1), 1>));
  TTS_EQUAL(t1.size(), 1ULL);
  TTS_EQUAL(get<0>(t1), 1);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t2), 2>));
  TTS_EQUAL(t2.size(), 2ULL);
  TTS_EQUAL(get<0>(t2), 1);
  TTS_EQUAL(get<1>(t2), 2);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t3), 3>));
  TTS_EQUAL(t3.size(), 3ULL);
  TTS_EQUAL(get<0>(t3), 1.);
  TTS_EQUAL(get<1>(t3), 2.);
  TTS_EQUAL(get<2>(t3), 3.);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t4), 4>));
  TTS_EQUAL(t4.size(), 4ULL);
  TTS_EQUAL(get<0>(t4), '1');
  TTS_EQUAL(get<1>(t4), '2');
  TTS_EQUAL(get<2>(t4), '3');
  TTS_EQUAL(get<3>(t4), '4');

  auto m0 = moveonly{};
  TTS_EXPECT_COMPILES(m0, { kumi::make_array(std::move(m0), std::move(m0)); });
};

TTS_CASE("Check construction of kumi::array via constexpr make_array")
{
  constexpr auto t1 = kumi::make_array(1);
  constexpr auto t2 = kumi::make_array(1, 2);
  constexpr auto t3 = kumi::make_array(1., 2., 3.);
  constexpr auto t4 = kumi::make_array('1', '2', '3', '4');

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t1), 1>));
  TTS_CONSTEXPR_EQUAL(t1.size(), 1ULL);
  TTS_CONSTEXPR_EQUAL(get<0>(t1), 1);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t2), 2>));
  TTS_CONSTEXPR_EQUAL(t2.size(), 2ULL);
  TTS_CONSTEXPR_EQUAL(get<0>(t2), 1);
  TTS_CONSTEXPR_EQUAL(get<1>(t2), 2);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t3), 3>));
  TTS_CONSTEXPR_EQUAL(t3.size(), 3ULL);
  TTS_CONSTEXPR_EQUAL(get<0>(t3), 1.);
  TTS_CONSTEXPR_EQUAL(get<1>(t3), 2.);
  TTS_CONSTEXPR_EQUAL(get<2>(t3), 3.);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t4), 4>));
  TTS_CONSTEXPR_EQUAL(t4.size(), 4ULL);
  TTS_CONSTEXPR_EQUAL(get<0>(t4), '1');
  TTS_CONSTEXPR_EQUAL(get<1>(t4), '2');
  TTS_CONSTEXPR_EQUAL(get<2>(t4), '3');
  TTS_CONSTEXPR_EQUAL(get<3>(t4), '4');
};
