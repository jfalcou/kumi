//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>

using namespace kumi::literals;

TTS_CASE("Check record_element of kumi::record")
{
  auto aggregate = kumi::record{"x"_f = '1', "y"_f = 2., "z"_f = 3.f};
  TTS_TYPE_IS((std::tuple_element_t<0, decltype(aggregate)>), (kumi::field_capture<"x", char>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(aggregate)>), (kumi::field_capture<"y", double>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(aggregate)>), (kumi::field_capture<"z", float>));
};

TTS_CASE("Check construction of kumi::record as an aggregate")
{
  auto t0 = kumi::record{};
  auto t1 = kumi::record{"x"_f = 1};
  auto t2 = kumi::record{"x"_f = 1.f, "y"_f = 2};
  auto t3 = kumi::record{"x"_f = 1., "y"_f = 2.f, "z"_f = 3};
  auto t4 = kumi::record{"x"_f = '1', "y"_f = 2., "z"_f = 3.f, "t"_f = 4};

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t0), 0>));
  TTS_EQUAL(t0.size(), 0ULL);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t1), 1>));
  TTS_EQUAL(t1.size(), 1ULL);
  TTS_EQUAL(get<0>(t1).value, 1);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t2), 2>));
  TTS_EQUAL(t2.size(), 2ULL);
  TTS_EQUAL(get<0>(t2).value, 1.f);
  TTS_EQUAL(get<1>(t2).value, 2);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t3), 3>));
  TTS_EQUAL(t3.size(), 3ULL);
  TTS_EQUAL(get<0>(t3).value, 1.);
  TTS_EQUAL(get<1>(t3).value, 2.f);
  TTS_EQUAL(get<2>(t3).value, 3);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t4), 4>));
  TTS_EQUAL(t4.size(), 4ULL);
  TTS_EQUAL(get<0>(t4).value, '1');
  TTS_EQUAL(get<1>(t4).value, 2.);
  TTS_EQUAL(get<2>(t4).value, 3.f);
  TTS_EQUAL(get<3>(t4).value, 4);
};

TTS_CASE("Check construction of kumi::record as a constexpr aggregate")
{
  constexpr auto t0 = kumi::record{};
  constexpr auto t1 = kumi::record{"x"_f = 1};
  constexpr auto t2 = kumi::record{"x"_f = 1.f, "y"_f = 2};
  constexpr auto t3 = kumi::record{"x"_f = 1., "y"_f = 2.f, "z"_f = 3};
  constexpr auto t4 = kumi::record{"x"_f = '1', "y"_f = 2., "z"_f = 3.f, "t"_f = 4};

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t0), 0>));
  TTS_CONSTEXPR_EQUAL(t0.size(), 0ULL);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t1), 1>));
  TTS_CONSTEXPR_EQUAL(t1.size(), 1ULL);
  TTS_CONSTEXPR_EQUAL(get<0>(t1).value, 1);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t2), 2>));
  TTS_CONSTEXPR_EQUAL(t2.size(), 2ULL);
  TTS_CONSTEXPR_EQUAL(get<0>(t2).value, 1.f);
  TTS_CONSTEXPR_EQUAL(get<1>(t2).value, 2);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t3), 3>));
  TTS_CONSTEXPR_EQUAL(t3.size(), 3ULL);
  TTS_CONSTEXPR_EQUAL(get<0>(t3).value, 1.);
  TTS_CONSTEXPR_EQUAL(get<1>(t3).value, 2.f);
  TTS_CONSTEXPR_EQUAL(get<2>(t3).value, 3);

  TTS_CONSTEXPR_EXPECT((kumi::sized_product_type<decltype(t4), 4>));
  TTS_CONSTEXPR_EQUAL(t4.size(), 4ULL);
  TTS_CONSTEXPR_EQUAL(get<0>(t4).value, '1');
  TTS_CONSTEXPR_EQUAL(get<1>(t4).value, 2.);
  TTS_CONSTEXPR_EQUAL(get<2>(t4).value, 3.f);
  TTS_CONSTEXPR_EQUAL(get<3>(t4).value, 4);
};
