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

TTS_CASE("Check runtime kumi::tuple_cast behavior")
{
    auto base   = kumi::tuple{1UL, short{55}, 12.5, 3.f };
    auto t1     = kumi::tuple{1.f, 55.f     , 12  , 3   };
    auto t2     = kumi::tuple{1  , '7'      , 12  , 3.f };

    TTS_EQUAL ( kumi::tuple_cast<decltype(t1)> ( base ) , ( t1 ) );
    TTS_EQUAL ( kumi::tuple_cast<decltype(t2)> ( base)  , ( t2 ) );    
};

TTS_CASE("Check constexpr kumi::tuple_cast behavior")
{
    constexpr auto base   = kumi::tuple{1UL, short{55}, 12.5, 3.f };
    constexpr auto t1     = kumi::tuple{1.f, 55.f     , 12  , 3   };
    constexpr auto t2     = kumi::tuple{1  , '7'      , 12  , 3.f };

    TTS_CONSTEXPR_EQUAL ( kumi::tuple_cast<decltype(t1)> ( base ) , ( t1 ) );
    TTS_CONSTEXPR_EQUAL ( kumi::tuple_cast<decltype(t2)> ( base ) , ( t2 ) );    
};

TTS_CASE("Check result::tuple_cast behavior")
{
    using base  = kumi::tuple<int, char, float, const short, volatile long>;
    using t1    = kumi::tuple<double, double, double, double, double>;
    using t2    = kumi::tuple<const char, const char, const char, const char, const char>;

    TTS_TYPE_IS( (kumi::result::tuple_cast_t<t1, base>) , ( t1 ) );
    TTS_TYPE_IS( (kumi::result::tuple_cast_t<t2, base>) , ( t2 ) );
};
