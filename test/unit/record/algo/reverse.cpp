//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check result::reverse<record> behavior")
{
  using record_t = kumi::record<kumi::field_capture<"a", char>, kumi::field_capture<"b", short>,
                                kumi::field_capture<"c", int>, kumi::field_capture<"d", double>>;

  TTS_TYPE_IS((kumi::result::reverse_t<record_t>),
              (kumi::record<kumi::field_capture<"d", double>, kumi::field_capture<"c", int>,
                            kumi::field_capture<"b", short>, kumi::field_capture<"a", char>>));
};

TTS_CASE("Check reverse(record) behavior")
{
  using namespace kumi::literals;

  auto t = kumi::record{"a"_f = 1, "b"_f = 2., "c"_f = 3.4f, "d"_f = '5'};
  TTS_EQUAL(kumi::reverse(t), (kumi::record{"d"_f = '5', "c"_f = 3.4f, "b"_f = 2., "a"_f = 1}));
  TTS_EQUAL(kumi::reverse(kumi::record<>{}), (kumi::record{}));
};

TTS_CASE("Check reverse(record) constexpr behavior")
{
  using namespace kumi::literals;

  constexpr auto t = kumi::record{"a"_f = 1, "b"_f = 2., "c"_f = 3.4f, "d"_f = '5'};
  TTS_CONSTEXPR_EQUAL(kumi::reverse(t), (kumi::record{"d"_f = '5', "c"_f = 3.4f, "b"_f = 2., "a"_f = 1}));
  TTS_CONSTEXPR_EQUAL(kumi::reverse(kumi::record<>{}), (kumi::record{}));
};
