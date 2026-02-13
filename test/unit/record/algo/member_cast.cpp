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

using namespace kumi::literals;

TTS_CASE("Check runtime kumi::member_cast behavior on records")
{
  auto base = kumi::record{"a"_f = 1UL, "b"_f = short{44}, "c"_f = 12.5, "d"_f = 3.f};
  TTS_EQUAL(kumi::member_cast<int>(base), (kumi::record{"a"_f = 1, "b"_f = 44, "c"_f = 12, "d"_f = 3}));
  TTS_EQUAL(kumi::member_cast<float>(base), (kumi::record{"a"_f = 1.f, "b"_f = 44.f, "c"_f = 12.5f, "d"_f = 3.f}));
  TTS_EQUAL(kumi::member_cast<float>(base), (kumi::record{"a"_f = 1.f, "b"_f = 44.f, "c"_f = 12.5f, "d"_f = 3.f}));
};

TTS_CASE("Check constexpr kumi::member_cast behavior on records")
{
  constexpr auto base = kumi::record{"a"_f = 1UL, "b"_f = short{44}, "c"_f = 12.5, "d"_f = 3.f};
  TTS_CONSTEXPR_EQUAL(kumi::member_cast<int>(base), (kumi::record{"a"_f = 1, "b"_f = 44, "c"_f = 12, "d"_f = 3}));
  TTS_CONSTEXPR_EQUAL(kumi::member_cast<float>(base),
                      (kumi::record{"a"_f = 1.f, "b"_f = 44.f, "c"_f = 12.5f, "d"_f = 3.f}));
  TTS_CONSTEXPR_EQUAL(kumi::member_cast<float>(base),
                      (kumi::record{"a"_f = 1.f, "b"_f = 44.f, "c"_f = 12.5f, "d"_f = 3.f}));
};

TTS_CASE("Check result::member_cast behavior on records")
{
  using namespace kumi;
  using base = record<field_capture<"a", int>, field_capture<"b", char&>, field_capture<"c", float&&>,
                      field_capture<"d", short const>, field_capture<"e", long>>;
  using t1 = record<field_capture<"a", double>, field_capture<"b", double>, field_capture<"c", double>,
                    field_capture<"d", double>, field_capture<"e", double>>;
  using t2 = record<field_capture<"a", char const>, field_capture<"b", char const>, field_capture<"c", char const>,
                    field_capture<"d", char const>, field_capture<"e", char const>>;

  TTS_TYPE_IS((kumi::result::member_cast_t<double, base>), (t1));
  TTS_TYPE_IS((kumi::result::member_cast_t<char const, base>), (t2));
};
