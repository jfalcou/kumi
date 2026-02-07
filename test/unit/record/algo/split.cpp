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

TTS_CASE("Check result::split<Record,I> behavior")
{
  using namespace kumi::literals;

  using char_f = kumi::field<kumi::name<"a">, char>;
  using short_f = kumi::field<kumi::name<"b">, short>;
  using int_f = kumi::field<kumi::name<"c">, int>;
  using double_f = kumi::field<kumi::name<"d">, double>;

  TTS_TYPE_IS((kumi::result::split_t<kumi::record<char_f, short_f, int_f, double_f>, 0>),
              (kumi::tuple<kumi::record<>, kumi::record<char_f, short_f, int_f, double_f>>));

  TTS_TYPE_IS((kumi::result::split_t<kumi::record<char_f, short_f, int_f, double_f>, 1>),
              (kumi::tuple<kumi::record<char_f>, kumi::record<short_f, int_f, double_f>>));

  TTS_TYPE_IS((kumi::result::split_t<kumi::record<char_f, short_f, int_f, double_f>, 2>),
              (kumi::tuple<kumi::record<char_f, short_f>, kumi::record<int_f, double_f>>));

  TTS_TYPE_IS((kumi::result::split_t<kumi::record<char_f, short_f, int_f, double_f>, 3>),
              (kumi::tuple<kumi::record<char_f, short_f, int_f>, kumi::record<double_f>>));

  TTS_TYPE_IS((kumi::result::split_t<kumi::record<char_f, short_f, int_f, double_f>, 4>),
              (kumi::tuple<kumi::record<char_f, short_f, int_f, double_f>, kumi::record<>>));
};

TTS_CASE("Check record::split behavior")
{
  using namespace kumi::literals;

  kumi::record t = {"a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = 4, "e"_n = 5, "f"_n = 6.f, "g"_n = 7., "h"_n = '8'};

  auto [s00, s01] = kumi::split(t, 0_c);
  TTS_EQUAL(s00, kumi::record{});
  TTS_EQUAL(s01, t);

  auto [s10, s11] = kumi::split(t, 1_c);
  TTS_EQUAL(s10, (kumi::record{"a"_n = '1'}));
  TTS_EQUAL(s11, (kumi::record{"b"_n = 2., "c"_n = 3.f, "d"_n = 4, "e"_n = 5, "f"_n = 6.f, "g"_n = 7., "h"_n = '8'}));

  auto [s20, s21] = kumi::split(t, 2_c);
  TTS_EQUAL(s20, (kumi::record{"a"_n = '1', "b"_n = 2.}));
  TTS_EQUAL(s21, (kumi::record{"c"_n = 3.f, "d"_n = 4, "e"_n = 5, "f"_n = 6.f, "g"_n = 7., "h"_n = '8'}));

  auto [s30, s31] = kumi::split(t, 3_c);
  TTS_EQUAL(s30, (kumi::record{"a"_n = '1', "b"_n = 2., "c"_n = 3.f}));
  TTS_EQUAL(s31, (kumi::record{"d"_n = 4, "e"_n = 5, "f"_n = 6.f, "g"_n = 7., "h"_n = '8'}));

  auto [s40, s41] = kumi::split(t, 4_c);
  TTS_EQUAL(s40, (kumi::record{"a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = 4}));
  TTS_EQUAL(s41, (kumi::record{"e"_n = 5, "f"_n = 6.f, "g"_n = 7., "h"_n = '8'}));

  auto [s50, s51] = kumi::split(t, 5_c);
  TTS_EQUAL(s50, (kumi::record{"a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = 4, "e"_n = 5}));
  TTS_EQUAL(s51, (kumi::record{"f"_n = 6.f, "g"_n = 7., "h"_n = '8'}));

  auto [s60, s61] = kumi::split(t, 6_c);
  TTS_EQUAL(s60, (kumi::record{"a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = 4, "e"_n = 5, "f"_n = 6.f}));
  TTS_EQUAL(s61, (kumi::record{"g"_n = 7., "h"_n = '8'}));

  auto [s70, s71] = kumi::split(t, 7_c);
  TTS_EQUAL(s70, (kumi::record{"a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = 4, "e"_n = 5, "f"_n = 6.f, "g"_n = 7.}));
  TTS_EQUAL(s71, (kumi::record{"h"_n = '8'}));

  auto [s80, s81] = kumi::split(t, 8_c);
  TTS_EQUAL(s80, (kumi::record{"a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = 4, "e"_n = 5, "f"_n = 6.f, "g"_n = 7.,
                               "h"_n = '8'}));
  TTS_EQUAL(s81, (kumi::record{}));
};

TTS_CASE("Check record::split constexpr behavior")
{
  using namespace kumi::literals;

  constexpr kumi::record t = {"a"_n = '1', "b"_n = 2.,  "c"_n = 3.f, "d"_n = 4,
                              "e"_n = 5,   "f"_n = 6.f, "g"_n = 7.,  "h"_n = '8'};

  {
    constexpr auto s = kumi::split(t, 0_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), kumi::record{});
    TTS_CONSTEXPR_EQUAL(get<1>(s), t);
  }

  {
    constexpr auto s = kumi::split(t, 1_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::record{"a"_n = '1'}));
    TTS_CONSTEXPR_EQUAL(
      get<1>(s), (kumi::record{"b"_n = 2., "c"_n = 3.f, "d"_n = 4, "e"_n = 5, "f"_n = 6.f, "g"_n = 7., "h"_n = '8'}));
  }

  {
    constexpr auto s = kumi::split(t, 2_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::record{"a"_n = '1', "b"_n = 2.}));
    TTS_CONSTEXPR_EQUAL(get<1>(s),
                        (kumi::record{"c"_n = 3.f, "d"_n = 4, "e"_n = 5, "f"_n = 6.f, "g"_n = 7., "h"_n = '8'}));
  }

  {
    constexpr auto s = kumi::split(t, 3_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::record{"a"_n = '1', "b"_n = 2., "c"_n = 3.f}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::record{"d"_n = 4, "e"_n = 5, "f"_n = 6.f, "g"_n = 7., "h"_n = '8'}));
  }

  {
    constexpr auto s = kumi::split(t, 4_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::record{"a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = 4}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::record{"e"_n = 5, "f"_n = 6.f, "g"_n = 7., "h"_n = '8'}));
  }

  {
    constexpr auto s = kumi::split(t, 5_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::record{"a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = 4, "e"_n = 5}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::record{"f"_n = 6.f, "g"_n = 7., "h"_n = '8'}));
  }

  {
    constexpr auto s = kumi::split(t, 6_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s),
                        (kumi::record{"a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = 4, "e"_n = 5, "f"_n = 6.f}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::record{"g"_n = 7., "h"_n = '8'}));
  }

  {
    constexpr auto s = kumi::split(t, 7_c);
    TTS_CONSTEXPR_EQUAL(
      get<0>(s), (kumi::record{"a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = 4, "e"_n = 5, "f"_n = 6.f, "g"_n = 7.}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::record{"h"_n = '8'}));
  }

  {
    constexpr auto s = kumi::split(t, 8_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::record{"a"_n = '1', "b"_n = 2., "c"_n = 3.f, "d"_n = 4, "e"_n = 5,
                                                 "f"_n = 6.f, "g"_n = 7., "h"_n = '8'}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::record{}));
  }
};
