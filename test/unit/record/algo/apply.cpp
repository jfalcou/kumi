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
#include <sstream>
#include <tts/tts.hpp>

using namespace kumi::literals;

TTS_CASE("Check result::apply<F,Record> behavior")
{
  auto lambda = [](auto... m) { return (m + ...); };
  using func_t = decltype(lambda);

  using char_f = kumi::field<kumi::name<"x">, char>;
  using short_f = kumi::field<kumi::name<"y">, short>;
  using int_f = kumi::field<kumi::name<"z">, int>;
  using double_f = kumi::field<kumi::name<"t">, double>;
  TTS_TYPE_IS((kumi::result::apply_t<func_t, kumi::record<char_f, short_f, int_f, double_f>>), double);
};

TTS_CASE("Check apply behavior")
{
  TTS_EQUAL((kumi::apply([]() { return 99; }, kumi::record{})), 99);

  TTS_EQUAL((kumi::apply(
              [](auto... m) {
                std::ostringstream s;
                ((s << m << " "), ...);
                return s.str();
              },
              kumi::record{"a"_n = 1, "b"_n = '5', "c"_n = "things"})),
            "1 5 things ");
};

TTS_CASE("Check apply constexpr behavior")
{
  using namespace kumi::literals;

  constexpr auto t1 = []() {
    auto it = kumi::record{"x"_n = 1, "y"_n = 2., "z"_n = 3.f};
    return kumi::apply([](auto... m) { return (m + ...); }, it);
  }();

  constexpr auto empty = []() { return 99; };
  TTS_CONSTEXPR_EQUAL((kumi::apply(empty, kumi::record{})), 99);

  TTS_CONSTEXPR_EQUAL(t1, 6.);
};
