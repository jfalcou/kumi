//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <tts/tts.hpp>
#include <kumi/kumi.hpp>
#include <tuple>
#include <array>
#include <string>

TTS_CASE("Check generic concepts on product_types"){
  TTS_WHEN("Initialize different product types"){using namespace kumi::literals;

using empty_t = kumi::tuple<>;
using empty_std = std::tuple<>;
using empty_r = kumi::record<>;

using tuple_2 = kumi::tuple<int, float>;
using std_t_2 = std::tuple<int, float>;
using std_a_2 = std::array<int, 2>;
using std_p_2 = std::pair<int, float>;

using tuple_3 = kumi::tuple<int, char, float>;
using tuple_3_nc = kumi::tuple<int, char, std::string>;

using rec_ab = decltype(kumi::record{"a"_id = 1, "b"_id = 2.f});
using rec_ab_alt = decltype(kumi::record{"a"_id = 10, "b"_id = 5.5f});
using rec_ab_diff = decltype(kumi::record{"a"_id = 1, "b"_id = std::string{"hi"}});
using rec_ba = decltype(kumi::record{"b"_id = 2.f, "a"_id = 1});
using rec_xyz = decltype(kumi::record{"x"_id = 1, "y"_id = 2, "z"_id = 3});

TTS_AND_THEN("Check semantic requirements")
{
  TTS_EXPECT((kumi::concepts::follows_same_semantic<tuple_2, std_t_2, std_a_2, empty_t>));
  TTS_EXPECT((kumi::concepts::follows_same_semantic<rec_ab, rec_ba, rec_xyz>));

  TTS_EXPECT_NOT((kumi::concepts::follows_same_semantic<tuple_2, rec_ab>));

  TTS_EXPECT_NOT((kumi::concepts::follows_same_semantic<int, int>));
  TTS_EXPECT_NOT((kumi::concepts::follows_same_semantic<tuple_2, int>));
}

TTS_AND_THEN("Check comparable for equality")
{
  TTS_EXPECT((kumi::concepts::equality_comparable<tuple_2, std_t_2>));
  TTS_EXPECT((kumi::concepts::equality_comparable<std_a_2, std_t_2>));

  TTS_EXPECT_NOT((kumi::concepts::equality_comparable<tuple_3, tuple_3_nc>));
  TTS_EXPECT_NOT((kumi::concepts::equality_comparable<tuple_2, tuple_3>));

  TTS_EXPECT((kumi::concepts::equality_comparable<rec_ab, rec_ba>));
  TTS_EXPECT((kumi::concepts::equality_comparable<rec_ab, rec_ab_alt>));

  TTS_EXPECT_NOT((kumi::concepts::equality_comparable<rec_ab, rec_ab_diff>));
  TTS_EXPECT_NOT((kumi::concepts::equality_comparable<rec_ab, rec_xyz>));

  TTS_EXPECT((kumi::concepts::equality_comparable<empty_t, empty_std>));
  TTS_EXPECT((kumi::concepts::equality_comparable<empty_t, empty_r>));
  TTS_EXPECT_NOT((kumi::concepts::equality_comparable<int, int>));
}

TTS_AND_THEN("Check Compatibility")
{
  TTS_EXPECT((kumi::concepts::compatible_product_types<tuple_2, std_t_2, std_p_2, std_a_2>));
  TTS_EXPECT((kumi::concepts::compatible_product_types<empty_t, empty_std>));

  TTS_EXPECT((kumi::concepts::compatible_product_types<rec_ab, rec_ba, rec_ab_diff>));

  TTS_EXPECT_NOT((kumi::concepts::compatible_product_types<tuple_2, tuple_3>));
  TTS_EXPECT_NOT((kumi::concepts::compatible_product_types<rec_ab, rec_xyz>));
  TTS_EXPECT_NOT((kumi::concepts::compatible_product_types<std_a_2, rec_ab>));
}
}
}
;
