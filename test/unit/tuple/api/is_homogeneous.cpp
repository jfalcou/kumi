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
#include <array>
#include "test.hpp"

TTS_CASE("Check is_homogeneous for kumi::tuple")
{
  TTS_CONSTEXPR_EXPECT_NOT(kumi::concepts::homogeneous_product_type<kumi::tuple<>>);
  TTS_CONSTEXPR_EXPECT(kumi::concepts::homogeneous_product_type<kumi::tuple<int>>);
  TTS_CONSTEXPR_EXPECT(kumi::concepts::homogeneous_product_type<kumi::tuple<int>>);
  TTS_CONSTEXPR_EXPECT((kumi::concepts::homogeneous_product_type<kumi::tuple<int, int>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::homogeneous_product_type<kumi::tuple<int, float>>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::homogeneous_product_type<kumi::tuple<int, int, int>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::homogeneous_product_type<kumi::tuple<int, float, int>>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::homogeneous_product_type<kumi::tuple<int, int, int, int>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::homogeneous_product_type<kumi::tuple<int, float, int, int>>));
};

TTS_CASE("Check is_homogeneous for kumi::tuple derived types")
{
  TTS_CONSTEXPR_EXPECT((kumi::is_homogeneous_v<trivial_product_type<int, true>>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::homogeneous_product_type<trivial_product_type<int, true>>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::is_homogeneous_v<trivial_product_type<int, false>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::homogeneous_product_type<trivial_product_type<int, false>>));
};

TTS_CASE("Check is_homogeneous for kumi::concepts::product_type adapted types")
{
  TTS_CONSTEXPR_EXPECT((kumi::concepts::homogeneous_product_type<std::array<int, 7>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::homogeneous_product_type<tuple_box>));
};
