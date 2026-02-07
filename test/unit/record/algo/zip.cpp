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

TTS_CASE("Check result::zip<record...> behavior")
{
  using char_f = kumi::field<kumi::name<"a">, char>;
  using short_f = kumi::field<kumi::name<"b">, short>;
  using int_f = kumi::field<kumi::name<"c">, int>;

  using ld_f = kumi::field<kumi::name<"d">, long double>;
  using double_f = kumi::field<kumi::name<"e">, double>;
  using float_f = kumi::field<kumi::name<"f">, float>;

  using voidp_f = kumi::field<kumi::name<"g">, void*>;
  using voidpp_f = kumi::field<kumi::name<"h">, void**>;
  using voidppp_f = kumi::field<kumi::name<"i">, void***>;

  using record1_t = kumi::record<char_f, short_f, int_f>;
  using record2_t = kumi::record<ld_f, double_f, float_f>;
  using record3_t = kumi::record<voidp_f, voidpp_f, voidppp_f>;

  TTS_TYPE_IS((kumi::result::zip_t<record1_t, record2_t, record3_t>),
              (kumi::tuple<kumi::record<char_f, ld_f, voidp_f>, kumi::record<short_f, double_f, voidpp_f>,
                           kumi::record<int_f, float_f, voidppp_f>>));
};

TTS_CASE("Check record::zip behavior")
{
  auto numbers = kumi::record{"a"_n = 1, "b"_n = 2, "c"_n = 3, "d"_n = 4};
  auto letters = kumi::record{"e"_n = 'a', "f"_n = 'b', "g"_n = 'c', "h"_n = 'd'};
  auto ratio = kumi::record{"i"_n = 1.f, "j"_n = 0.5f, "k"_n = 0.25, "l"_n = 12.0};

  TTS_EQUAL((kumi::zip(kumi::record{}, kumi::record{})), kumi::tuple{});

  TTS_EQUAL((kumi::zip(numbers, letters)),
            (kumi::tuple{kumi::record{"a"_n = 1, "e"_n = 'a'}, kumi::record{"b"_n = 2, "f"_n = 'b'},
                         kumi::record{"c"_n = 3, "g"_n = 'c'}, kumi::record{"d"_n = 4, "h"_n = 'd'}}));

  TTS_EQUAL((kumi::zip(numbers, letters, ratio)), (kumi::tuple{kumi::record{"a"_n = 1, "e"_n = 'a', "i"_n = 1.0f},
                                                               kumi::record{"b"_n = 2, "f"_n = 'b', "j"_n = 0.5f},
                                                               kumi::record{"c"_n = 3, "g"_n = 'c', "k"_n = 0.25},
                                                               kumi::record{"d"_n = 4, "h"_n = 'd', "l"_n = 12.0}}));
};

TTS_CASE("Check record::zip behavior")
{
  constexpr auto numbers = kumi::record{"a"_n = 1, "b"_n = 2, "c"_n = 3, "d"_n = 4};
  constexpr auto letters = kumi::record{"e"_n = 'a', "f"_n = 'b', "g"_n = 'c', "h"_n = 'd'};
  constexpr auto ratio = kumi::record{"i"_n = 1.f, "j"_n = 0.5f, "k"_n = 0.25, "l"_n = 12.0};

  TTS_CONSTEXPR_EQUAL((kumi::zip(kumi::record{}, kumi::record{})), kumi::tuple{});

  TTS_CONSTEXPR_EQUAL((kumi::zip(numbers, letters)),
                      (kumi::tuple{kumi::record{"a"_n = 1, "e"_n = 'a'}, kumi::record{"b"_n = 2, "f"_n = 'b'},
                                   kumi::record{"c"_n = 3, "g"_n = 'c'}, kumi::record{"d"_n = 4, "h"_n = 'd'}}));

  TTS_CONSTEXPR_EQUAL(
    (kumi::zip(numbers, letters, ratio)),
    (kumi::tuple{kumi::record{"a"_n = 1, "e"_n = 'a', "i"_n = 1.0f}, kumi::record{"b"_n = 2, "f"_n = 'b', "j"_n = 0.5f},
                 kumi::record{"c"_n = 3, "g"_n = 'c', "k"_n = 0.25},
                 kumi::record{"d"_n = 4, "h"_n = 'd', "l"_n = 12.0}}));
};
