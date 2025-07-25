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
#include <type_traits>

TTS_CASE("Check behavior of std::common_reference on kumi::tuple")
{
#if !defined( __ANDROID__ )
  TTS_TYPE_IS ( (std::common_reference_t< kumi::tuple<char&,int&,float&>, kumi::tuple<char,int,float>&> )
              , (kumi::tuple<char&,int&,float&>)
              );

  TTS_TYPE_IS ( (std::common_reference_t< kumi::tuple<char&,int&,float&>, kumi::tuple<char,int,float> const&> )
              , (kumi::tuple<char const&,int const&,float const&>)
              );

  TTS_TYPE_IS ( (std::common_reference_t< kumi::tuple<char&,int&,float const&>, kumi::tuple<char,int,float>&> )
              , (kumi::tuple<char&,int&,float const&>)
              );
#else
  TTS_PASS("No support for common_reference on ANDROID");
#endif

};
