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

using namespace kumi::literals;

struct from_type
{
    int value;
    
    from_type(int& i) : value{i} {}

    template<typename T, typename U>
    from_type(kumi::record<T,U>) : value{15}
    {}

    friend constexpr auto operator==(from_type const& a, from_type const& b) noexcept
    {
        return a.value == b.value;
    }
    
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT,Traits> &operator<<( std::basic_ostream<CharT, Traits> &os
                                                       , from_type const& w) noexcept
    {
      return os << w.value;
    }
};

TTS_CASE("Check runtime kumi::product_type_cast behavior on records")
{
    int a = 15;
    from_type b{a};

    auto base   = kumi::record{"a"_f = 1UL, "b"_f = short{55}, "c"_f = 12.5, "d"_f = 3.f , "e"_f = std::ref(a)};
    auto t1     = kumi::record{"d"_f = 1.f, "a"_f = 55.f     , "c"_f = 12  , "b"_f = 3   , "e"_f = 15.f       };
    auto t2     = kumi::record{"a"_f = 1  , "b"_f = '7'      , "c"_f = 12  , "d"_f = 3.f , "e"_f = b          };

    auto base2  = kumi::record{"a"_f = 1, "b"_f = 3.f, "c"_f = 'x', "d"_f = kumi::record{"a"_f = 3.f, "b"_f = 3.f}};
    auto dest2  = kumi::record{"a"_f = 1, "b"_f = 3. , "c"_f = 'x', "d"_f = b                    };

    TTS_EQUAL ( kumi::product_type_cast<decltype(t1)> ( base ) , ( t1 ) );
    TTS_EQUAL ( kumi::product_type_cast<decltype(t2)> ( base)  , ( t2 ) );    
    TTS_EQUAL ( kumi::product_type_cast<decltype(dest2)> ( base2)  , ( dest2) );    
};

TTS_CASE("Check runtime kumi::product_type_cast behavior on records")
{
    constexpr auto base   = kumi::record{"a"_f = 1UL, "b"_f = short{55}, "c"_f = 12.5, "d"_f = 3.f };
    constexpr auto t1     = kumi::record{"d"_f = 1.f, "a"_f = 55.f     , "c"_f = 12  , "b"_f = 3   };
    constexpr auto t2     = kumi::record{"a"_f = 1  , "b"_f = '7'      , "c"_f = 12  , "d"_f = 3.f };

    TTS_CONSTEXPR_EQUAL ( kumi::product_type_cast<decltype(t1)> ( base ) , ( t1 ) );
    TTS_CONSTEXPR_EQUAL ( kumi::product_type_cast<decltype(t2)> ( base)  , ( t2 ) );    
};

TTS_CASE("Check result::product_type_cast behavior on records")
{
    using namespace kumi;
    using base  = record<field_capture<"a", int       >, field_capture<"b",char&&    >, field_capture<"c",float       >, field_capture<"d",const short>, field_capture<"e",long&     >>;
    using t1    = record<field_capture<"a", double    >, field_capture<"d",double    >, field_capture<"e",const double>, field_capture<"f",double     >, field_capture<"c",double    >>;
    using t2    = record<field_capture<"a", const char>, field_capture<"b",const char>, field_capture<"c",const char  >, field_capture<"d",const char >, field_capture<"e",const char>>;

    TTS_TYPE_IS( (kumi::result::product_type_cast_t<t1, base>) , ( t1 ) );
    TTS_TYPE_IS( (kumi::result::product_type_cast_t<t2, base>) , ( t2 ) );
};
