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
  constexpr float operator==(strange const&) const { return -1.f; }
};

struct other_cmp
{
  constexpr float operator==(other_cmp const&) const { return true; }

  constexpr float operator==(cmp const&) const { return false; }
};

TTS_CASE("Check concepts::equality_comparable for array")
{
  using namespace kumi;

  TTS_CONSTEXPR_EXPECT_NOT((concepts::equality_comparable<array<no_cmp, 1>, array<no_cmp, 1>>));
  TTS_CONSTEXPR_EXPECT_NOT((concepts::equality_comparable<array<cmp, 1>, array<no_cmp, 1>>));
  TTS_CONSTEXPR_EXPECT_NOT((concepts::equality_comparable<array<cmp, 1>, array<cmp, 2>>));
  TTS_CONSTEXPR_EXPECT_NOT((concepts::equality_comparable<array<cmp, 2>, array<cmp, 1>>));

  TTS_CONSTEXPR_EXPECT((concepts::equality_comparable<array<cmp, 1>, array<cmp, 1>>));
  TTS_CONSTEXPR_EXPECT((concepts::equality_comparable<array<array<cmp, 1>, 2>, array<array<cmp, 1>, 2>>));

  TTS_CONSTEXPR_EXPECT((concepts::equality_comparable<array<strange, 1>, array<strange, 1>>));
  TTS_CONSTEXPR_EXPECT((concepts::equality_comparable<array<array<strange, 1>, 2>, array<array<strange, 1>, 2>>));

  TTS_CONSTEXPR_EXPECT((concepts::equality_comparable<array<other_cmp, 2>, array<other_cmp, 2>>));
  TTS_CONSTEXPR_EXPECT((concepts::equality_comparable<array<other_cmp, 1>, array<cmp, 1>>));
};

TTS_CASE("Check product_type for array")
{
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::product_type<int>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::product_type<kumi::array<strange, 1>>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::product_type<kumi::array<kumi::array<cmp, 1>, 2>>));
};

TTS_CASE("Check sized_product_type for array")
{
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type<int, 0>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<kumi::array<>, 0>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type<kumi::array<strange, 1>, 0>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type<int, 1>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<kumi::array<strange, 1>, 1>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type<kumi::array<kumi::array<cmp, 1>, 2>, 1>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type<int, 2>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type<kumi::array<strange, 1>, 2>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type<kumi::array<kumi::array<cmp, 1>, 2>, 2>));
};

TTS_CASE("Check sized_product_type_or_more for array")
{
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<int, 0>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::array<>, 0>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::array<strange, 1>, 0>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::array<int, 3>, 0>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<int, 1>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::array<strange, 1>, 1>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::array<kumi::array<cmp, 1>, 2>, 1>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::array<int, 3>, 1>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<int, 2>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<kumi::array<strange, 1>, 2>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::array<kumi::array<cmp, 1>, 2>, 2>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::array<int, 3>, 2>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<int, 3>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<kumi::array<strange, 1>, 3>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<kumi::array<kumi::array<cmp, 1>, 2>, 3>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::sized_product_type_or_more<kumi::array<int, 3>, 3>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<int, 4>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<kumi::array<strange, 1>, 4>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<kumi::array<kumi::array<cmp, 1>, 2>, 4>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::sized_product_type_or_more<kumi::array<int, 3>, 4>));
};

TTS_CASE("Check non_empty_product_type for array")
{
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::non_empty_product_type<int>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::non_empty_product_type<kumi::array<>>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::non_empty_product_type<kumi::array<strange, 1>>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::non_empty_product_type<kumi::array<kumi::array<cmp, 1>, 2>>));
};

TTS_CASE("Check empty_product_type for array")
{
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::empty_product_type<int>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::empty_product_type<kumi::array<>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::empty_product_type<kumi::array<strange, 1>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::empty_product_type<kumi::array<kumi::array<cmp, 1>, 2>>));
};
