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

TTS_CASE("Check tuple_element of kumi::tuple")
{
  auto aggregate = kumi::tuple{'1', 2., 3.f};
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(aggregate)>), char);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(aggregate)>), double);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(aggregate)>), float);
};

TTS_CASE("Check construction of kumi::tuple as an aggregate")
{
  auto t0 = kumi::tuple{};
  auto t1 = kumi::tuple{1};
  auto t2 = kumi::tuple{1.f, 2};
  auto t3 = kumi::tuple{1., 2.f, 3};
  auto t4 = kumi::tuple{'1', 2., 3.f, 4};

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
  constexpr auto t0 = kumi::tuple{};
  constexpr auto t1 = kumi::tuple{1};
  constexpr auto t2 = kumi::tuple{1.f, 2};
  constexpr auto t3 = kumi::tuple{1., 2.f, 3};
  constexpr auto t4 = kumi::tuple{'1', 2., 3.f, 4};

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
