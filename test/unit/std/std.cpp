//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/kumi.hpp>
#include <functional>
#include <tts/tts.hpp>

TTS_CASE("Check kumi::field with std::reference_wrapper")
{
  using namespace kumi::literals;

  int x = 1;

  auto c = "x"_id = std::ref(x);
  auto d = "x"_id = std::cref(x);

  TTS_TYPE_IS((decltype(c.value)), int&);
  TTS_TYPE_IS((decltype(d.value)), int const&);

  c.value++;
  TTS_EQUAL(c.value, 2);
  TTS_EQUAL(d.value, 2);
};

TTS_CASE("Check kumi::tuple construction")
{
  float const f{};
  double d;
  std::reference_wrapper<float const> rf = f;
  std::reference_wrapper<double> rd = d;

  auto t = kumi::make_tuple(rf, rd);
  auto lref = kumi::to_ref(t);
  auto rref = kumi::to_ref(std::move(t));
  auto cref = kumi::to_ref(std::as_const(t));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(t)>), float const&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(t)>), double&);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(lref)>), float const&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(lref)>), double&);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(rref)>), float const&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(rref)>), double&);

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(cref)>), float const&);
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(cref)>), double&);
};

TTS_CASE("Check kumi::record construction")
{
  using namespace kumi::literals;

  float const f{};
  double d;

  std::reference_wrapper<float const> rf = f;
  std::reference_wrapper<double> rd = d;

  auto r = kumi::make_record("d"_id = rf, "e"_id = rd);
  auto lref = kumi::to_ref(r);
  auto rref = kumi::to_ref(std::move(r));
  auto cref = kumi::to_ref(std::as_const(r));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(r)>), (kumi::field<kumi::name<"d">, float const&>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(r)>), (kumi::field<kumi::name<"e">, double&>));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(lref)>), (kumi::field<kumi::name<"d">, float const&>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(lref)>), (kumi::field<kumi::name<"e">, double&>));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(rref)>), (kumi::field<kumi::name<"d">, float const&>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(rref)>), (kumi::field<kumi::name<"e">, double&>));

  TTS_TYPE_IS((std::tuple_element_t<0, decltype(cref)>), (kumi::field<kumi::name<"d">, float const&>));
  TTS_TYPE_IS((std::tuple_element_t<1, decltype(cref)>), (kumi::field<kumi::name<"e">, double&>));
};

TTS_CASE("Check kumi::apply edge cases with std::ref")
{
  struct C
  {
    void f(int) {}

    int x;
  };

  struct F0
  {
    void operator()() && {}
  };

  struct F1
  {
    void operator()() & {}
  };

  C c;
  F0 f0;
  F1 f1;

  auto u0 = kumi::make_tuple(std::ref(c), 1);
  kumi::tuple<std::reference_wrapper<C>, int> u1{c, 1};
  auto u3 = kumi::make_tuple(std::ref(c));
  kumi::tuple<std::reference_wrapper<C>> u4{c};

  TTS_EXPECT_COMPILES(u0, { kumi::apply(&C::f, u0); });
  TTS_EXPECT_COMPILES(u1, { kumi::apply(&C::f, u1); });
  TTS_EXPECT_COMPILES(u3, { kumi::apply(&C::x, u3); });
  TTS_EXPECT_COMPILES(u4, { kumi::apply(&C::x, u4); });

  TTS_EXPECT_NOT_COMPILES(f0, { kumi::apply(std::ref(f0), kumi::tuple{}); });
  TTS_EXPECT_COMPILES(f1, { kumi::apply(std::ref(f1), kumi::tuple{}); });
};
