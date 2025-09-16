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

TTS_CASE("Check result::partition<Func,record> behavior")
{
  TTS_TYPE_IS ( (kumi::result::partition_t<std::is_integral,kumi::record<>>)
              , (kumi::tuple<kumi::record<>,kumi::record<>>)
              );

  TTS_TYPE_IS ( (kumi::result::partition_t<std::is_integral,kumi::record<kumi::field_capture<"a",int>,kumi::field_capture<"b",float>,kumi::field_capture<"c",double>>>)
              , (kumi::tuple<kumi::record<kumi::field_capture<"a",int>>,kumi::record<kumi::field_capture<"b", float>, kumi::field_capture<"c",double>>>)
              );

  TTS_TYPE_IS ( (kumi::result::partition_t< std::is_rvalue_reference
                                          , kumi::record<kumi::field_capture<"a",int&>,kumi::field_capture<"b",float&&>,kumi::field_capture<"c",double const&>>
                                          >
                )
              , (kumi::tuple<kumi::record<kumi::field_capture<"b",float&&>>,kumi::record<kumi::field_capture<"a", int&>, kumi::field_capture<"c", double const&>>>)
              );
};

TTS_CASE("Check partition(kumi::record<>{}) behavior")
{
  TTS_EQUAL ( (kumi::partition<std::is_pointer>(kumi::record{}))
            , (kumi::tuple<kumi::record<>,kumi::record<>>{})
            );
};

TTS_CASE("Check partition() behavior with values")
{
  using namespace kumi::literals;

  int     a = 4;
  double  b = 3.1415;
  float   c = 0.01f;

  auto original = kumi::record{"a"_f = a,"b"_f = &a,"c"_f = b,"d"_f = &b,"e"_f = c,"f"_f = &c,"g"_f = 'z',"h"_f = nullptr};

  TTS_EQUAL ( kumi::partition<std::is_pointer>(original)
            , (kumi::tuple{kumi::record{"b"_f = &a,"d"_f = &b,"f"_f = &c},kumi::record{"a"_f = a,"c"_f = b,"e"_f = c,"g"_f = 'z',"h"_f = nullptr}})
            );

  TTS_EQUAL ( kumi::partition<std::is_floating_point>(original)
            , (kumi::tuple{kumi::record{"c"_f = b,"e"_f = c},kumi::record{"a"_f = a,"b"_f = &a,"d"_f = &b, "f"_f = &c,"g"_f = 'z',"h"_f = nullptr}})
            );

  TTS_EQUAL ( kumi::partition<std::is_null_pointer>(original)
            , (kumi::tuple{kumi::record{"h"_f = nullptr},kumi::record{"a"_f = a,"b"_f = &a,"c"_f = b,"d"_f = &b,"e"_f = c,"f"_f = &c,"g"_f = 'z',}})
            );
};


TTS_CASE("Check partition() behavior with reference")
{
  using namespace kumi::literals;

  int     a = 4;
  double  b = 3.1415;

  auto original = kumi::record<kumi::field_capture<"a", int>,kumi::field_capture<"b", int&>, kumi::field_capture<"c", double>,kumi::field_capture<"d", double&>>{a,a,b,b};

  TTS_EQUAL ( kumi::partition<std::is_lvalue_reference>(original)
            , (kumi::tuple{kumi::record<kumi::field_capture<"b", int&>,kumi::field_capture<"d", double&>>{a,b},kumi::record{"a"_f = a,"c"_f = b}})
            );
};