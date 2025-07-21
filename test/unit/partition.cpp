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

TTS_CASE("Check result::partition<Func,Tuple> behavior")
{
  TTS_TYPE_IS ( (kumi::result::partition_t<std::is_integral,kumi::tuple<>>)
              , (kumi::tuple<kumi::tuple<>,kumi::tuple<>>)
              );

  TTS_TYPE_IS ( (kumi::result::partition_t<std::is_integral,kumi::tuple<int,float,double>>)
              , (kumi::tuple<kumi::tuple<int>,kumi::tuple<float,double>>)
              );

  TTS_TYPE_IS ( (kumi::result::partition_t< std::is_rvalue_reference
                                          , kumi::tuple<int&,float&&,double const&>
                                          >
                )
              , (kumi::tuple<kumi::tuple<float&&>,kumi::tuple<int&, double const&>>)
              );
};

TTS_CASE("Check partition(kumi::tuple<>{}) behavior")
{
  TTS_EQUAL ( (kumi::partition<std::is_pointer>(kumi::tuple{}))
            , (kumi::tuple<kumi::tuple<>,kumi::tuple<>>{})
            );
};

TTS_CASE("Check partition() behavior with values")
{
  int     a = 4;
  double  b = 3.1415;
  float   c = 0.01f;

  auto original = kumi::tuple{a,&a,b,&b,c,&c,'z',nullptr};

  TTS_EQUAL ( kumi::partition<std::is_pointer>(original)
            , (kumi::tuple{kumi::tuple{&a,&b,&c},kumi::tuple{a,b,c,'z',nullptr}})
            );

  TTS_EQUAL ( kumi::partition<std::is_floating_point>(original)
            , (kumi::tuple{kumi::tuple{b,c},kumi::tuple{a,&a,&b,&c,'z',nullptr}})
            );

  TTS_EQUAL ( kumi::partition<std::is_null_pointer>(original)
            , (kumi::tuple{kumi::tuple{nullptr},kumi::tuple{a,&a,b,&b,c,&c,'z',}})
            );
};


TTS_CASE("Check partition() behavior with reference")
{
  int     a = 4;
  double  b = 3.1415;

  auto original = kumi::tuple<int,int&,double,double&>{a,a,b,b};

  TTS_EQUAL ( kumi::partition<std::is_lvalue_reference>(original)
            , (kumi::tuple{kumi::tuple<int&,double&>{a,b},kumi::tuple{a,b}})
            );
};
