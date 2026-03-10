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

  auto map1 = kumi::projection_map{0_c, 1_c};
  auto map2 = kumi::projection_map{0_c, kumi::projection_map{0_c, 1_c}};
  auto map3 = kumi::indexes(0_c, 1_c);
  auto map4 = kumi::make_indexes<1, 2, 3, 4, 5>();

  auto map5 = kumi::identifiers("a"_id, "b"_id);
  auto map6 = kumi::projection_map{"a"_id, "b"_id};

  TTS_EXPECT((kumi::concepts::projection<std::integral_constant<std::size_t, 0>>));
  TTS_EXPECT((kumi::concepts::projection<kumi::index_t<0>>));

  TTS_EXPECT((kumi::concepts::projection<decltype(map1)>));
  TTS_EXPECT((kumi::concepts::projection<decltype(map2)>));
  TTS_EXPECT((kumi::concepts::projection<decltype(map3)>));
  TTS_EXPECT((kumi::concepts::projection<decltype(map4)>));

  TTS_EXPECT((kumi::concepts::projection<decltype(map5)>));
  TTS_EXPECT((kumi::concepts::projection<decltype(map6)>));
};
