//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/tuple.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include <concepts>
#include <compare>

struct no_cmp
{
};

struct cmp
{
  constexpr auto operator<=>(cmp const&) const = default;
};

struct strange
{
  constexpr float operator==(strange const&) const { return -1.f; };
};

struct other_cmp
{
  constexpr float operator==(other_cmp const&) const { return true; };

  constexpr float operator==(cmp const&) const { return false; };
};

TTS_CASE("Check concepts::equality_comparable for tuple")
{
  using namespace kumi;

  TTS_CONSTEXPR_EXPECT_NOT((concepts::equality_comparable<tuple<no_cmp>, tuple<no_cmp>>));
  TTS_CONSTEXPR_EXPECT_NOT((concepts::equality_comparable<tuple<cmp>, tuple<no_cmp>>));
  TTS_CONSTEXPR_EXPECT_NOT((concepts::equality_comparable<tuple<cmp>, tuple<cmp, cmp>>));
  TTS_CONSTEXPR_EXPECT_NOT((concepts::equality_comparable<tuple<cmp, cmp>, tuple<cmp>>));

  TTS_CONSTEXPR_EXPECT((concepts::equality_comparable<tuple<cmp>, tuple<cmp>>));
  TTS_CONSTEXPR_EXPECT((concepts::equality_comparable<tuple<cmp, tuple<cmp>>, tuple<cmp, tuple<cmp>>>));

  TTS_CONSTEXPR_EXPECT((concepts::equality_comparable<tuple<strange>, tuple<strange>>));
  TTS_CONSTEXPR_EXPECT((concepts::equality_comparable<tuple<strange, tuple<strange>>, tuple<strange, tuple<strange>>>));

  TTS_CONSTEXPR_EXPECT((concepts::equality_comparable<tuple<other_cmp, other_cmp>, tuple<other_cmp, cmp>>));
};

TTS_CASE("Check product_type for tuple")
{
  TTS_CONSTEXPR_EXPECT_NOT(kumi::concepts::product_type<int>);
  TTS_CONSTEXPR_EXPECT(kumi::concepts::product_type<kumi::tuple<strange>>);
  TTS_CONSTEXPR_EXPECT((kumi::concepts::product_type<kumi::tuple<strange, kumi::tuple<cmp>>>));
};

TTS_CASE("Check sized_product_type for tuple")
{
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type<int, 0>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<kumi::tuple<>, 0>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type<kumi::tuple<strange>, 0>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type<int, 1>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<kumi::tuple<strange>, 1>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type<kumi::tuple<strange, kumi::tuple<cmp>>, 1>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type<int, 2>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type<kumi::tuple<strange>, 2>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<kumi::tuple<strange, kumi::tuple<cmp>>, 2>));
};

TTS_CASE("Check sized_product_type_or_more for tuple")
{
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<int, 0>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::tuple<>, 0>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange>, 0>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange, int, cmp>, 0>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<int, 1>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange>, 1>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange, kumi::tuple<cmp>>, 1>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange, int, cmp>, 1>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<int, 2>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange>, 2>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange, kumi::tuple<cmp>>, 2>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange, int, cmp>, 2>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<int, 3>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange>, 3>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange, kumi::tuple<cmp>>, 3>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange, int, cmp>, 3>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<int, 4>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange>, 4>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange, kumi::tuple<cmp>>, 4>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<kumi::tuple<strange, int, cmp>, 4>));
};

TTS_CASE("Check non_empty_product_type for tuple")
{
  TTS_CONSTEXPR_EXPECT_NOT(kumi::concepts::non_empty_product_type<int>);
  TTS_CONSTEXPR_EXPECT_NOT(kumi::concepts::non_empty_product_type<kumi::tuple<>>);
  TTS_CONSTEXPR_EXPECT(kumi::concepts::non_empty_product_type<kumi::tuple<strange>>);
  TTS_CONSTEXPR_EXPECT((kumi::concepts::non_empty_product_type<kumi::tuple<strange, kumi::tuple<cmp>>>));
};

TTS_CASE("Check empty_product_type for tuple")
{
  TTS_CONSTEXPR_EXPECT_NOT(kumi::concepts::empty_product_type<int>);
  TTS_CONSTEXPR_EXPECT(kumi::concepts::empty_product_type<kumi::tuple<>>);
  TTS_CONSTEXPR_EXPECT_NOT(kumi::concepts::empty_product_type<kumi::tuple<strange>>);
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::empty_product_type<kumi::tuple<strange, kumi::tuple<cmp>>>));
};
