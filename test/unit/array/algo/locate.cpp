//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/find.hpp>
#include <tts/tts.hpp>

TTS_CASE("kumi locate runtime behavior")
{
  auto values = kumi::make_array(1, 2, 3, 4);
  TTS_EQUAL(kumi::locate(values, [](auto e) { return e == 4; }), 3ULL);
  TTS_EQUAL(kumi::locate(values, [](auto e) { return e < 0; }), 4ULL);
  TTS_EQUAL(kumi::locate(values, [](auto e) { return e > 0; }), 0LL);
  TTS_EQUAL(kumi::locate(std::move(values), [](auto e) { return e == 3; }), 2ULL);
};

TTS_CASE("kumi locate constexpr behavior")
{
  constexpr auto values = kumi::make_array(1, 2, 3, 4);
  TTS_CONSTEXPR_EQUAL(kumi::locate(values, [](auto e) { return e == 4; }), 3ULL);
  TTS_CONSTEXPR_EQUAL(kumi::locate(values, [](auto e) { return e < 0; }), 4ULL);
  TTS_CONSTEXPR_EQUAL(kumi::locate(values, [](auto e) { return e > 0; }), 0LL);
};
