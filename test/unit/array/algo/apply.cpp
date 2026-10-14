//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/apply.hpp>
#include <sstream>
#include <tts/tts.hpp>

struct A
{
  void operator()(auto&&...) & {}
};

struct B
{
  void operator()(auto&&) & {}
};

struct C
{
  void f(int) {}

  int x;
};

TTS_CASE("Check apply SFINAE compliance")
{
  A a;
  B b;
  auto t = kumi::make_array(1, 2, 3, 4);

  TTS_EXPECT_COMPILES(a, t, { kumi::apply(a, t); });
  TTS_EXPECT_NOT_COMPILES(b, t, { kumi::apply(b, t); });

  struct F0
  {
    void operator()() && {}
  };

  F0 f0{};
  TTS_EXPECT_COMPILES(f0, { kumi::apply(std::move(f0), kumi::array{}); });
  TTS_EXPECT_NOT_COMPILES(f0, { kumi::apply(f0, kumi::array{}); });

  struct F1
  {
    void operator()() & {}
  };

  F1 f1{};
  TTS_EXPECT_NOT_COMPILES(f1, { kumi::apply(std::move(f1), kumi::array{}); });
  TTS_EXPECT_COMPILES(f1, { kumi::apply(f1, kumi::array{}); });

  struct F2
  {
    void operator()(int&&) {}
  };

  F2 f2{};
  TTS_EXPECT_COMPILES(f2, { kumi::apply(f2, kumi::make_array(2)); });
};

TTS_CASE("Check result::apply<F,Array> behavior")
{
  [[maybe_unused]] auto func = [](auto... m) { return (m + ...); };
  using func_t = decltype(func);
  TTS_TYPE_IS((kumi::result::apply_t<func_t, kumi::array<int, 4>>), int);
};

TTS_CASE("Check apply behavior")
{
  TTS_EQUAL((kumi::apply([]() { return 99; }, kumi::array{})), 99);
  TTS_EQUAL((kumi::apply(
              [](auto... m) {
                std::ostringstream s;
                ((s << m << " "), ...);
                return s.str();
              },
              kumi::array{1, 2, 3})),
            "1 2 3 ");
  auto ref = kumi::array{1, 2, 3};
  TTS_EQUAL((kumi::apply(
              [](auto... m) {
                std::ostringstream s;
                ((s << m << " "), ...);
                return s.str();
              },
              std::move(ref))),
            "1 2 3 ");
};

TTS_CASE("Check apply constexpr behavior")
{
  constexpr auto t1 = []() {
    auto it = kumi::array{1, 2, 3};
    return kumi::apply([](auto... m) { return (m + ...); }, it);
  }();
  constexpr auto empty = []() { return 99; };
  TTS_CONSTEXPR_EQUAL((kumi::apply(empty, kumi::array{})), 99);
  TTS_CONSTEXPR_EQUAL(t1, 6);
};
