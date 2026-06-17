//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/record.hpp>
#include <kumi/algorithm/flatten.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check kumi::result::compress behavior on records")
{
  using char_f = kumi::field<kumi::name<"a">, char>;
  using short_f = kumi::field<kumi::name<"b">, short>;
  using int_f = kumi::field<kumi::name<"c">, int>;
  using double_f = kumi::field<kumi::name<"d">, double>;

  TTS_TYPE_IS((kumi::result::compress_t<kumi::record<>>), (kumi::record<>));

  TTS_TYPE_IS((kumi::result::compress_t<kumi::record<kumi::field<kumi::name<"a">, kumi::record<>>>>), (kumi::record<>));

  TTS_TYPE_IS(
    (kumi::result::compress_t<kumi::record<kumi::field<
       kumi::name<"a">, kumi::record<kumi::field<kumi::name<"b">, kumi::record<double_f, char_f, short_f>>>>>>),
    (kumi::record<kumi::field<kumi::name<"a.b.d">, double>, kumi::field<kumi::name<"a.b.a">, char>,
                  kumi::field<kumi::name<"a.b.b">, short>>));

  TTS_TYPE_IS((kumi::result::compress_t<kumi::record<char_f, short_f, int_f, double_f>>),
              (kumi::record<char_f, short_f, int_f, double_f>));

  TTS_TYPE_IS(
    (kumi::result::compress_t<kumi::record<
       char_f, kumi::field<kumi::name<"b">,
                           kumi::record<short_f, int_f, kumi::field<kumi::name<"f">, kumi::record<double_f>>>>>>),
    (kumi::record<char_f,
                  kumi::field<kumi::name<"b">,
                              kumi::record<short_f, int_f, kumi::field<kumi::name<"f">, kumi::record<double_f>>>>>));
};

TTS_CASE("Check kumi::compress behavior on records")
{
  using namespace kumi::literals;

  auto t0 = kumi::record{};
  auto t1 = kumi::record{"a"_id = 2., "b"_id = 1, "c"_id = short{55}};
  auto t2 = kumi::record{"a"_id = kumi::record{"b"_id = 2., "c"_id = 1, "d"_id = short{55}}};
  auto t3 = kumi::record{"a"_id = kumi::record{"b"_id = kumi::record{"c"_id = 2., "d"_id = 1, "e"_id = short{55}}}};
  auto t4 =
    kumi::record{"a"_id = 3.25f, "b"_id = kumi::record{"c"_id = 2., "d"_id = 1, "e"_id = short{55}}, "f"_id = 'z'};
  auto t5 =
    kumi::record{"a"_id = 3.25f,
                 "b"_id = kumi::record{"c"_id = 2., "d"_id = kumi::record{"e"_id = 2., "f"_id = 1, "g"_id = short{55}},
                                       "h"_id = short{55}},
                 "i"_id = 'z'};

  TTS_EQUAL(kumi::compress(t0), t0);
  TTS_EQUAL((kumi::compress(t1)), (t1));
  TTS_EQUAL((kumi::compress(t2)), (kumi::record{"a.b"_id = 2., "a.c"_id = 1, "a.d"_id = short{55}}));
  TTS_EQUAL((kumi::compress(t3)), (kumi::record{"a.b.c"_id = 2., "a.b.d"_id = 1, "a.b.e"_id = short{55}}));

  TTS_EQUAL((kumi::compress(t4)), (t4));
  TTS_EQUAL((kumi::compress(t5)), (t5));

  auto r = kumi::record{"a"_id = 1.f, "b"_id = 'x', "c"_id = short{66}, "d"_id = moveonly{}};
  TTS_EXPECT_COMPILES(r, { kumi::compress(std::move(r)); });
};

TTS_CASE("Check kumi::compress constexpr behavior on records")
{
  using namespace kumi::literals;

  constexpr auto t0 = kumi::record{};
  constexpr auto t1 = kumi::record{"a"_id = 2., "b"_id = 1, "c"_id = short{55}};
  constexpr auto t2 = kumi::record{"a"_id = kumi::record{"b"_id = 2., "c"_id = 1, "d"_id = short{55}}};
  constexpr auto t3 =
    kumi::record{"a"_id = kumi::record{"b"_id = kumi::record{"c"_id = 2., "d"_id = 1, "e"_id = short{55}}}};
  constexpr auto t4 =
    kumi::record{"a"_id = 3.25f, "b"_id = kumi::record{"c"_id = 2., "d"_id = 1, "e"_id = short{55}}, "f"_id = 'z'};
  constexpr auto t5 =
    kumi::record{"a"_id = 3.25f,
                 "b"_id = kumi::record{"c"_id = 2., "d"_id = kumi::record{"e"_id = 2., "f"_id = 1, "g"_id = short{55}},
                                       "h"_id = short{55}},
                 "i"_id = 'z'};

  TTS_CONSTEXPR_EQUAL(kumi::compress(t0), t0);
  TTS_CONSTEXPR_EQUAL((kumi::compress(t1)), (t1));
  TTS_CONSTEXPR_EQUAL((kumi::compress(t2)), (kumi::record{"a.b"_id = 2., "a.c"_id = 1, "a.d"_id = short{55}}));
  TTS_CONSTEXPR_EQUAL((kumi::compress(t3)), (kumi::record{"a.b.c"_id = 2., "a.b.d"_id = 1, "a.b.e"_id = short{55}}));

  TTS_CONSTEXPR_EQUAL((kumi::compress(t4)), (t4));
  TTS_CONSTEXPR_EQUAL((kumi::compress(t5)), (t5));
};
