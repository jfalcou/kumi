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

    auto a = "x"_m = x;
    auto b = "x"_m = y;
    auto c = "x"_m = std::ref(x);
    auto d = "x"_m = std::cref(x);
    auto e = "x"_m = std::move(x);

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

    auto t = kumi::tuple{ "a"_m = x, "b"_m = y, "c"_m = std::ref(x), "d"_m = std::cref(y), "e"_m = z };
    auto nl = kumi::tuple{ kumi::str{"a"}, kumi::str{"b"}, kumi::str{"c"}, kumi::str{"d"}, kumi::str{"e"} };
    
    auto pt = kumi::tuple{"a"_m = x, y, std::ref(x), "d"_m = std::cref(y), z };
    auto ptnl = kumi::tuple{ kumi::str{"a"}, kumi::unit{},kumi::unit{}, kumi::str{"d"}, kumi::unit{} };

    TTS_TYPE_IS( tpl                    , decltype(t )     );
    TTS_TYPE_IS( decltype(t.names())    , decltype(nl)     );
    TTS_TYPE_IS( decltype(pt.names())   , decltype(ptnl)   );

    TTS_EQUAL( t.names() , nl    );
    TTS_EQUAL( pt.names(), ptnl  );
};
