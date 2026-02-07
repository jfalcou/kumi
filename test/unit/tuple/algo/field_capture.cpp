//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/tuple.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include <functional>

TTS_CASE("Check field type coherence")
{
  int x = 1;

  auto a = kumi::field<kumi::name<"x">, int>{x};
  auto b = kumi::field<kumi::name<"x">, int const>{x};
  auto c = kumi::field<kumi::name<"x">, int&>{x};
  auto d = kumi::field<kumi::name<"x">, int const&>{x};
  auto e = kumi::field<kumi::name<"x">, int&&>{std::move(x)};

  TTS_TYPE_IS((decltype(a.value)), int);
  TTS_TYPE_IS((decltype(b.value)), int const);
  TTS_TYPE_IS((decltype(c.value)), int&);
  TTS_TYPE_IS((decltype(d.value)), int const&);
  TTS_TYPE_IS((decltype(e.value)), int&&);

  c.value++;
  TTS_EQUAL(a.value, 1);
  TTS_EQUAL(b.value, 1);
  TTS_EQUAL(c.value, 2);
  TTS_EQUAL(d.value, 2);
  TTS_EQUAL(e.value, 2);
  TTS_EQUAL(x, 2);
};

TTS_CASE("Check field type coherence through field_name")
{
  using namespace kumi::literals;

  int x = 1;
  int const y = 1;

  auto a = "x"_n = x;
  auto b = "x"_n = y;
  auto c = "x"_n = std::ref(x);
  auto d = "x"_n = std::cref(x);
  auto e = "x"_n = std::move(x);

  TTS_TYPE_IS((decltype(a.value)), int);
  TTS_TYPE_IS((decltype(b.value)), int);
  TTS_TYPE_IS((decltype(c.value)), int&);
  TTS_TYPE_IS((decltype(d.value)), int const&);
  TTS_TYPE_IS((decltype(e.value)), int);

  c.value++;
  TTS_EQUAL(a.value, 1);
  TTS_EQUAL(b.value, 1);
  TTS_EQUAL(c.value, 2);
  TTS_EQUAL(d.value, 2);
  TTS_EQUAL(e.value, 1);
  TTS_EQUAL(x, 2);
};

TTS_CASE("Check kumi::tuple behavior with fields")
{
  using namespace kumi::literals;

  int x = 1;
  int const y = 2;
  int&& z = std::move(x);

  using f = kumi::field<kumi::name<"a">, int>;
  using fc = kumi::field<kumi::name<"b">, int>;
  using fref = kumi::field<kumi::name<"c">, int&>;
  using fcref = kumi::field<kumi::name<"d">, int const&>;
  using furef = kumi::field<kumi::name<"e">, int>;

  using tpl = kumi::tuple<f, fc, fref, fcref, furef>;

  auto t = kumi::tuple{"a"_n = x, "b"_n = y, "c"_n = std::ref(x), "d"_n = std::cref(y), "e"_n = z};
  auto nl = kumi::tuple{"a"_n, "b"_n, "c"_n, "d"_n, "e"_n};

  auto pt = kumi::tuple{"a"_n = x, y, std::ref(x), "d"_n = std::cref(y), z};
  auto ptnl = kumi::tuple{"a"_n, kumi::none, kumi::none, "d"_n, kumi::none};

  constexpr auto dup = kumi::tuple{"a"_n = 3, "a"_n = 8};
  constexpr auto uni = kumi::tuple{"a"_n = 3, "b"_n = 8};

  TTS_TYPE_IS(tpl, decltype(t));
  TTS_TYPE_IS(decltype(t.names()), decltype(nl));
  TTS_TYPE_IS(decltype(pt.names()), decltype(ptnl));

  TTS_EQUAL(t.names(), nl);
  TTS_EQUAL(pt.names(), ptnl);

  TTS_EXPECT_NOT_COMPILES(dup, { get<"a"_n>(dup); });
  TTS_EXPECT_COMPILES(uni, { get<"a"_n>(uni); });
};
