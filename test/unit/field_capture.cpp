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

TTS_CASE("Check field_capture type coherence")
{
    int x = 1;

    auto a = kumi::field_capture<"x", int>{x};
    auto b = kumi::field_capture<"x", const int>{x};
    auto c = kumi::field_capture<"x", int&>{x};
    auto d = kumi::field_capture<"x", int const &>{x};
    auto e = kumi::field_capture<"x", int&&>{std::move(x)};

    TTS_TYPE_IS((decltype(a.value)), int);
    TTS_TYPE_IS((decltype(b.value)), const int);
    TTS_TYPE_IS((decltype(c.value)), int&);
    TTS_TYPE_IS((decltype(d.value)), int const &);
    TTS_TYPE_IS((decltype(e.value)), int&&);

    c.value ++;
    TTS_EQUAL(a.value, 1);
    TTS_EQUAL(b.value, 1);
    TTS_EQUAL(c.value, 2);
    TTS_EQUAL(d.value, 2);
    TTS_EQUAL(e.value, 2);
    TTS_EQUAL(x, 2);
};

TTS_CASE("Check field_capture type coherence through field_name")
{
    using namespace kumi::literals;

    int x           = 1;
    const int y     = 1;

    auto a = "x"_f = x;
    auto b = "x"_f = y;
    auto c = "x"_f = std::ref(x);
    auto d = "x"_f = std::cref(x);
    auto e = "x"_f = std::move(x);

    TTS_TYPE_IS((decltype(a.value)), int);
    TTS_TYPE_IS((decltype(b.value)), int);
    TTS_TYPE_IS((decltype(c.value)), int&);
    TTS_TYPE_IS((decltype(d.value)), int const &);
    TTS_TYPE_IS((decltype(e.value)), int);

    c.value ++;
    TTS_EQUAL(a.value, 1);
    TTS_EQUAL(b.value, 1);
    TTS_EQUAL(c.value, 2);
    TTS_EQUAL(d.value, 2);
    TTS_EQUAL(e.value, 1);
    TTS_EQUAL(x, 2);
};

template<auto name> 
constexpr bool check_valid_name(auto const t) requires( requires{t[name]; })
{
    return true;
}

template<auto name> 
constexpr bool check_valid_name(auto const t) requires( !requires{t[name]; })
{
    return false;
}

TTS_CASE("Check kumi::tuple behavior with field_captures")
{
    using namespace kumi::literals;

    int x       = 1;
    const int y = 2;
    int&& z     = std::move(x);

    using f     = kumi::field_capture<"a", int         >; 
    using fc    = kumi::field_capture<"b", int         >;
    using fref  = kumi::field_capture<"c", int&        >;
    using fcref = kumi::field_capture<"d", const int&  >;
    using furef = kumi::field_capture<"e", int         >;

    using tpl   = kumi::tuple<f, fc, fref, fcref, furef>;

    auto t  = kumi::tuple{ "a"_f = x     , "b"_f = y     , "c"_f = std::ref(x), "d"_f = std::cref(y), "e"_f = z      };
    auto nl = kumi::tuple{ kumi::str{"a"}, kumi::str{"b"}, kumi::str{"c"}     , kumi::str{"d"}      , kumi::str{"e"} };
    
    auto pt   = kumi::tuple{"a"_f = x      , y         , std::ref(x), "d"_f = std::cref(y), z          };
    auto ptnl = kumi::tuple{ kumi::str{"a"}, kumi::none, kumi::none , kumi::str{"d"}      , kumi::none };

    constexpr auto dup = kumi::tuple{"a"_f = 3, "a"_f = 8};
    constexpr auto uni = kumi::tuple{"a"_f = 3, "b"_f = 8};

    TTS_TYPE_IS( tpl                    , decltype(t )     );
    TTS_TYPE_IS( decltype(t.names())    , decltype(nl)     );
    TTS_TYPE_IS( decltype(pt.names())   , decltype(ptnl)   );

    TTS_EQUAL( t.names() , nl    );
    TTS_EQUAL( pt.names(), ptnl  );

    TTS_EXPECT          (! check_valid_name<"a"_f>(dup));
    TTS_CONSTEXPR_EXPECT(! check_valid_name<"a"_f>(dup));

    TTS_EXPECT          ( check_valid_name<"a"_f>(uni) );
    TTS_CONSTEXPR_EXPECT( check_valid_name<"a"_f>(uni) );
};
