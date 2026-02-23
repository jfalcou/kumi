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

TTS_CASE("Check tuple::as_flat_ptr function behavior")
{
  using namespace kumi;

  auto r = record{
    "a"_id = 3.25f,
    "b"_id = record{"c"_id = 2., "d"_id = record{"e"_id = 2., "f"_id = 1, "g"_id = short{55}}, "h"_id = short{55}},
    "i"_id = 'a'};
  auto f = as_flat_ptr(r);

  TTS_EQUAL(get<"a">(f), &get<"a">(r));
  TTS_EQUAL(get<"b.c">(f), &get<"c">(get<"b">(r)));
  TTS_EQUAL(get<"b.d.e">(f), &get<"e">(get<"d">(get<"b">(r))));
  TTS_EQUAL(get<"b.d.f">(f), &get<"f">(get<"d">(get<"b">(r))));
  TTS_EQUAL(get<"b.d.g">(f), &get<"g">(get<"d">(get<"b">(r))));
  TTS_EQUAL(get<"b.h">(f), &get<"h">(get<"b">(r)));
  TTS_EQUAL(get<"i">(f), &get<"i">(r));
};
