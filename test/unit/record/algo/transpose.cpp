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

  using char_f = kumi::field_capture<"a", char>;
  using short_f = kumi::field_capture<"b", short>;
  using int_f = kumi::field_capture<"c", int>;

  using long_double_f = kumi::field_capture<"d", long double>;
  using double_f = kumi::field_capture<"e", double>;
  using float_f = kumi::field_capture<"f", float>;

  using record1_t = kumi::record<char_f, short_f, int_f>;
  using record2_t = kumi::record<long_double_f, double_f, float_f>;
  using record_t = kumi::record<kumi::field_capture<"g", record1_t>, kumi::field_capture<"h", record2_t>>;

  TTS_TYPE_IS(
    (kumi::result::transpose_t<record_t>),
    (kumi::tuple<kumi::record<char_f, long_double_f>, kumi::record<short_f, double_f>, kumi::record<int_f, float_f>>));
};

TTS_CASE("Check record::transpose behavior")
{
  auto numbers = kumi::record{"a"_f = 1, "b"_f = 2, "c"_f = 3, "d"_f = 4};
  auto letters = kumi::record{"e"_f = 'a', "f"_f = 'b', "g"_f = 'c', "h"_f = 'd'};
  auto ratio = kumi::record{"i"_f = 1.f, "j"_f = 0.1f, "k"_f = 0.01f, "l"_f = 0.001f};

  TTS_EQUAL(kumi::transpose(kumi::record{}), kumi::tuple{});

  TTS_EQUAL(
    (kumi::transpose(kumi::record{"n"_f = numbers, "l"_f = letters, "r"_f = ratio})),
    (kumi::tuple{kumi::record{"a"_f = 1, "e"_f = 'a', "i"_f = 1.f}, kumi::record{"b"_f = 2, "f"_f = 'b', "j"_f = 0.1f},
                 kumi::record{"c"_f = 3, "g"_f = 'c', "k"_f = 0.01f},
                 kumi::record{"d"_f = 4, "h"_f = 'd', "l"_f = 0.001f}}));
};

TTS_CASE("Check record::transpose behavior")
{
  constexpr auto numbers = kumi::record{"a"_f = 1, "b"_f = 2, "c"_f = 3, "d"_f = 4};
  constexpr auto letters = kumi::record{"e"_f = 'a', "f"_f = 'b', "g"_f = 'c', "h"_f = 'd'};
  constexpr auto ratio = kumi::record{"i"_f = 1.f, "j"_f = 0.1f, "k"_f = 0.01f, "l"_f = 0.001f};

  TTS_CONSTEXPR_EQUAL(kumi::transpose(kumi::record{}), kumi::tuple{});

  TTS_CONSTEXPR_EQUAL(
    (kumi::transpose(kumi::record{"n"_f = numbers, "l"_f = letters, "r"_f = ratio})),
    (kumi::tuple{kumi::record{"a"_f = 1, "e"_f = 'a', "i"_f = 1.f}, kumi::record{"b"_f = 2, "f"_f = 'b', "j"_f = 0.1f},
                 kumi::record{"c"_f = 3, "g"_f = 'c', "k"_f = 0.01f},
                 kumi::record{"d"_f = 4, "h"_f = 'd', "l"_f = 0.001f}}));
};
