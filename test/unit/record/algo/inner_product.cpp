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
#include <tts/tts.hpp>

TTS_CASE("Check result::inner_product_t behavior")
{
  using namespace kumi::literals;

  auto sum = [](auto a, auto b) { return sizeof(a) + sizeof(b); };
  auto prod = [](auto a, auto b) { return a * b; };
  using sfunc_t = decltype(sum);
  using pfunc_t = decltype(prod);

  using int_f = kumi::field<kumi::name<"a">, int>;
  using double_f = kumi::field<kumi::name<"b">, double>;
  using char_f = kumi::field<kumi::name<"a">, char>;
  using short_f = kumi::field<kumi::name<"b">, short>;

  TTS_TYPE_IS((kumi::result::inner_product_t<kumi::record<int_f, double_f>, kumi::record<char_f, short_f>, int>),
              double);

  TTS_TYPE_IS((kumi::result::inner_product_t<kumi::record<int_f, double_f>, kumi::record<char_f, short_f>, int, sfunc_t,
                                             pfunc_t>),
              std::size_t);
};

TTS_CASE("Check tuple::inner_product behavior")
{
  using namespace kumi::literals;

  auto t1 = kumi::record{"a"_n = 2, "b"_n = 4, "c"_n = 8};
  auto t2 = kumi::record{"a"_n = 2.5, "b"_n = 4.5, "c"_n = 7.5};

  TTS_EQUAL(kumi::inner_product(t1, t2, 0.f), 83);
  TTS_EQUAL(kumi::inner_product(
              t1, t2, 1ULL, [](auto a, auto b) { return a * b; }, [](auto a, auto b) { return a + b; }),
            592.875);
};

TTS_CASE("Check tuple::inner_product constexpr behavior")
{
  using namespace kumi::literals;

  TTS_CONSTEXPR_EQUAL(kumi::inner_product(kumi::record{"a"_n = 2, "b"_n = 4, "c"_n = 8},
                                          kumi::record{"a"_n = 2.5, "b"_n = 4.5, "c"_n = 7.5}, 0.f),
                      83);
  TTS_CONSTEXPR_EQUAL(kumi::inner_product(
                        kumi::record{"a"_n = 2, "b"_n = 4, "c"_n = 8},
                        kumi::record{"a"_n = 2.5, "b"_n = 4.5, "c"_n = 7.5}, 1ULL, [](auto a, auto b) { return a * b; },
                        [](auto a, auto b) { return a + b; }),
                      592.875);
};
