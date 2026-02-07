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
  auto numbers = kumi::record{"a"_id = 1, "b"_id = 2, "c"_id = 3, "d"_id = 4};
  auto letters = kumi::record{"e"_id = 'a', "f"_id = 'b', "g"_id = 'c', "h"_id = 'd'};
  auto ratio = kumi::record{"i"_id = 1.f, "j"_id = 0.5f, "k"_id = 0.25, "l"_id = 12.0};

  TTS_EQUAL((kumi::zip(kumi::record{}, kumi::record{})), kumi::tuple{});

  TTS_EQUAL((kumi::zip(numbers, letters)),
            (kumi::tuple{kumi::record{"a"_id = 1, "e"_id = 'a'}, kumi::record{"b"_id = 2, "f"_id = 'b'},
                         kumi::record{"c"_id = 3, "g"_id = 'c'}, kumi::record{"d"_id = 4, "h"_id = 'd'}}));

  TTS_EQUAL((kumi::zip(numbers, letters, ratio)), (kumi::tuple{kumi::record{"a"_id = 1, "e"_id = 'a', "i"_id = 1.0f},
                                                               kumi::record{"b"_id = 2, "f"_id = 'b', "j"_id = 0.5f},
                                                               kumi::record{"c"_id = 3, "g"_id = 'c', "k"_id = 0.25},
                                                               kumi::record{"d"_id = 4, "h"_id = 'd', "l"_id = 12.0}}));
};

TTS_CASE("Check record::zip behavior")
{
  constexpr auto numbers = kumi::record{"a"_id = 1, "b"_id = 2, "c"_id = 3, "d"_id = 4};
  constexpr auto letters = kumi::record{"e"_id = 'a', "f"_id = 'b', "g"_id = 'c', "h"_id = 'd'};
  constexpr auto ratio = kumi::record{"i"_id = 1.f, "j"_id = 0.5f, "k"_id = 0.25, "l"_id = 12.0};

  TTS_CONSTEXPR_EQUAL((kumi::zip(kumi::record{}, kumi::record{})), kumi::tuple{});

  TTS_CONSTEXPR_EQUAL((kumi::zip(numbers, letters)),
                      (kumi::tuple{kumi::record{"a"_id = 1, "e"_id = 'a'}, kumi::record{"b"_id = 2, "f"_id = 'b'},
                                   kumi::record{"c"_id = 3, "g"_id = 'c'}, kumi::record{"d"_id = 4, "h"_id = 'd'}}));

  TTS_CONSTEXPR_EQUAL((kumi::zip(numbers, letters, ratio)),
                      (kumi::tuple{kumi::record{"a"_id = 1, "e"_id = 'a', "i"_id = 1.0f},
                                   kumi::record{"b"_id = 2, "f"_id = 'b', "j"_id = 0.5f},
                                   kumi::record{"c"_id = 3, "g"_id = 'c', "k"_id = 0.25},
                                   kumi::record{"d"_id = 4, "h"_id = 'd', "l"_id = 12.0}}));
};
