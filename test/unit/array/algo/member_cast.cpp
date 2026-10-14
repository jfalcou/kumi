//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/cast.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check runtime kumi::member_cast behavior on arrays")
{
  auto base = kumi::array{1, 44, 12, 3};
  TTS_EQUAL(kumi::member_cast<int>(base), (kumi::array{1, 44, 12, 3}));
  TTS_EQUAL(kumi::member_cast<float>(base), (kumi::array{1.f, 44.f, 12.f, 3.f}));
  TTS_EQUAL(kumi::member_cast<double>(base), (kumi::array{1., 44., 12., 3.}));
};

TTS_CASE("Check constexpr kumi::member_cast behavior on arrays")
{
  constexpr auto base = kumi::array{1, 44, 12, 3};
  TTS_CONSTEXPR_EQUAL(kumi::member_cast<int>(base), (kumi::array{1, 44, 12, 3}));
  TTS_CONSTEXPR_EQUAL(kumi::member_cast<float>(base), (kumi::array{1.f, 44.f, 12.f, 3.f}));
  TTS_CONSTEXPR_EQUAL(kumi::member_cast<double>(base), (kumi::array{1., 44., 12., 3.}));
};

TTS_CASE("Check result::member_cast behavior on arrays")
{
  using base = kumi::array<int, 5>;
  TTS_TYPE_IS((kumi::result::member_cast_t<double, base>), (kumi::array<double, 5>));
  TTS_TYPE_IS((kumi::result::member_cast_t<short, base>), (kumi::array<short, 5>));
};
