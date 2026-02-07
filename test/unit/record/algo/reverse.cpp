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

TTS_CASE("Check result::reverse<record> behavior")
{
  using record_t = kumi::record<kumi::field<kumi::name<"a">, char>, kumi::field<kumi::name<"b">, short>,
                                kumi::field<kumi::name<"c">, int>, kumi::field<kumi::name<"d">, double>>;

  TTS_TYPE_IS((kumi::result::reverse_t<record_t>),
              (kumi::record<kumi::field<kumi::name<"d">, double>, kumi::field<kumi::name<"c">, int>,
                            kumi::field<kumi::name<"b">, short>, kumi::field<kumi::name<"a">, char>>));
};

TTS_CASE("Check reverse(record) behavior")
{
  using namespace kumi::literals;

  auto t = kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f, "d"_n = '5'};
  TTS_EQUAL(kumi::reverse(t), (kumi::record{"d"_n = '5', "c"_n = 3.4f, "b"_n = 2., "a"_n = 1}));
  TTS_EQUAL(kumi::reverse(kumi::record<>{}), (kumi::record{}));
};

TTS_CASE("Check reverse(record) constexpr behavior")
{
  using namespace kumi::literals;

  constexpr auto t = kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f, "d"_n = '5'};
  TTS_CONSTEXPR_EQUAL(kumi::reverse(t), (kumi::record{"d"_n = '5', "c"_n = 3.4f, "b"_n = 2., "a"_n = 1}));
  TTS_CONSTEXPR_EQUAL(kumi::reverse(kumi::record<>{}), (kumi::record{}));
};
