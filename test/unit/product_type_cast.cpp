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

struct from_type
{
    int value;
    
    from_type(int& i) : value{i}
    {}

    template<typename T>
    from_type(kumi::tuple<T,T>) : value{15}
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

TTS_CASE("Check runtime kumi::product_type_cast behavior on tuples")
{
    int a = 15;
    from_type b{a};

    auto base   = kumi::tuple{1UL, short{55}, 12.5, 3.f , std::ref(a)   };
    auto t1     = kumi::tuple{1.f, 55.f     , 12  , 3   , 15.f          };
    auto t2     = kumi::tuple{1  , '7'      , 12  , 3.f , b             };

    auto base2  = kumi::tuple{1, 3.f, 'x', kumi::tuple{3.f, 3.f}};
    auto dest2  = kumi::tuple{1, 3. , 'x', b                    };

    TTS_EQUAL ( kumi::product_type_cast<decltype(t1)> ( base ) , ( t1 ) );
    TTS_EQUAL ( kumi::product_type_cast<decltype(t2)> ( base)  , ( t2 ) );    
    TTS_EQUAL ( kumi::product_type_cast<decltype(dest2)> ( base2)  , ( dest2) );    
};

TTS_CASE("Check constexpr kumi::product_type_cast behavior on tuples")
{
    constexpr auto base   = kumi::tuple{1UL, short{55}, 12.5, 3.f };
    constexpr auto t1     = kumi::tuple{1.f, 55.f     , 12  , 3   };
    constexpr auto t2     = kumi::tuple{1  , '7'      , 12  , 3.f };

    TTS_CONSTEXPR_EQUAL ( kumi::product_type_cast<decltype(t1)> ( base ) , ( t1 ) );
    TTS_CONSTEXPR_EQUAL ( kumi::product_type_cast<decltype(t2)> ( base ) , ( t2 ) );    
};

TTS_CASE("Check result::product_type_cast behavior on tuples")
{
    using base  = kumi::tuple<int, char&&, float, const short, long&>;
    using t1    = kumi::tuple<double, double, const double, double, double>;
    using t2    = kumi::tuple<const char, const char, const char, const char, const char>;

    TTS_TYPE_IS( (kumi::result::product_type_cast_t<t1, base>) , ( t1 ) );
    TTS_TYPE_IS( (kumi::result::product_type_cast_t<t2, base>) , ( t2 ) );
};
