
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

using namespace kumi::literals;

TTS_CASE("Check result::filter_t<Func,record> behavior")
{
  TTS_TYPE_IS ( (kumi::result::filter_t<std::is_integral,kumi::record<>>), (kumi::record<>));

  TTS_TYPE_IS ( (kumi::result::filter_t<std::is_integral,
                kumi::record<kumi::field_capture<"a",int>,
                             kumi::field_capture<"b",float>,
                             kumi::field_capture<"c",double>
                            >>)
              , (kumi::record<kumi::field_capture<"a",int>>)
              );

  TTS_TYPE_IS ( ( kumi::result::filter_t< std::is_rvalue_reference
                , kumi::record<
                    kumi::field_capture<"a",int&>,
                    kumi::field_capture<"b",float&&>,
                    kumi::field_capture<"c",double const&>>
                  >
                )
              , (kumi::record<kumi::field_capture<"b",float&&>>)
              );
};

TTS_CASE("Check filter(kumi::record<>{}) behavior")
{
  TTS_EQUAL ( (kumi::filter<std::is_pointer>(kumi::record{}))
            , (kumi::record<>{})
            );
};

TTS_CASE("Check filter() behavior with values")
{
  int     a = 4;
  double  b = 3.1415;
  float   c = 0.01f;

  auto original = kumi::record{"a"_f=a,"b"_f=&a,"c"_f=b,"d"_f=&b
                              ,"e"_f=c,"f"_f=&c,"g"_f='z',"h"_f=nullptr};

  TTS_EQUAL ( kumi::filter<std::is_pointer>(original)
            , (kumi::record{"b"_f=&a,"d"_f=&b,"f"_f=&c})
            );

  TTS_EQUAL ( kumi::filter<std::is_floating_point>(original)
            , (kumi::record{"c"_f=b,"e"_f=c})
            );

  TTS_EQUAL ( kumi::filter<std::is_null_pointer>(original)
            , (kumi::record{"h"_f=nullptr})
            );

  auto t = kumi::record{"a"_f=1.f,"b"_f=2,"c"_f='x',"d"_f=moveonly{}};
  TTS_EXPECT_COMPILES(t, {kumi::filter<is_moveonly_type>(std::move(t));});
};


TTS_CASE("Check filter() behavior with reference")
{
  int     a = 4;
  double  b = 3.1415;

  auto original = kumi::record< kumi::field_capture<"a",int>
                              , kumi::field_capture<"b",int&>
                              , kumi::field_capture<"c",double>
                              , kumi::field_capture<"d",double&>>
                              {a,a,b,b};

  TTS_EQUAL ( kumi::filter<std::is_lvalue_reference>(original)
            , (kumi::record< kumi::field_capture<"b",int&>
                            ,kumi::field_capture<"d",double&>>{a,b})
            );
};
