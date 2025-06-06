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

TTS_CASE("Check member_capture type coherence")
{
    int x = 1;

    auto a = kumi::member_capture<"x", int>{x};
    auto b = kumi::member_capture<"x", const int>{x};
    auto c = kumi::member_capture<"x", int&>{x};
    auto d = kumi::member_capture<"x", int const &>{x};
    auto e = kumi::member_capture<"x", int&&>{std::move(x)};

    TTS_TYPE_IS((decltype(a.value)), int);
    TTS_TYPE_IS((decltype(b.value)), const int);
    TTS_TYPE_IS((decltype(c.value)), int&);
    TTS_TYPE_IS((decltype(d.value)), int const &);
    TTS_TYPE_IS((decltype(e.value)), int&&);

    c++;
    TTS_EQUAL(a.value, 1);
    TTS_EQUAL(b.value, 1);
    TTS_EQUAL(c.value, 2);
    TTS_EQUAL(d.value, 2);
    TTS_EQUAL(e.value, 2);
    TTS_EQUAL(x, 2);
};

TTS_CASE("Check member_capture type coherence through member_name")
{
    using namespace kumi::literals;

    int x           = 1;
    const int y     = 1;

    auto a = "x"_m = x;
    auto b = "x"_m = y;
    auto c = "x"_m = std::ref(x);
    auto d = "x"_m = std::cref(y);
    auto e = "x"_m = std::move(x);

    TTS_TYPE_IS((decltype(a.value)), int);
    TTS_TYPE_IS((decltype(b.value)), int);
    TTS_TYPE_IS((decltype(c.value)), int&);
    TTS_TYPE_IS((decltype(d.value)), int const &);
    TTS_TYPE_IS((decltype(e.value)), int);
};

TTS_CASE("Check kumi::tuple behavior with member_captures")
{
    using namespace kumi::literals;

    using f     = kumi::member_capture<"a", int       >; 
    using fc    = kumi::member_capture<"b", const int >;
    using fref  = kumi::member_capture<"c", int&      >;
    using fcref = kumi::member_capture<"d", const int&>;
    using furef = kumi::member_capture<"e", int&&     >;

    using tpl = kumi::tuple<f, fc, fref, fcref, furef>;

    int x = 1;
    auto t = kumi::tuple{f{x}, fc{x}, fref{x}, fcref{x}, furef(std::move(x))};
    
    TTS_TYPE_IS(tpl , decltype(t));

    using namelist = kumi::str_list<kumi::str{"a"}, kumi::str{"b"}, kumi::str{"c"}
                    , kumi::str{"d"}, kumi::str{"e"}>;

    namelist nl{};

    TTS_TYPE_IS((decltype(t.names())), (decltype(nl)));
    TTS_EQUAL((decltype(t.names())::get<0>()), namelist::get<0>());
};
