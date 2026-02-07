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

TTS_CASE("Check tuple_element of kumi::record")
{
  using namespace kumi::literals;

  float const f{};
  double d;
  std::reference_wrapper<float const> rf = f;
  std::reference_wrapper<double> rd = d;

  auto made = kumi::make_record("a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = rf, "e"_n = rd);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(made)>), (kumi::field<kumi::name<"a">, char>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(made)>), (kumi::field<kumi::name<"b">, double>));
  TTS_TYPE_IS((std::tuple_element_t<2, decltype(made)>), (kumi::field<kumi::name<"c">, float>));
  TTS_TYPE_IS((std::tuple_element_t<3, decltype(made)>), (kumi::field<kumi::name<"d">, float const&>));
  TTS_TYPE_IS((std::tuple_element_t<4, decltype(made)>), (kumi::field<kumi::name<"e">, double&>));
};

TTS_CASE("Check construction of kumi::record via make_record")
{
  using namespace kumi::literals;

  auto t0 = kumi::make_record();
  auto t1 = kumi::make_record("a"_n = 1);
  auto t2 = kumi::make_record("a"_n = 1.f, "b"_n = 2);
  auto t3 = kumi::make_record("a"_n = 1., "b"_n = 2.f, "c"_n = 3);
  auto t4 = kumi::make_record("a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = 4);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t0), 0>));
  TTS_EQUAL(t0.size(), 0ULL);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t1), 1>));
  TTS_EQUAL(t1.size(), 1ULL);
  TTS_EQUAL(get<"a"_n>(t1), 1);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t2), 2>));
  TTS_EQUAL(t2.size(), 2ULL);
  TTS_EQUAL(get<"a"_n>(t2), 1.f);
  TTS_EQUAL(get<"b"_n>(t2), 2);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t3), 3>));
  TTS_EQUAL(t3.size(), 3ULL);
  TTS_EQUAL(get<"a"_n>(t3), 1.);
  TTS_EQUAL(get<"b"_n>(t3), 2.f);
  TTS_EQUAL(get<"c"_n>(t3), 3);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t4), 4>));
  TTS_EQUAL(t4.size(), 4ULL);
  TTS_EQUAL(get<"a"_n>(t4), '1');
  TTS_EQUAL(get<"b"_n>(t4), 2.);
  TTS_EQUAL(get<"c"_n>(t4), 3.f);
  TTS_EQUAL(get<"d"_n>(t4), 4);
};

TTS_CASE("Check construction of kumi::record via constexpr make_record")
{
  using namespace kumi::literals;

  constexpr auto t0 = kumi::make_record();
  constexpr auto t1 = kumi::make_record("a"_n = 1);
  constexpr auto t2 = kumi::make_record("a"_n = 1.f, "b"_n = 2);
  constexpr auto t3 = kumi::make_record("a"_n = 1., "b"_n = 2.f, "c"_n = 3);
  constexpr auto t4 = kumi::make_record("a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = 4);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t0), 0>));
  TTS_CONSTEXPR_EQUAL(t0.size(), 0ULL);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t1), 1>));
  TTS_CONSTEXPR_EQUAL(t1.size(), 1ULL);
  TTS_CONSTEXPR_EQUAL(get<"a"_n>(t1), 1);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t2), 2>));
  TTS_CONSTEXPR_EQUAL(t2.size(), 2ULL);
  TTS_CONSTEXPR_EQUAL(get<"a"_n>(t2), 1.f);
  TTS_CONSTEXPR_EQUAL(get<"b"_n>(t2), 2);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t3), 3>));
  TTS_CONSTEXPR_EQUAL(t3.size(), 3ULL);
  TTS_CONSTEXPR_EQUAL(get<"a"_n>(t3), 1.);
  TTS_CONSTEXPR_EQUAL(get<"b"_n>(t3), 2.f);
  TTS_CONSTEXPR_EQUAL(get<"c"_n>(t3), 3);

  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<decltype(t4), 4>));
  TTS_CONSTEXPR_EQUAL(t4.size(), 4ULL);
  TTS_CONSTEXPR_EQUAL(get<"a"_n>(t4), '1');
  TTS_CONSTEXPR_EQUAL(get<"b"_n>(t4), 2.);
  TTS_CONSTEXPR_EQUAL(get<"c"_n>(t4), 3.f);
  TTS_CONSTEXPR_EQUAL(get<"d"_n>(t4), 4);
};
