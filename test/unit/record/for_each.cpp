//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/kumi.hpp>
#include <string_view>
#include <tts/tts.hpp>

struct A { void operator()(auto&&) & {} };
struct B { void operator()(auto&&) && {} };

using namespace kumi::literals;
using namespace std::literals;

TTS_CASE("Check for_each SFINAE compliance")
{
  A a;
  B b;
  auto t = kumi::make_record("a"_f = 1,"b"_f = 2);

  TTS_EXPECT_COMPILES(a, t, { kumi::for_each(a, t); } );
  TTS_EXPECT_NOT_COMPILES(b, t, { kumi::for_each(b, t); } );

};

TTS_CASE("Check for_each behavior")
{
  auto t = kumi::record {"a"_f = 1, "b"_f = 2., "c"_f = 3.4f, "d"_f = '5'};
  
  kumi::for_each([](auto &m) { m++; }, t);

  TTS_EQUAL(get<"a"_f>(t), 2);
  TTS_EQUAL(get<"b"_f>(t), 3.);
  TTS_EQUAL(get<"c"_f>(t), 4.4f);
  TTS_EQUAL(get<"d"_f>(t), '6');
  
  kumi::for_each([](auto &m, auto n) { m *= n; }, t, t);

  TTS_EQUAL(get<"a"_f>(t), 4);
  TTS_EQUAL(get<"b"_f>(t), 9.);
  TTS_EQUAL(get<"c"_f>(t), 19.36f);
  TTS_EQUAL(get<"d"_f>(t), 'd');

  bool was_run = false;
  kumi::for_each([&]() { was_run = true; }, kumi::record{});
  TTS_EXPECT_NOT(was_run);
};

TTS_CASE("Check for_each constexpr behavior")
{
  constexpr auto t = []() {
    auto it = kumi::record {"a"_f = 1, "b"_f = 2., "c"_f = 3.4f, "d"_f = '5'};
    kumi::for_each([](auto &m) { m++; }, it.values());
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<"a"_f>(t), 2);
  TTS_CONSTEXPR_EQUAL(get<"b"_f>(t), 3.);
  TTS_CONSTEXPR_EQUAL(get<"c"_f>(t), 4.4f);
  TTS_CONSTEXPR_EQUAL(get<"d"_f>(t), '6');

  constexpr auto t2 = []() {
    auto it = kumi::record {"a"_f = 1, "b"_f = 2., "c"_f = 3.4f, "d"_f = char(8)};
    kumi::for_each([](auto &m, auto n) { m *= n; }, it, it);
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<"a"_f>(t2), 1);
  TTS_CONSTEXPR_EQUAL(get<"b"_f>(t2), 4.);
  TTS_CONSTEXPR_EQUAL(get<"c"_f>(t2), 11.56f);
  TTS_CONSTEXPR_EQUAL(get<"d"_f>(t2), '@');
};

TTS_CASE("Check for_each_field behavior")
{

  auto t = kumi::record {"a"_f = 1, "ab"_f = 3., "cr"_f = 3.4f, "de"_f = '5'};
  kumi::for_each_field(
      [](auto name, auto &m) {
        if ( name == "a"){
          m++;}
        else
          m--;
      },
      t);

  TTS_EQUAL(get<"a"_f>(t), 2);
  TTS_EQUAL(get<"ab"_f>(t), 2.);
  TTS_EQUAL(get<"cr"_f>(t), 2.4f);
  TTS_EQUAL(get<"de"_f>(t), '4');
  
  kumi::for_each_field(
      [](auto name, auto &m, auto n) {
        if ( std::string_view{name.data(), name.size()}.starts_with('a') )
          m *= n;
        else
          m += n;
      },
      t, t);

  TTS_EQUAL(get<"a"_f>(t), 4);
  TTS_EQUAL(get<"ab"_f>(t), 4.);
  TTS_EQUAL(get<"cr"_f>(t), 4.8f);
  TTS_EQUAL(get<"de"_f>(t), 'h');
};

TTS_CASE("Check for_each_field constexpr behavior")
{
  constexpr auto t = []() {
    auto it = kumi::record {"arg"_f = 1, "beg"_f = 2., "crf"_f = 3.4f, "deg"_f = '5'};
    kumi::for_each_field(
        [](auto name, auto &m) {
          if ( std::string_view{name.data(), name.size()}.ends_with('g') )
            m++;
          else
            m--;
        },
        it);
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<"arg"_f>(t), 2);
  TTS_CONSTEXPR_EQUAL(get<"beg"_f>(t), 3.);
  TTS_CONSTEXPR_EQUAL(get<"crf"_f>(t), 2.4f);
  TTS_CONSTEXPR_EQUAL(get<"deg"_f>(t), '6');

  constexpr auto t2 = []() {
    auto it = kumi::record {"actually"_f = 1, "bike"_f = 2., "what"_f = 3.4f, "delicious"_f = '5'};
    kumi::for_each_field(
        [](auto name, auto &m, auto n) {
          auto s = std::string_view{name.data(), name.size()};
          if ( s.starts_with('a') || s.ends_with('t') )
            m *= n;
          else
            m +=n;
        },
        it, it);
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<"actually"_f>(t2) , 1);
  TTS_CONSTEXPR_EQUAL(get<"bike"_f>(t2)     , 4.);
  TTS_CONSTEXPR_EQUAL(get<"what"_f>(t2)     , 11.56f);
  TTS_CONSTEXPR_EQUAL(get<"delicious"_f>(t2), 'j');

  bool was_run = false;
  kumi::for_each_field([&]() { was_run = true; }, kumi::record{});
  TTS_EXPECT_NOT(was_run);
};
