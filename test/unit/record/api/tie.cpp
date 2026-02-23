//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check tuple_element of kumi::record")
{
  using namespace kumi::literals;
  char c{};
  char const cc{};
  double d{};
  double const cd{};
  float f{};
  float const cf{};

  auto tied = kumi::tie<"c"_id, "d"_id, "f"_id>(c, d, f);
  auto const_tied = kumi::tie<"c"_id, "d"_id, "f"_id>(cc, cd, cf);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(tied)>), (kumi::field<kumi::name<"c">, char&>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(tied)>), (kumi::field<kumi::name<"d">, double&>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(tied)>), (kumi::field<kumi::name<"f">, float&>));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(const_tied)>), (kumi::field<kumi::name<"c">, char const&>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(const_tied)>), (kumi::field<kumi::name<"d">, double const&>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(const_tied)>), (kumi::field<kumi::name<"f">, float const&>));
};

TTS_CASE("Check construction of kumi::record via tie")
{
  using namespace kumi::literals;

  auto i = 1;
  auto f = 2.f;
  auto d = 3.;
  auto c = '4';

  auto t1 = kumi::tie<"i"_id>(i);
  auto t2 = kumi::tie<"i"_id, "f"_id>(i, f);
  auto t3 = kumi::tie<"i"_id, "f"_id, "d"_id>(i, f, d);
  auto t4 = kumi::tie<"i"_id, "f"_id, "d"_id, "c"_id>(i, f, d, c);

  auto& [s1_0] = t1;
  auto& t1_0 = kumi::field_value_of(s1_0);
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t1), 1>));
  TTS_EQUAL(t1.size(), 1ULL);
  TTS_EQUAL(&t1_0, &i);

  auto& [s2_0, s2_1] = t2;
  auto& t2_0 = kumi::field_value_of(s2_0);
  auto& t2_1 = kumi::field_value_of(s2_1);
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t2), 2>));
  TTS_EQUAL(t2.size(), 2ULL);
  TTS_EQUAL(&t2_0, &i);
  TTS_EQUAL(&t2_1, &f);

  auto& [s3_0, s3_1, s3_2] = t3;
  auto& t3_0 = kumi::field_value_of(s3_0);
  auto& t3_1 = kumi::field_value_of(s3_1);
  auto& t3_2 = kumi::field_value_of(s3_2);
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t3), 3>));
  TTS_EQUAL(t3.size(), 3ULL);
  TTS_EQUAL(&t3_0, &i);
  TTS_EQUAL(&t3_1, &f);
  TTS_EQUAL(&t3_2, &d);

  auto& [s4_0, s4_1, s4_2, s4_3] = t4;
  auto& t4_0 = kumi::field_value_of(s4_0);
  auto& t4_1 = kumi::field_value_of(s4_1);
  auto& t4_2 = kumi::field_value_of(s4_2);
  auto& t4_3 = kumi::field_value_of(s4_3);
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t4), 4>));
  TTS_EQUAL(t4.size(), 4ULL);
  TTS_EQUAL(&t4_0, &i);
  TTS_EQUAL(&t4_1, &f);
  TTS_EQUAL(&t4_2, &d);
  TTS_EQUAL(&t4_3, &c);
};
