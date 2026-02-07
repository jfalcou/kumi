//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <string_view>
#include <tts/tts.hpp>

struct A
{
  void operator()(auto&&) & {}
};

struct B
{
  void operator()(auto&&) && {}
};

using namespace kumi::literals;
using namespace std::literals;

TTS_CASE("Check for_each SFINAE compliance")
{
  A a;
  B b;
  auto t = kumi::make_record("a"_n = 1, "b"_n = 2);

  TTS_EXPECT_COMPILES(a, t, { kumi::for_each(a, t); });
  TTS_EXPECT_NOT_COMPILES(b, t, { kumi::for_each(b, t); });
};

TTS_CASE("Check for_each behavior")
{
  auto t = kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f, "d"_n = '5'};

  kumi::for_each([](auto& m) { m++; }, t);

  TTS_EQUAL(get<"a"_n>(t), 2);
  TTS_EQUAL(get<"b"_n>(t), 3.);
  TTS_EQUAL(get<"c"_n>(t), 4.4f);
  TTS_EQUAL(get<"d"_n>(t), '6');

  kumi::for_each([](auto& m, auto n) { m *= n; }, t, t);

  TTS_EQUAL(get<"a"_n>(t), 4);
  TTS_EQUAL(get<"b"_n>(t), 9.);
  TTS_EQUAL(get<"c"_n>(t), 19.36f);
  TTS_EQUAL(get<"d"_n>(t), 'd');

  bool was_run = false;
  kumi::for_each([&]() { was_run = true; }, kumi::record{});
  TTS_EXPECT_NOT(was_run);
};

TTS_CASE("Check for_each constexpr behavior")
{
  constexpr auto t = []() {
    auto it = kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f, "d"_n = '5'};
    kumi::for_each([](auto& m) { m++; }, it.values());
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<"a"_n>(t), 2);
  TTS_CONSTEXPR_EQUAL(get<"b"_n>(t), 3.);
  TTS_CONSTEXPR_EQUAL(get<"c"_n>(t), 4.4f);
  TTS_CONSTEXPR_EQUAL(get<"d"_n>(t), '6');

  constexpr auto t2 = []() {
    auto it = kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f, "d"_n = char(8)};
    kumi::for_each([](auto& m, auto n) { m *= n; }, it, it);
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<"a"_n>(t2), 1);
  TTS_CONSTEXPR_EQUAL(get<"b"_n>(t2), 4.);
  TTS_CONSTEXPR_EQUAL(get<"c"_n>(t2), 11.56f);
  TTS_CONSTEXPR_EQUAL(get<"d"_n>(t2), '@');
};

TTS_CASE("Check for_each_field behavior")
{

  auto t = kumi::record{"a"_n = 1, "ab"_n = 3., "cr"_n = 3.4f, "de"_n = '5'};
  kumi::for_each_field(
    [](auto name, auto& m) {
      if (name == "a") { m++; }
      else m--;
    },
    t);

  TTS_EQUAL(get<"a"_n>(t), 2);
  TTS_EQUAL(get<"ab"_n>(t), 2.);
  TTS_EQUAL(get<"cr"_n>(t), 2.4f);
  TTS_EQUAL(get<"de"_n>(t), '4');

  kumi::for_each_field(
    [](kumi::str name, auto& m, auto n) {
      if (name.as<std::string_view>().starts_with('a')) m *= n;
      else m += n;
    },
    t, t);

  TTS_EQUAL(get<"a"_n>(t), 4);
  TTS_EQUAL(get<"ab"_n>(t), 4.);
  TTS_EQUAL(get<"cr"_n>(t), 4.8f);
  TTS_EQUAL(get<"de"_n>(t), 'h');
};

TTS_CASE("Check for_each_field constexpr behavior")
{
  constexpr auto t = []() {
    auto it = kumi::record{"arg"_n = 1, "beg"_n = 2., "crf"_n = 3.4f, "deg"_n = '5'};
    kumi::for_each_field(
      [](kumi::str name, auto& m) {
        if (name.as<std::string_view>().ends_with("g")) m++;
        else m--;
      },
      it);
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<"arg"_n>(t), 2);
  TTS_CONSTEXPR_EQUAL(get<"beg"_n>(t), 3.);
  TTS_CONSTEXPR_EQUAL(get<"crf"_n>(t), 2.4f);
  TTS_CONSTEXPR_EQUAL(get<"deg"_n>(t), '6');

  constexpr auto t2 = []() {
    auto it = kumi::record{"actually"_n = 1, "bike"_n = 2., "what"_n = 3.4f, "delicious"_n = '5'};
    kumi::for_each_field(
      [](kumi::str name, auto& m, auto n) {
        auto s = name.as<std::string_view>();
        if (s.starts_with('a') || s.ends_with('t')) m *= n;
        else m += n;
      },
      it, it);
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<"actually"_n>(t2), 1);
  TTS_CONSTEXPR_EQUAL(get<"bike"_n>(t2), 4.);
  TTS_CONSTEXPR_EQUAL(get<"what"_n>(t2), 11.56f);
  TTS_CONSTEXPR_EQUAL(get<"delicious"_n>(t2), 'j');

  bool was_run = false;
  kumi::for_each_field([&]() { was_run = true; }, kumi::record{});
  TTS_EXPECT_NOT(was_run);
};
