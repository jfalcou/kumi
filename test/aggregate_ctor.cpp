//==================================================================================================
/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check tuple_element of kumi::tuple")
{
  kumi::tuple aggregate = {'1', 2., 3.f};
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(aggregate)>), char);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(aggregate)>), double);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(aggregate)>), float);
};

TTS_CASE("Check construction of kumi::tuple as an aggregate")
{
  kumi::tuple t0 = {};
  kumi::tuple t1 = {1};
  kumi::tuple t2 = {1.f, 2};
  kumi::tuple t3 = {1., 2.f, 3};
  kumi::tuple t4 = {'1', 2., 3.f, 4};

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t0), 0>));
  TTS_EQUAL(t0.size(), 0ULL);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t1), 1>));
  TTS_EQUAL(t1.size(), 1ULL);
  TTS_EQUAL(get<0>(t1), 1);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t2), 2>));
  TTS_EQUAL(t2.size(), 2ULL);
  TTS_EQUAL(get<0>(t2), 1.f);
  TTS_EQUAL(get<1>(t2), 2);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t3), 3>));
  TTS_EQUAL(t3.size(), 3ULL);
  TTS_EQUAL(get<0>(t3), 1.);
  TTS_EQUAL(get<1>(t3), 2.f);
  TTS_EQUAL(get<2>(t3), 3);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t4), 4>));
  TTS_EQUAL(t4.size(), 4ULL);
  TTS_EQUAL(get<0>(t4), '1');
  TTS_EQUAL(get<1>(t4), 2.);
  TTS_EQUAL(get<2>(t4), 3.f);
  TTS_EQUAL(get<3>(t4), 4);
};

TTS_CASE("Check construction of kumi::tuple as a constexpr aggregate")
{
  constexpr kumi::tuple t0 = {};
  constexpr kumi::tuple t1 = {1};
  constexpr kumi::tuple t2 = {1.f, 2};
  constexpr kumi::tuple t3 = {1., 2.f, 3};
  constexpr kumi::tuple t4 = {'1', 2., 3.f, 4};

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t0), 0>));
  TTS_CONSTEXPR_EQUAL(t0.size(), 0ULL);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t1), 1>));
  TTS_CONSTEXPR_EQUAL(t1.size(), 1ULL);
  TTS_CONSTEXPR_EQUAL(get<0>(t1), 1);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t2), 2>));
  TTS_CONSTEXPR_EQUAL(t2.size(), 2ULL);
  TTS_CONSTEXPR_EQUAL(get<0>(t2), 1.f);
  TTS_CONSTEXPR_EQUAL(get<1>(t2), 2);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t3), 3>));
  TTS_CONSTEXPR_EQUAL(t3.size(), 3ULL);
  TTS_CONSTEXPR_EQUAL(get<0>(t3), 1.);
  TTS_CONSTEXPR_EQUAL(get<1>(t3), 2.f);
  TTS_CONSTEXPR_EQUAL(get<2>(t3), 3);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t4), 4>));
  TTS_CONSTEXPR_EQUAL(t4.size(), 4ULL);
  TTS_CONSTEXPR_EQUAL(get<0>(t4), '1');
  TTS_CONSTEXPR_EQUAL(get<1>(t4), 2.);
  TTS_CONSTEXPR_EQUAL(get<2>(t4), 3.f);
  TTS_CONSTEXPR_EQUAL(get<3>(t4), 4);
};
