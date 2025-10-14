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
#include <type_traits>

TTS_CASE("Check std::is_empty behavior for tuple & record")
{
  using namespace kumi;

  TTS_CONSTEXPR_EXPECT_NOT(( std::is_empty_v<tuple<int>>    ));
  TTS_CONSTEXPR_EXPECT((     std::is_empty_v<kumi::tuple<>> ));

  TTS_CONSTEXPR_EXPECT_NOT(( std::is_empty_v<record<field_capture<"toto", int>>> ));
  TTS_CONSTEXPR_EXPECT(( std::is_empty_v<kumi::record<>> ));
};

TTS_CASE("Check std::is_aggregate behavior for tuple & record")
{
  using namespace kumi;

  TTS_CONSTEXPR_EXPECT(( std::is_aggregate_v<tuple<int>>    ));
  TTS_CONSTEXPR_EXPECT(( std::is_aggregate_v<kumi::tuple<>> ));

  TTS_CONSTEXPR_EXPECT(( std::is_aggregate_v<record<field_capture<"toto", int>>> ));
  TTS_CONSTEXPR_EXPECT(( std::is_aggregate_v<record<>> ));
};
