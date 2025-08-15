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
#include "test.hpp"

TTS_CASE("Check result::filter_t<Func,Tuple> behavior")
{
  TTS_TYPE_IS ( (kumi::result::filter_t<std::is_integral,kumi::tuple<>>), (kumi::tuple<>));

  TTS_TYPE_IS ( (kumi::result::filter_t<std::is_integral,kumi::tuple<int,float,double>>)
              , (kumi::tuple<int>)
              );

  TTS_TYPE_IS ( (kumi::result::filter_t< std::is_rvalue_reference
                                          , kumi::tuple<int&,float&&,double const&>
                                          >
                )
              , (kumi::tuple<float&&>)
              );
};

TTS_CASE("Check filter(kumi::tuple<>{}) behavior")
{
  TTS_EQUAL ( (kumi::filter<std::is_pointer>(kumi::tuple{}))
            , (kumi::tuple<>{})
            );
};

TTS_CASE("Check partition() behavior with values")
{
  int     a = 4;
  double  b = 3.1415;
  float   c = 0.01f;

  auto original = kumi::tuple{a,&a,b,&b,c,&c,'z',nullptr};

  TTS_EQUAL ( kumi::filter<std::is_pointer>(original)
            , (kumi::tuple{&a,&b,&c})
            );

  TTS_EQUAL ( kumi::filter<std::is_floating_point>(original)
            , (kumi::tuple{b,c})
            );

  TTS_EQUAL ( kumi::filter<std::is_null_pointer>(original)
            , (kumi::tuple{nullptr})
            );

  auto t = kumi::tuple{1.f, 2, 'x', moveonly{}};
  TTS_EXPECT_COMPILES(t, {kumi::filter<is_moveonly_type>(std::move(t));});
};


TTS_CASE("Check filter() behavior with reference")
{
  int     a = 4;
  double  b = 3.1415;

  auto original = kumi::tuple<int,int&,double,double&>{a,a,b,b};

  TTS_EQUAL ( kumi::filter<std::is_lvalue_reference>(original)
            , (kumi::tuple<int&,double&>{a,b})
            );
};
