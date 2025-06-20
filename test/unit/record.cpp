//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/record.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check record type coherence")
{
    using namespace kumi::literals;
    int x = 1;
    int y = 1;

    auto a = kumi::field_capture<"a", int>{x};
    auto b = kumi::field_capture<"b", const int>{x};
    auto c = kumi::field_capture<"c", int&>{x};
    auto d = kumi::field_capture<"d", int const &>{x};
    auto e = kumi::field_capture<"e", int&&>{std::move(y)};

    auto rec = kumi::record{a, b, c, d, std::move(e)};

    TTS_TYPE_IS((decltype(kumi::get<0_c>(rec))), std::add_lvalue_reference_t<decltype(a)>);
    TTS_TYPE_IS((decltype(kumi::get<1_c>(rec))), std::add_lvalue_reference_t<decltype(b)>);
    TTS_TYPE_IS((decltype(kumi::get<2_c>(rec))), std::add_lvalue_reference_t<decltype(c)>);
    TTS_TYPE_IS((decltype(kumi::get<3_c>(rec))), std::add_lvalue_reference_t<decltype(d)>);
    TTS_TYPE_IS((decltype(kumi::get<4_c>(rec))), std::add_lvalue_reference_t<decltype(e)>);

    kumi::get<"c"_f>(rec) ++;
    TTS_EQUAL(a.value, 1);
    TTS_EQUAL(b.value, 1);
    TTS_EQUAL(c.value, 2);
    TTS_EQUAL(d.value, 2);
    TTS_EQUAL(e.value, 1);
    TTS_EQUAL(x, 2);
};

TTS_CASE("Check record equality coherence")
{
   using namespace kumi::literals; 

   auto t   = kumi::record{"x"_f = 1, "y"_f = 2.f, "z"_f = 3., "t"_f = 'c'};
   auto t2  = kumi::record{"y"_f = 2.f, "z"_f = 3., "t"_f = 'c', "x"_f = 1};

   auto tx = kumi::record{"x"_f = 1.f, "y"_f = 4, "z"_f = 'x', "t"_f = kumi::str{"str"}};
    
   auto a = kumi::record{"x"_f = 0, "z"_f = 0., "t"_f = 'a', "y"_f = 42.f};
  
   auto r = kumi::_::fieldwise_convertible<decltype(t), decltype(a)>;
   TTS_EQUAL(r, true);
   a = std::move(t);
    
   auto b = t;
   
   auto not_comp = kumi::named_equality_comparable<decltype(t), decltype(tx)>;
   
   TTS_EQUAL(kumi::get<"x"_f>(t), 1);
   TTS_EQUAL(not_comp, false);

   //TTS_EQUAL(a, t);
   TTS_EQUAL(t, t);
   TTS_EQUAL(t, t2);
   TTS_EQUAL(t, b);
};
