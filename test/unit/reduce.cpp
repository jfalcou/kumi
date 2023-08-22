//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>
#include <vector>


TTS_CASE("Check result::prod/sum/bit_* behavior")
{
  TTS_TYPE_IS ( (kumi::result::sum_t<kumi::tuple<char,short,int,double>,int>)
              , double
              );

  TTS_TYPE_IS ( (kumi::result::prod_t<kumi::tuple<char,short,int,double>,int>)
              , double
              );

  TTS_TYPE_IS ( (kumi::result::bit_or_t<kumi::tuple<short,std::size_t,int>,char>)
              , std::size_t
              );

  TTS_TYPE_IS ( (kumi::result::bit_and_t<kumi::tuple<short,std::size_t,int>,char>)
              , std::size_t
              );

  TTS_TYPE_IS ( (kumi::result::sum_t<kumi::tuple<char,short,int,double>>)
              , double
              );

  TTS_TYPE_IS ( (kumi::result::prod_t<kumi::tuple<char,short,int,double>>)
              , double
              );

  TTS_TYPE_IS ( (kumi::result::bit_or_t<kumi::tuple<short,std::size_t,int>>)
              , std::size_t
              );

  TTS_TYPE_IS ( (kumi::result::bit_and_t<kumi::tuple<short,std::size_t,int>>)
              , std::size_t
              );
};

TTS_CASE("Check tuple::sum behavior")
{
  constexpr auto t = kumi::tuple {2., 1, short {55}, 'z'};

  TTS_EQUAL(kumi::sum(kumi::tuple{}, 42),  42 );
  TTS_EQUAL(kumi::sum(t, 0)             , 180 );

  TTS_CONSTEXPR_EQUAL(kumi::sum(kumi::tuple{}, 42),  42 );
  TTS_CONSTEXPR_EQUAL(kumi::sum(t, 0)             , 180 );
  TTS_CONSTEXPR_EQUAL(kumi::sum(t)                , 180 );
};

TTS_CASE("Check tuple::prod behavior")
{
  constexpr auto t = kumi::tuple {2., 3, short {5}, '\a'};

  TTS_EQUAL(kumi::prod(kumi::tuple{}, 42),  42 );
  TTS_EQUAL(kumi::prod(t, 1)             , 210 );

  TTS_CONSTEXPR_EQUAL(kumi::prod(kumi::tuple{}, 42),  42 );
  TTS_CONSTEXPR_EQUAL(kumi::prod(t, 1)             , 210 );
  TTS_CONSTEXPR_EQUAL(kumi::prod(t)                , 210 );
};

TTS_CASE("Check tuple::bit_and behavior")
{
  constexpr auto t = kumi::tuple {14UL, char{7}, short{6}};

  TTS_EQUAL(kumi::bit_and(kumi::tuple{}, 42),  42 );
  TTS_EQUAL(kumi::bit_and(t, 255)           , 6UL );

  TTS_CONSTEXPR_EQUAL(kumi::bit_and(kumi::tuple{}, 42),  42 );
  TTS_CONSTEXPR_EQUAL(kumi::bit_and(t, 255)           , 6UL );
  TTS_CONSTEXPR_EQUAL(kumi::bit_and(t)                , 6UL );
};

TTS_CASE("Check tuple::bit_or behavior")
{
  constexpr auto t = kumi::tuple {2UL, 3, short {5}, char{64}};

  TTS_EQUAL(kumi::bit_or(kumi::tuple{}, 42),  42  );
  TTS_EQUAL(kumi::bit_or(t, 1)             , 71UL );

  TTS_CONSTEXPR_EQUAL(kumi::bit_or(kumi::tuple{}, 42),  42  );
  TTS_CONSTEXPR_EQUAL(kumi::bit_or(t, 1)             , 71UL );
  TTS_CONSTEXPR_EQUAL(kumi::bit_or(t)                , 71UL );
};
