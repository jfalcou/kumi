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

  kumi::tuple some_tuple {1, '5', "things"};

  TTS_EQUAL((some_tuple([](auto... m) {
              std::ostringstream s;
              ((s << m << " "), ...);
              return s.str();
            })),
            "1 5 things ");
};

TTS_CASE("Check apply constexpr behavior")
{
  constexpr auto t1 = []() {
    auto it = kumi::tuple {1, 2., 3.f};
    return kumi::apply([](auto... m) { return (m + ...); }, it);
  }();

  constexpr auto t2 = []() {
    auto it = kumi::tuple {1, 2., 3.f};
    return it([](auto... m) { return (m + ...); });
  }();

  constexpr auto empty = []() { return 99; };
  TTS_CONSTEXPR_EQUAL((kumi::apply( empty, kumi::tuple{})), 99);

  TTS_CONSTEXPR_EQUAL(t1, 6.);
  TTS_CONSTEXPR_EQUAL(t2, 6.);
};
