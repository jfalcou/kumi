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

constexpr auto t1 = [](auto &p){ return static_cast<int>(p);        };
constexpr auto t2 = [](auto   ){ return 2.f;                        };
constexpr auto t3 = [](auto  p){ return static_cast<double>(p);     };
constexpr auto t4 = [](auto   ){ return '7';                        };

TTS_CASE("Check runtime kumi::generate behavior")
{
  TTS_EQUAL ( kumi::generate<1>(t1 ) , (kumi::tuple{0}                          ) );
  TTS_EQUAL ( kumi::generate<2>(t2 ) , (kumi::tuple{2.f, 2.f}                   ) );
  TTS_EQUAL ( kumi::generate<9>(t3 ) , (kumi::tuple{0.,1.,2.,3.,4.,5.,6.,7.,8.} ) );
  TTS_EQUAL ( kumi::generate<7>(t4 ) , (kumi::tuple{'7','7','7','7','7','7','7'}) );
};

TTS_CASE("Check constexpr kumi::generate behavior")
{
  TTS_CONSTEXPR_EQUAL ( kumi::generate<1>(t1 ) , (kumi::tuple{0}                          ) );
  TTS_CONSTEXPR_EQUAL ( kumi::generate<2>(t2 ) , (kumi::tuple{2.f, 2.f}                   ) );
  TTS_CONSTEXPR_EQUAL ( kumi::generate<9>(t3 ) , (kumi::tuple{0.,1.,2.,3.,4.,5.,6.,7.,8.} ) );
  TTS_CONSTEXPR_EQUAL ( kumi::generate<7>(t4 ) , (kumi::tuple{'7','7','7','7','7','7','7'}) );
};
