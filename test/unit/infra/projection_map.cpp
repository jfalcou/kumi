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

TTS_CASE("Check kumi::concepts::projection bejavior")
{
  using namespace kumi::literals;

  TTS_EXPECT((kumi::concepts::projection<std::integral_constant<std::size_t, 0>>));
  TTS_EXPECT((kumi::concepts::projection<kumi::index_t<0>>));

  TTS_EXPECT((kumi::concepts::projection<decltype(kumi::projection_map{0_c, 1_c})>));
  TTS_EXPECT((kumi::concepts::projection<decltype(kumi::projection_map{0_c, kumi::projection_map{0_c, 1_c}})>));
  TTS_EXPECT((kumi::concepts::projection<decltype(kumi::indexes(0_c, 1_c))>));
  TTS_EXPECT((kumi::concepts::projection<decltype(kumi::make_indexes<1, 2, 3, 4, 5>())>));

  TTS_EXPECT((kumi::concepts::projection<decltype(kumi::identifiers("a"_id, "b"_id))>));
  TTS_EXPECT((kumi::concepts::projection<decltype(kumi::projection_map{"a"_id, "b"_id})>));
};
