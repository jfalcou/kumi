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
#include "test.hpp"

template<typename T> struct is_int : std::is_same<std::remove_cvref_t<T>, int>
{
};

TTS_CASE("Check operator[] partial application on map and sum")
{
  auto t = kumi::tuple{1, 2, 3};
  auto twice = [](auto v) { return v * 2; };

  TTS_EQUAL(kumi::map[twice](t), (kumi::tuple{2, 4, 6}));
  TTS_EQUAL(kumi::sum[10](t), 16);
};

TTS_CASE("Check pipe behavior")
{
  auto t = kumi::tuple{1, 2.5, 3, 'x'};
  auto twice = [](auto v) { return v * 2; };

  auto p = kumi::filter<is_int> | kumi::map[twice] | kumi::sum[0];

  TTS_EQUAL(p(t), 8);
  TTS_EQUAL(p(kumi::tuple{10, 20, 30}), 120);
  TTS_EQUAL((kumi::reverse | p)(t), 8);
  auto acc = [](auto a, auto v) { return a + v; };
  TTS_EQUAL((kumi::filter<is_int> | kumi::bind_back(kumi::bind_front(kumi::fold_left, acc), 100))(t), 104);
};

TTS_CASE("Check pipe constexpr behavior")
{
  constexpr auto t = kumi::tuple{1, 2.5, 3, 'x'};
  constexpr auto twice = [](auto v) { return v * 2; };
  constexpr auto p = kumi::filter<is_int> | kumi::map[twice] | kumi::sum[0];

  TTS_CONSTEXPR_EQUAL(p(t), 8);
  TTS_CONSTEXPR_EQUAL(p(kumi::tuple{10, 20, 30}), 120);
  TTS_CONSTEXPR_EQUAL((kumi::reverse | p)(t), 8);
};

TTS_CASE("Check pipe storage")
{
  constexpr auto twice = [](auto v) { return v * 2; };
  constexpr auto p = kumi::filter<is_int> | kumi::map[twice] | kumi::sum[0];
  constexpr auto q = kumi::reverse | kumi::filter<is_int>;

  TTS_CONSTEXPR_EQUAL(sizeof(p), sizeof(int));
  TTS_CONSTEXPR_EQUAL(sizeof(q), 1ULL);
  TTS_EXPECT_NOT(kumi::concepts::product_type<decltype(p)>);
  TTS_EXPECT(kumi::concepts::stage<decltype(p)>);
  TTS_EXPECT(kumi::concepts::stage<decltype(kumi::map)>);
  TTS_EXPECT_NOT(kumi::concepts::stage<kumi::tuple<int>>);
};
