//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include <vector>

using namespace kumi::literals;

TTS_CASE("Check result::transpose<record> behavior")
{

  using char_f = kumi::field<kumi::name<"a">, char>;
  using short_f = kumi::field<kumi::name<"b">, short>;
  using int_f = kumi::field<kumi::name<"c">, int>;

  using long_double_f = kumi::field<kumi::name<"d">, long double>;
  using double_f = kumi::field<kumi::name<"e">, double>;
  using float_f = kumi::field<kumi::name<"f">, float>;

  using record1_t = kumi::record<char_f, short_f, int_f>;
  using record2_t = kumi::record<long_double_f, double_f, float_f>;
  using record_t = kumi::record<kumi::field<kumi::name<"g">, record1_t>, kumi::field<kumi::name<"h">, record2_t>>;

  TTS_TYPE_IS(
    (kumi::result::transpose_t<record_t>),
    (kumi::tuple<kumi::record<char_f, long_double_f>, kumi::record<short_f, double_f>, kumi::record<int_f, float_f>>));
};

TTS_CASE("Check record::transpose behavior")
{
  auto numbers = kumi::record{"a"_n = 1, "b"_n = 2, "c"_n = 3, "d"_n = 4};
  auto letters = kumi::record{"e"_n = 'a', "f"_n = 'b', "g"_n = 'c', "h"_n = 'd'};
  auto ratio = kumi::record{"i"_n = 1.f, "j"_n = 0.1f, "k"_n = 0.01f, "l"_n = 0.001f};

  TTS_EQUAL(kumi::transpose(kumi::record{}), kumi::tuple{});

  TTS_EQUAL(
    (kumi::transpose(kumi::record{"n"_n = numbers, "l"_n = letters, "r"_n = ratio})),
    (kumi::tuple{kumi::record{"a"_n = 1, "e"_n = 'a', "i"_n = 1.f}, kumi::record{"b"_n = 2, "f"_n = 'b', "j"_n = 0.1f},
                 kumi::record{"c"_n = 3, "g"_n = 'c', "k"_n = 0.01f},
                 kumi::record{"d"_n = 4, "h"_n = 'd', "l"_n = 0.001f}}));
};

TTS_CASE("Check record::transpose behavior")
{
  constexpr auto numbers = kumi::record{"a"_n = 1, "b"_n = 2, "c"_n = 3, "d"_n = 4};
  constexpr auto letters = kumi::record{"e"_n = 'a', "f"_n = 'b', "g"_n = 'c', "h"_n = 'd'};
  constexpr auto ratio = kumi::record{"i"_n = 1.f, "j"_n = 0.1f, "k"_n = 0.01f, "l"_n = 0.001f};

  TTS_CONSTEXPR_EQUAL(kumi::transpose(kumi::record{}), kumi::tuple{});

  TTS_CONSTEXPR_EQUAL(
    (kumi::transpose(kumi::record{"n"_n = numbers, "l"_n = letters, "r"_n = ratio})),
    (kumi::tuple{kumi::record{"a"_n = 1, "e"_n = 'a', "i"_n = 1.f}, kumi::record{"b"_n = 2, "f"_n = 'b', "j"_n = 0.1f},
                 kumi::record{"c"_n = 3, "g"_n = 'c', "k"_n = 0.01f},
                 kumi::record{"d"_n = 4, "h"_n = 'd', "l"_n = 0.001f}}));
};
