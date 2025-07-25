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

TTS_CASE("Check runtime kumi::fill behavior")
{
  TTS_EQUAL ( kumi::fill<1>(1   ) , (kumi::tuple{1}                          ) );
  TTS_EQUAL ( kumi::fill<2>(2.f ) , (kumi::tuple{2.f, 2.f}                   ) );
  TTS_EQUAL ( kumi::fill<3>(3.  ) , (kumi::tuple{3.,3.,3.}                   ) );
  TTS_EQUAL ( kumi::fill<7>('7' ) , (kumi::tuple{'7','7','7','7','7','7','7'}) );
};

TTS_CASE("Check constexpr kumi::fill behavior")
{
  TTS_CONSTEXPR_EQUAL ( kumi::fill<1>(1   ) , (kumi::tuple{1}                          ) );
  TTS_CONSTEXPR_EQUAL ( kumi::fill<2>(2.f ) , (kumi::tuple{2.f, 2.f}                   ) );
  TTS_CONSTEXPR_EQUAL ( kumi::fill<3>(3.  ) , (kumi::tuple{3.,3.,3.}                   ) );
  TTS_CONSTEXPR_EQUAL ( kumi::fill<7>('7' ) , (kumi::tuple{'7','7','7','7','7','7','7'}) );
};
