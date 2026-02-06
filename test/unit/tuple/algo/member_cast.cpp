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

TTS_CASE("Check runtime kumi::member_cast behavior on tuples")
{
  auto base = kumi::tuple{1UL, short{44}, 12.5, 3.f};
  TTS_EQUAL(kumi::member_cast<int>(base), (kumi::tuple{1, 44, 12, 3}));
  TTS_EQUAL(kumi::member_cast<float>(base), (kumi::tuple{1.f, 44.f, 12.5f, 3.f}));
};

TTS_CASE("Check constexpr kumi::member_cast behavior on tuples")
{
  constexpr auto base = kumi::tuple{1UL, short{44}, 12.5, 3.f};
  TTS_CONSTEXPR_EQUAL(kumi::member_cast<int>(base), (kumi::tuple{1, 44, 12, 3}));
  TTS_CONSTEXPR_EQUAL(kumi::member_cast<float>(base), (kumi::tuple{1.f, 44.f, 12.5f, 3.f}));
};

TTS_CASE("Check result::member_cast behavior on tuples")
{
  using base = kumi::tuple<int, char&, float&&, short const, long>;
  using t1 = kumi::tuple<double, double, double, double, double>;
  using t2 = kumi::tuple<char const, char const, char const, char const, char const>;

  TTS_TYPE_IS((kumi::result::member_cast_t<double, base>), (t1));
  TTS_TYPE_IS((kumi::result::member_cast_t<char const, base>), (t2));
};
