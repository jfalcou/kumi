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

TTS_CASE("Check tuple_element of kumi::tuple")
{
  char c{};
  char const cc{};
  double d{};
  double const cd{};
  float f{};
  float const cf{};

  auto tied = kumi::tie(c, d, f);
  auto const_tied = kumi::tie(cc, cd, cf);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(tied)>), char&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(tied)>), double&);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(tied)>), float&);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(const_tied)>), char const&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(const_tied)>), double const&);
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(const_tied)>), float const&);
};

TTS_CASE("Check construction of kumi::tuple via tie")
{
  auto i = 1;
  auto f = 2.f;
  auto d = 3.;
  auto c = '4';

  auto t1 = kumi::tie(i);
  auto t2 = kumi::tie(i, f);
  auto t3 = kumi::tie(i, f, d);
  auto t4 = kumi::tie(i, f, d, c);

  auto& [s1_0] = t1;
  auto& t1_0 = s1_0;
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t1), 1>));
  TTS_EQUAL(t1.size(), 1ULL);
  TTS_EQUAL(&t1_0, &i);

  auto& [s2_0, s2_1] = t2;
  auto& t2_0 = s2_0;
  auto& t2_1 = s2_1;
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t2), 2>));
  TTS_EQUAL(t2.size(), 2ULL);
  TTS_EQUAL(&t2_0, &i);
  TTS_EQUAL(&t2_1, &f);

  auto& [s3_0, s3_1, s3_2] = t3;
  auto& t3_0 = s3_0;
  auto& t3_1 = s3_1;
  auto& t3_2 = s3_2;
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t3), 3>));
  TTS_EQUAL(t3.size(), 3ULL);
  TTS_EQUAL(&t3_0, &i);
  TTS_EQUAL(&t3_1, &f);
  TTS_EQUAL(&t3_2, &d);

  auto& [s4_0, s4_1, s4_2, s4_3] = t4;
  auto& t4_0 = s4_0;
  auto& t4_1 = s4_1;
  auto& t4_2 = s4_2;
  auto& t4_3 = s4_3;
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t4), 4>));
  TTS_EQUAL(t4.size(), 4ULL);
  TTS_EQUAL(&t4_0, &i);
  TTS_EQUAL(&t4_1, &f);
  TTS_EQUAL(&t4_2, &d);
  TTS_EQUAL(&t4_3, &c);
};
