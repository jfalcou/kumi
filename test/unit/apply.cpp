//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/kumi.hpp>
#include <sstream>
#include <tts/tts.hpp>

struct A { void operator()(auto&&...) & {} };
struct B { void operator()(auto&&) & {} };
struct C { void f(int){} int x; };

TTS_CASE("Check apply SFINAE compliance")
{
  A a;
  B b;
  C c;
  auto t = kumi::make_tuple(1,2,3,4);
  auto u0 = kumi::make_tuple(std::ref(c), 1);
  kumi::tuple<std::reference_wrapper<C>, int> u1{c,1};
  kumi::tuple<C *, int> u2{&c,2};
  auto u3 = kumi::make_tuple(std::ref(c));
  kumi::tuple<std::reference_wrapper<C>> u4{c};
  auto u5 = kumi::make_tuple(&c);

  TTS_EXPECT_COMPILES(a, t, { kumi::apply(a, t); } );
  TTS_EXPECT_NOT_COMPILES(b, t, { kumi::apply(b, t); } );
  TTS_EXPECT_COMPILES(u0, { kumi::apply(&C::f, u0); } );
  TTS_EXPECT_COMPILES(u1, { kumi::apply(&C::f, u1); } );
  TTS_EXPECT_COMPILES(u2, { kumi::apply(&C::f, u2); } );
  TTS_EXPECT_COMPILES(u3, { kumi::apply(&C::x, u3); } );
  TTS_EXPECT_COMPILES(u4, { kumi::apply(&C::x, u4); } );
  TTS_EXPECT_COMPILES(u5, { kumi::apply(&C::x, u5); } );

  struct F0{
    void operator()() && {}
  };
  F0 f0{};
  TTS_EXPECT_COMPILES(f0, { kumi::apply(std::move(f0), kumi::tuple{}); });
  TTS_EXPECT_NOT_COMPILES(f0, { kumi::apply(f0, kumi::tuple{}); });
  TTS_EXPECT_NOT_COMPILES(f0, { kumi::apply(std::ref(f0), kumi::tuple{}); });
  struct F1{
    void operator()() & {}
  };
  F1 f1{};
  TTS_EXPECT_NOT_COMPILES(f1, { kumi::apply(std::move(f1), kumi::tuple{}); });
  TTS_EXPECT_COMPILES(f1, { kumi::apply(f1, kumi::tuple{}); });
  TTS_EXPECT_COMPILES(f1, { kumi::apply(std::ref(f1), kumi::tuple{}); });

  struct F2{
    void operator()(int &&){}
  };
  F2 f2{};
  TTS_EXPECT_COMPILES(f2, { kumi::apply(f2, kumi::make_tuple(2)); });
  int i2 = 2;
  TTS_EXPECT_NOT_COMPILES(f2, i2, { kumi::apply(f2, kumi::forward_as_tuple(i2)); });
  TTS_EXPECT_COMPILES(f2, i2, { kumi::apply(f2, kumi::forward_as_tuple(std::move(i2))); });
  auto t2 = kumi::forward_as_tuple(std::move(i2));
  TTS_EXPECT_NOT_COMPILES(f2, t2, { kumi::apply(f2, t2); });
};

TTS_CASE("Check result::apply<F,Tuple> behavior")
{
  auto lambda = [](auto... m) { return (m + ...); };
  using func_t = decltype(lambda);

  TTS_TYPE_IS((kumi::result::apply_t<func_t,kumi::tuple<char,short,int,double>>), double);
};

TTS_CASE("Check apply behavior")
{
  TTS_EQUAL((kumi::apply( []() { return 99; }, kumi::tuple{})), 99);

  TTS_EQUAL((kumi::apply(
                [](auto... m) {
                  std::ostringstream s;
                  ((s << m << " "), ...);
                  return s.str();
                },
                kumi::tuple {1, '5', "things"})),
            "1 5 things ");

  auto ref = kumi::tuple {1, '5', "things"};
  TTS_EQUAL((kumi::apply(
                [](auto... m) {
                  std::ostringstream s;
                  ((s << m << " "), ...);
                  return s.str();
                },
                std::move(ref))),
            "1 5 things ");
};

TTS_CASE("Check apply constexpr behavior")
{
  constexpr auto t1 = []() {
    auto it = kumi::tuple {1, 2., 3.f};
    return kumi::apply([](auto... m) { return (m + ...); }, it);
  }();

  constexpr auto empty = []() { return 99; };
  TTS_CONSTEXPR_EQUAL((kumi::apply( empty, kumi::tuple{})), 99);

  TTS_CONSTEXPR_EQUAL(t1, 6.);
};
