//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>
#include <string>
#include <compare>

struct my_struct
{
  std::size_t n;
  double      data;
  constexpr auto operator<=>(my_struct const&) const = default;
};

TTS_CASE("Check tuple to constructible type conversion")
{
  kumi::tuple in{std::size_t{9}, 13.37};

  TTS_EQUAL ( kumi::from_tuple<my_struct>(in), (my_struct{9,13.37}) );
};

TTS_CASE("Check tuple to constructible type constexpr conversion")
{
  constexpr kumi::tuple in{std::size_t{9}, 13.37};

  TTS_CONSTEXPR_EQUAL ( kumi::from_tuple<my_struct>(in), (my_struct{9,13.37}) );
};
