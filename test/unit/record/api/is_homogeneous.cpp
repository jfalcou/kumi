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
#include <array>
#include "test.hpp"

TTS_CASE("Check is_homogeneous for kumi::record")
{
  TTS_CONSTEXPR_EXPECT_NOT(
    (kumi::concepts::homogeneous_product_type<
      kumi::record<kumi::field_capture<"a", int>, kumi::field_capture<"b", int>, kumi::field_capture<"c", int>>>));

  TTS_CONSTEXPR_EXPECT_NOT(
    (kumi::concepts::homogeneous_product_type<
      kumi::record<kumi::field_capture<"a", int>, kumi::field_capture<"b", float>, kumi::field_capture<"c", char>>>));
};

TTS_CASE("Check is_homogeneous for kumi::record derived types")
{
  TTS_CONSTEXPR_EXPECT_NOT((kumi::is_homogeneous_v<trivial_record_type<int, true>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::homogeneous_product_type<trivial_record_type<int, true>>));

  TTS_CONSTEXPR_EXPECT_NOT((kumi::is_homogeneous_v<trivial_record_type<int, false>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::homogeneous_product_type<trivial_record_type<int, false>>));
};

TTS_CASE("Check is_homogeneous for kumi::concepts::record_type adapted types")
{
  TTS_CONSTEXPR_EXPECT_NOT((kumi::concepts::homogeneous_product_type<record_box>));
};
