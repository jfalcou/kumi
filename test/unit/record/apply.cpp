//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <sstream>
#include <tts/tts.hpp>

struct A { void operator()(auto&&...) & {} };
struct B { void operator()(auto&&) & {} };
struct C { void f(int){} int x; };

TTS_CASE("Check result::apply<F,Record> behavior")
{
  using namespace kumi::literals;
 
  auto lambda = [](auto... m) { return (m + ...); };
  using func_t = decltype(lambda);

  using char_f      = kumi::field_capture<"x", char>;
  using short_f     = kumi::field_capture<"y", short>;
  using int_f       = kumi::field_capture<"z", int>;
  using double_f    = kumi::field_capture<"t", double>;
  TTS_TYPE_IS((kumi::result::apply_t<func_t,kumi::record<char_f,short_f,int_f,double_f>>), double);
};

TTS_CASE("Check apply behavior")
{
  using namespace kumi::literals;

  TTS_EQUAL((kumi::apply( []() { return 99; }, kumi::record{})), 99);

  TTS_EQUAL((kumi::apply(
                [](auto... m) {
                  std::ostringstream s;
                  ((s << m << " "), ...);
                  return s.str();
                },
                kumi::record {"a"_f = 1, "b"_f = '5', "c"_f = "things"})),
            "1 5 things ");

  kumi::record some_record {"a"_f = 1, "b"_f = '5', "c"_f = "things"};

  TTS_EQUAL((some_record.values()([](auto... m) {
              std::ostringstream s;
              ((s << m << " "), ...);
              return s.str();
            })),
            "1 5 things ");
};

TTS_CASE("Check apply constexpr behavior")
{
  using namespace kumi::literals;

  constexpr auto t1 = []() {
    auto it = kumi::record {"x"_f = 1, "y"_f = 2., "z"_f = 3.f};
    return kumi::apply([](auto... m) { return (m + ...); }, it);
  }();

  constexpr auto t2 = []() {
    auto it = kumi::record {"x"_f = 1, "y"_f = 2., "z"_f = 3.f};
    return it.values()([](auto... m) { return (m + ...); });
  }();
  constexpr auto empty = []() { return 99; };
  TTS_CONSTEXPR_EQUAL((kumi::apply( empty, kumi::record{})), 99);

  TTS_CONSTEXPR_EQUAL(t1, 6.);
  TTS_CONSTEXPR_EQUAL(t2, 6.);
};
