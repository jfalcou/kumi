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

  using map1 = decltype(kumi::projection_map{0_c, 1_c});
  using map2 = decltype(kumi::projection_map{0_c, kumi::projection_map{0_c, 1_c}});
  using map3 = decltype(kumi::indexes(0_c, 1_c));
  using map4 = decltype(kumi::make_indexes<1, 2, 3, 4, 5>());

  // using map5 = decltype(kumi::identifiers("a"_id, "b"_id));
  // using map6 = decltype(kumi::projection_map{"a"_id, "b"_id});

  TTS_EXPECT((kumi::concepts::projection<std::integral_constant<std::size_t, 0>>));
  TTS_EXPECT((kumi::concepts::projection<kumi::index_t<0>>));

  TTS_EXPECT((kumi::concepts::projection<map1>));
  TTS_EXPECT((kumi::concepts::projection<map2>));
  TTS_EXPECT((kumi::concepts::projection<map3>));
  TTS_EXPECT((kumi::concepts::projection<map4>));

  // TTS_EXPECT((kumi::concepts::projection<map5>));
  // TTS_EXPECT((kumi::concepts::projection<map6>));
};
