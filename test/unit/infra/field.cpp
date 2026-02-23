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

  auto a = "x"_id = x;
  auto b = "x"_id = y;
  auto c = "x"_id = std::ref(x);
  auto d = "x"_id = std::cref(x);
  auto e = "x"_id = std::move(x);

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

  auto t = kumi::tuple{"a"_id = x, "b"_id = y, "c"_id = std::ref(x), "d"_id = std::cref(y), "e"_id = z};
  auto nl = kumi::tuple{"a"_id, "b"_id, "c"_id, "d"_id, "e"_id};

  auto pt = kumi::tuple{"a"_id = x, y, std::ref(x), "d"_id = std::cref(y), z};
  auto ptnl = kumi::tuple{"a"_id, kumi::unknown{}, kumi::unknown{}, "d"_id, kumi::unknown{}};

  constexpr auto dup = kumi::tuple{"a"_id = 3, "a"_id = 8};
  constexpr auto uni = kumi::tuple{"a"_id = 3, "b"_id = 8};

  TTS_TYPE_IS(tpl, decltype(t));
  TTS_TYPE_IS(decltype(t.names()), decltype(nl));
  TTS_TYPE_IS(decltype(pt.names()), decltype(ptnl));

  TTS_EQUAL(t.names(), nl);
  TTS_EQUAL(pt.names(), ptnl);

  TTS_EXPECT_NOT_COMPILES(dup, { get<"a"_id>(dup); });
  TTS_EXPECT_COMPILES(uni, { get<"a"_id>(uni); });
};
