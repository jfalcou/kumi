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
#include <array>
#include "test.hpp"

TTS_CASE("Check is_homogeneous for kumi::tuple")
{
  TTS_CONSTEXPR_EXPECT_NOT(kumi::tuple<>::is_homogeneous);
  TTS_CONSTEXPR_EXPECT(kumi::tuple<int>::is_homogeneous);
  TTS_CONSTEXPR_EXPECT((kumi::tuple<int, int>::is_homogeneous));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::tuple<int, float>::is_homogeneous));
  TTS_CONSTEXPR_EXPECT((kumi::tuple<int, int, int>::is_homogeneous));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::tuple<int, float, int>::is_homogeneous));
  TTS_CONSTEXPR_EXPECT((kumi::tuple<int, int, int, int>::is_homogeneous));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::tuple<int, float, int, int>::is_homogeneous));

  TTS_CONSTEXPR_EXPECT_NOT(kumi::homogeneous_product_type<kumi::tuple<>>);
  TTS_CONSTEXPR_EXPECT(kumi::homogeneous_product_type<kumi::tuple<int>>);
  TTS_CONSTEXPR_EXPECT(kumi::homogeneous_product_type<kumi::tuple<int>>);
  TTS_CONSTEXPR_EXPECT((kumi::homogeneous_product_type<kumi::tuple<int, int>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::homogeneous_product_type<kumi::tuple<int, float>>));
  TTS_CONSTEXPR_EXPECT((kumi::homogeneous_product_type<kumi::tuple<int, int, int>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::homogeneous_product_type<kumi::tuple<int, float, int>>));
  TTS_CONSTEXPR_EXPECT((kumi::homogeneous_product_type<kumi::tuple<int, int, int, int>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::homogeneous_product_type<kumi::tuple<int, float, int, int>>));

  TTS_CONSTEXPR_EXPECT_NOT(
    (kumi::homogeneous_product_type<
      kumi::record<kumi::field_capture<"a", int>, kumi::field_capture<"b", int>, kumi::field_capture<"c", int>>>));

  TTS_CONSTEXPR_EXPECT_NOT(
    (kumi::homogeneous_product_type<
      kumi::record<kumi::field_capture<"a", int>, kumi::field_capture<"b", float>, kumi::field_capture<"c", char>>>));
};

TTS_CASE("Check is_homogeneous for kumi::tuple derived types")
{
  TTS_CONSTEXPR_EXPECT((trivial_product_type<int, true>::is_homogeneous));
  TTS_CONSTEXPR_EXPECT((kumi::homogeneous_product_type<trivial_product_type<int, true>>));

  TTS_CONSTEXPR_EXPECT_NOT((trivial_product_type<int, false>::is_homogeneous));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::homogeneous_product_type<trivial_product_type<int, false>>));
};

TTS_CASE("Check is_homogeneous for kumi::product_type adapted types")
{
  TTS_CONSTEXPR_EXPECT((kumi::homogeneous_product_type<std::array<int, 7>>));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::homogeneous_product_type<tuple_box>));
};

TTS_CASE("Check is_homogeneous for kumi::record derived types")
{
  TTS_CONSTEXPR_EXPECT_NOT((trivial_record_type<int, true>::is_homogeneous));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::homogeneous_product_type<trivial_record_type<int, true>>));

  TTS_CONSTEXPR_EXPECT_NOT((trivial_record_type<int, false>::is_homogeneous));
  TTS_CONSTEXPR_EXPECT_NOT((kumi::homogeneous_product_type<trivial_record_type<int, false>>));
};

TTS_CASE("Check is_homogeneous for kumi::record_type adapted types")
{
  TTS_CONSTEXPR_EXPECT_NOT((kumi::homogeneous_product_type<record_box>));
};
