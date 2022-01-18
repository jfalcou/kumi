//==================================================================================================
/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>
#include <string>

TTS_CASE("Check tuple to tuple conversion")
{
  kumi::tuple in{short{49},62.5f};

  TTS_EQUAL ( (in.cast<int ,double>() ) , (kumi::tuple{49 ,62.5}) );
  TTS_EQUAL ( (in.cast<char,int>()    ) , (kumi::tuple{'1',62})   );

  TTS_EQUAL ( kumi::tuple{"some text"}.cast<std::string>()
            , kumi::tuple{std::string("some text")}
            );
};

TTS_CASE("Check tuple to tuple constexpr conversion")
{
  constexpr kumi::tuple in{short{49},62.5f};

  TTS_CONSTEXPR_EQUAL ( (in.cast<int ,double>() ) , (kumi::tuple{49 ,62.5}) );
  TTS_CONSTEXPR_EQUAL ( (in.cast<char,int>()    ) , (kumi::tuple{'1',62})   );
};

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
