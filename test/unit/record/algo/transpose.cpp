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
  auto numbers = kumi::record{"a"_id = 1, "b"_id = 2, "c"_id = 3, "d"_id = 4};
  auto letters = kumi::record{"e"_id = 'a', "f"_id = 'b', "g"_id = 'c', "h"_id = 'd'};
  auto ratio = kumi::record{"i"_id = 1.f, "j"_id = 0.1f, "k"_id = 0.01f, "l"_id = 0.001f};

  TTS_EQUAL(kumi::transpose(kumi::record{}), kumi::tuple{});

  TTS_EQUAL((kumi::transpose(kumi::record{"n"_id = numbers, "l"_id = letters, "r"_id = ratio})),
            (kumi::tuple{kumi::record{"a"_id = 1, "e"_id = 'a', "i"_id = 1.f},
                         kumi::record{"b"_id = 2, "f"_id = 'b', "j"_id = 0.1f},
                         kumi::record{"c"_id = 3, "g"_id = 'c', "k"_id = 0.01f},
                         kumi::record{"d"_id = 4, "h"_id = 'd', "l"_id = 0.001f}}));
};

TTS_CASE("Check record::transpose behavior")
{
  constexpr auto numbers = kumi::record{"a"_id = 1, "b"_id = 2, "c"_id = 3, "d"_id = 4};
  constexpr auto letters = kumi::record{"e"_id = 'a', "f"_id = 'b', "g"_id = 'c', "h"_id = 'd'};
  constexpr auto ratio = kumi::record{"i"_id = 1.f, "j"_id = 0.1f, "k"_id = 0.01f, "l"_id = 0.001f};

  TTS_CONSTEXPR_EQUAL(kumi::transpose(kumi::record{}), kumi::tuple{});

  TTS_CONSTEXPR_EQUAL((kumi::transpose(kumi::record{"n"_id = numbers, "l"_id = letters, "r"_id = ratio})),
                      (kumi::tuple{kumi::record{"a"_id = 1, "e"_id = 'a', "i"_id = 1.f},
                                   kumi::record{"b"_id = 2, "f"_id = 'b', "j"_id = 0.1f},
                                   kumi::record{"c"_id = 3, "g"_id = 'c', "k"_id = 0.01f},
                                   kumi::record{"d"_id = 4, "h"_id = 'd', "l"_id = 0.001f}}));
};
