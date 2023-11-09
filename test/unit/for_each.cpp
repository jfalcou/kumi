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

struct A { void operator()(auto&&) & {} };
struct B { void operator()(auto&&) && {} };

TTS_CASE("Check for_each SFINAE compliance")
{
  A a;
  B b;
  auto t = kumi::make_tuple(1,2);

  TTS_EXPECT_COMPILES(a, t, { kumi::for_each(a, t); } );
  TTS_EXPECT_NOT_COMPILES(b, t, { kumi::for_each(b, t); } );
};


TTS_CASE("Check for_each behavior")
{
  auto t = kumi::tuple {1, 2., 3.4f, '5'};
  kumi::for_each([](auto &m) { m++; }, t);

  TTS_EQUAL(get<0>(t), 2);
  TTS_EQUAL(get<1>(t), 3.);
  TTS_EQUAL(get<2>(t), 4.4f);
  TTS_EQUAL(get<3>(t), '6');

  kumi::for_each([](auto &m, auto n) { m *= n; }, t, t);

  TTS_EQUAL(get<0>(t), 4);
  TTS_EQUAL(get<1>(t), 9.);
  TTS_EQUAL(get<2>(t), 19.36f);
  TTS_EQUAL(get<3>(t), 'd');

  bool was_run = false;
  kumi::for_each([&]() { was_run = true; }, kumi::tuple{});
  TTS_EXPECT_NOT(was_run);
};

TTS_CASE("Check for_each constexpr behavior")
{
  constexpr auto t = []() {
    auto it = kumi::tuple {1, 2., 3.4f, '5'};
    kumi::for_each([](auto &m) { m++; }, it);
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<0>(t), 2);
  TTS_CONSTEXPR_EQUAL(get<1>(t), 3.);
  TTS_CONSTEXPR_EQUAL(get<2>(t), 4.4f);
  TTS_CONSTEXPR_EQUAL(get<3>(t), '6');

  constexpr auto t2 = []() {
    auto it = kumi::tuple {1, 2., 3.4f, char(8)};
    kumi::for_each([](auto &m, auto n) { m *= n; }, it, it);
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<0>(t2), 1);
  TTS_CONSTEXPR_EQUAL(get<1>(t2), 4.);
  TTS_CONSTEXPR_EQUAL(get<2>(t2), 11.56f);
  TTS_CONSTEXPR_EQUAL(get<3>(t2), '@');
};

TTS_CASE("Check for_each_index behavior")
{
  auto t = kumi::tuple {1, 2., 3.4f, '5'};
  kumi::for_each_index(
      [](auto i, auto &m) {
        if constexpr( i % 2 == 0 )
          m++;
        else
          m--;
      },
      t);

  TTS_EQUAL(get<0>(t), 2);
  TTS_EQUAL(get<1>(t), 1.);
  TTS_EQUAL(get<2>(t), 4.4f);
  TTS_EQUAL(get<3>(t), '4');

  kumi::for_each_index(
      [](auto i, auto &m, auto n) {
        if constexpr( i % 2 == 0 )
          m *= n;
        else
          m += n;
      },
      t, t);

  TTS_EQUAL(get<0>(t), 4);
  TTS_EQUAL(get<1>(t), 2.);
  TTS_EQUAL(get<2>(t), 19.36f);
  TTS_EQUAL(get<3>(t), 'h');
};

TTS_CASE("Check for_each_index constexpr behavior")
{
  constexpr auto t = []() {
    auto it = kumi::tuple {1, 2., 3.4f, '5'};
    kumi::for_each_index(
        [](auto i, auto &m) {
          if constexpr( i % 2 == 0 )
            m++;
          else
            m--;
        },
        it);
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<0>(t), 2);
  TTS_CONSTEXPR_EQUAL(get<1>(t), 1.);
  TTS_CONSTEXPR_EQUAL(get<2>(t), 4.4f);
  TTS_CONSTEXPR_EQUAL(get<3>(t), '4');

  constexpr auto t2 = []() {
    auto it = kumi::tuple {1, 2., 3.4f, '5'};
    kumi::for_each_index(
        [](auto i, auto &m, auto n) {
          if constexpr( i % 2 == 0 )
            m *= n;
          else
            m +=n;
        },
        it, it);
    return it;
  }();

  TTS_CONSTEXPR_EQUAL(get<0>(t2), 1);
  TTS_CONSTEXPR_EQUAL(get<1>(t2), 4.);
  TTS_CONSTEXPR_EQUAL(get<2>(t2), 11.56f);
  TTS_CONSTEXPR_EQUAL(get<3>(t2), 'j');

  bool was_run = false;
  kumi::for_each_index([&]() { was_run = true; }, kumi::tuple{});
  TTS_EXPECT_NOT(was_run);
};
