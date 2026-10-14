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
#include <array>
#include "test.hpp"

TTS_CASE("Check is_homogeneous for kumi::array")
{
  TTS_CONSTEXPR_EXPECT((kumi::concepts::homogeneous_product_type<kumi::array<>>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::homogeneous_product_type<kumi::array<void, 0>>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::homogeneous_product_type<kumi::array<int, 1>>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::homogeneous_product_type<kumi::array<int, 3>>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::homogeneous_product_type<kumi::array<int, 7>>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::homogeneous_product_type<kumi::array<kumi::array<int, 2>, 3>>));

  // An array is homogeneous even for an empty array since t^0 collapses to the unit type.
  TTS_CONSTEXPR_EXPECT((kumi::is_homogeneous_v<kumi::array<int, 0>>));
  TTS_CONSTEXPR_EXPECT((kumi::is_homogeneous_v<kumi::array<>>));
};

TTS_CASE("Check is_homogeneous for kumi::concepts::product_type adapted types")
{
  TTS_CONSTEXPR_EXPECT((kumi::concepts::homogeneous_product_type<std::array<int, 7>>));

  // A heterogeneous tuple is not homogeneous, so it cannot be an array.
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::homogeneous_product_type<kumi::tuple<int, float>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::is_homogeneous_v<kumi::tuple<int, float>>));
};
