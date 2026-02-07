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
  auto base = kumi::record{"a"_id = 1UL, "b"_id = short{44}, "c"_id = 12.5, "d"_id = 3.f};
  TTS_EQUAL(kumi::member_cast<int>(base), (kumi::record{"a"_id = 1, "b"_id = 44, "c"_id = 12, "d"_id = 3}));
  TTS_EQUAL(kumi::member_cast<float>(base), (kumi::record{"a"_id = 1.f, "b"_id = 44.f, "c"_id = 12.5f, "d"_id = 3.f}));
  TTS_EQUAL(kumi::member_cast<float>(base), (kumi::record{"a"_id = 1.f, "b"_id = 44.f, "c"_id = 12.5f, "d"_id = 3.f}));
};

TTS_CASE("Check constexpr kumi::member_cast behavior on records")
{
  constexpr auto base = kumi::record{"a"_id = 1UL, "b"_id = short{44}, "c"_id = 12.5, "d"_id = 3.f};
  TTS_CONSTEXPR_EQUAL(kumi::member_cast<int>(base), (kumi::record{"a"_id = 1, "b"_id = 44, "c"_id = 12, "d"_id = 3}));
  TTS_CONSTEXPR_EQUAL(kumi::member_cast<float>(base),
                      (kumi::record{"a"_id = 1.f, "b"_id = 44.f, "c"_id = 12.5f, "d"_id = 3.f}));
  TTS_CONSTEXPR_EQUAL(kumi::member_cast<float>(base),
                      (kumi::record{"a"_id = 1.f, "b"_id = 44.f, "c"_id = 12.5f, "d"_id = 3.f}));
};

TTS_CASE("Check result::member_cast behavior on records")
{
  using namespace kumi;
  using base = record<field<kumi::name<"a">, int>, field<kumi::name<"b">, char&>, field<kumi::name<"c">, float&&>,
                      field<kumi::name<"d">, short const>, field<kumi::name<"e">, long>>;
  using t1 = record<field<kumi::name<"a">, double>, field<kumi::name<"b">, double>, field<kumi::name<"c">, double>,
                    field<kumi::name<"d">, double>, field<kumi::name<"e">, double>>;
  using t2 =
    record<field<kumi::name<"a">, char const>, field<kumi::name<"b">, char const>, field<kumi::name<"c">, char const>,
           field<kumi::name<"d">, char const>, field<kumi::name<"e">, char const>>;

  TTS_TYPE_IS((kumi::result::member_cast_t<double, base>), (t1));
  TTS_TYPE_IS((kumi::result::member_cast_t<char const, base>), (t2));
};
