//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check runtime kumi::generate behavior")
{
  TTS_EQUAL ( kumi::generate<1>(1   ) , (kumi::tuple{1}                          ) );
  TTS_EQUAL ( kumi::generate<2>(2.f ) , (kumi::tuple{2.f, 2.f}                   ) );
  TTS_EQUAL ( kumi::generate<3>(3.  ) , (kumi::tuple{3.,3.,3.}                   ) );
  TTS_EQUAL ( kumi::generate<7>('7' ) , (kumi::tuple{'7','7','7','7','7','7','7'}) );
};

TTS_CASE("Check constexpr kumi::generate behavior")
{
  TTS_CONSTEXPR_EQUAL ( kumi::generate<1>(1   ) , (kumi::tuple{1}                          ) );
  TTS_CONSTEXPR_EQUAL ( kumi::generate<2>(2.f ) , (kumi::tuple{2.f, 2.f}                   ) );
  TTS_CONSTEXPR_EQUAL ( kumi::generate<3>(3.  ) , (kumi::tuple{3.,3.,3.}                   ) );
  TTS_CONSTEXPR_EQUAL ( kumi::generate<7>('7' ) , (kumi::tuple{'7','7','7','7','7','7','7'}) );
};
