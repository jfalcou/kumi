//==================================================================================================
/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check tuple::as_flat function behavior")
{
  auto t = kumi::tuple{3.25f, kumi::tuple {2., kumi::tuple {2., 1, short {55}}, short {55}}, 'a'};
  auto f = kumi::as_flat(t);

  TTS_EQUAL(get<0>(f), &                get<0>(t)   );
  TTS_EQUAL(get<1>(f), &        get<0>( get<1>(t) ) );
  TTS_EQUAL(get<2>(f), &get<0>( get<1>( get<1>(t))) );
  TTS_EQUAL(get<3>(f), &get<1>( get<1>( get<1>(t))) );
  TTS_EQUAL(get<4>(f), &get<2>( get<1>( get<1>(t))) );
  TTS_EQUAL(get<5>(f), &        get<2>( get<1>(t) ) );
  TTS_EQUAL(get<6>(f), &                get<2>(t)   );
};
