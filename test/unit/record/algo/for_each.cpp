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
  auto t = kumi::make_record("a"_id = 1, "b"_id = 2);

  TTS_EXPECT_COMPILES(a, t, { kumi::for_each(a, t); });
  TTS_EXPECT_NOT_COMPILES(b, t, { kumi::for_each(b, t); });
};

TTS_CASE("Check for_each behavior")
{
  auto t = kumi::record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f, "d"_id = '5'};

  kumi::for_each([](auto& m) { m++; }, t);

  TTS_EQUAL(get<"a"_id>(t), 2);
  TTS_EQUAL(get<"b"_id>(t), 3.);
  TTS_EQUAL(get<"c"_id>(t), 4.4f);
  TTS_EQUAL(get<"d"_id>(t), '6');

  kumi::for_each([](auto& m, auto n) { m *= n; }, t, t);

  TTS_EQUAL(get<"a"_id>(t), 4);
  TTS_EQUAL(get<"b"_id>(t), 9.);
  TTS_EQUAL(get<"c"_id>(t), 19.36f);
  TTS_EQUAL(get<"d"_id>(t), 'd');

  bool was_run = false;
  kumi::for_each([&]() { was_run = true; }, kumi::record{});
  TTS_EXPECT_NOT(was_run);
};

TTS_CASE("Check for_each constexpr behavior")
{
  constexpr auto t = []() {
    auto it = kumi::record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f, "d"_id = '5'};
    kumi::for_each([](auto& m) { m++; }, it.values());
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<"a"_id>(t), 2);
  TTS_CONSTEXPR_EQUAL(get<"b"_id>(t), 3.);
  TTS_CONSTEXPR_EQUAL(get<"c"_id>(t), 4.4f);
  TTS_CONSTEXPR_EQUAL(get<"d"_id>(t), '6');

  constexpr auto t2 = []() {
    auto it = kumi::record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f, "d"_id = char(8)};
    kumi::for_each([](auto& m, auto n) { m *= n; }, it, it);
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<"a"_id>(t2), 1);
  TTS_CONSTEXPR_EQUAL(get<"b"_id>(t2), 4.);
  TTS_CONSTEXPR_EQUAL(get<"c"_id>(t2), 11.56f);
  TTS_CONSTEXPR_EQUAL(get<"d"_id>(t2), '@');
};

TTS_CASE("Check for_each_field behavior")
{

  auto t = kumi::record{"a"_id = 1, "ab"_id = 3., "cr"_id = 3.4f, "de"_id = '5'};
  kumi::for_each_field(
    [](auto name, auto& m) {
      if (name == "a") { m++; }
      else m--;
    },
    t);

  TTS_EQUAL(get<"a"_id>(t), 2);
  TTS_EQUAL(get<"ab"_id>(t), 2.);
  TTS_EQUAL(get<"cr"_id>(t), 2.4f);
  TTS_EQUAL(get<"de"_id>(t), '4');

  kumi::for_each_field(
    [](kumi::str name, auto& m, auto n) {
      if (name.as<std::string_view>().starts_with('a')) m *= n;
      else m += n;
    },
    t, t);

  TTS_EQUAL(get<"a"_id>(t), 4);
  TTS_EQUAL(get<"ab"_id>(t), 4.);
  TTS_EQUAL(get<"cr"_id>(t), 4.8f);
  TTS_EQUAL(get<"de"_id>(t), 'h');
};

TTS_CASE("Check for_each_field constexpr behavior")
{
  constexpr auto t = []() {
    auto it = kumi::record{"arg"_id = 1, "beg"_id = 2., "crf"_id = 3.4f, "deg"_id = '5'};
    kumi::for_each_field(
      [](kumi::str name, auto& m) {
        if (name.as<std::string_view>().ends_with("g")) m++;
        else m--;
      },
      it);
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<"arg"_id>(t), 2);
  TTS_CONSTEXPR_EQUAL(get<"beg"_id>(t), 3.);
  TTS_CONSTEXPR_EQUAL(get<"crf"_id>(t), 2.4f);
  TTS_CONSTEXPR_EQUAL(get<"deg"_id>(t), '6');

  constexpr auto t2 = []() {
    auto it = kumi::record{"actually"_id = 1, "bike"_id = 2., "what"_id = 3.4f, "delicious"_id = '5'};
    kumi::for_each_field(
      [](kumi::str name, auto& m, auto n) {
        auto s = name.as<std::string_view>();
        if (s.starts_with('a') || s.ends_with('t')) m *= n;
        else m += n;
      },
      it, it);
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<"actually"_id>(t2), 1);
  TTS_CONSTEXPR_EQUAL(get<"bike"_id>(t2), 4.);
  TTS_CONSTEXPR_EQUAL(get<"what"_id>(t2), 11.56f);
  TTS_CONSTEXPR_EQUAL(get<"delicious"_id>(t2), 'j');

  bool was_run = false;
  kumi::for_each_field([&]() { was_run = true; }, kumi::record{});
  TTS_EXPECT_NOT(was_run);
};
