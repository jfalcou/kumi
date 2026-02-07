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

TTS_CASE("Check result::reorder<record,I...> behavior")
{
  using char_f = kumi::field<kumi::name<"a">, char>;
  using short_f = kumi::field<kumi::name<"b">, short>;
  using int_f = kumi::field<kumi::name<"c">, int>;
  using double_f = kumi::field<kumi::name<"d">, double>;

  using record_t = kumi::record<char_f, short_f, int_f, double_f>;

  TTS_TYPE_IS((kumi::result::reorder_t<record_t, 0, 1, 2, 3>), record_t);
  TTS_TYPE_IS((kumi::result::reorder_t<record_t, 1, 2, 3, 0>), (kumi::record<short_f, int_f, double_f, char_f>));
  TTS_TYPE_IS((kumi::result::reorder_t<record_t>), kumi::record<>);
};

TTS_CASE("Check result::reorder_fields<record,Name...> behavior")
{
  using char_f = kumi::field<kumi::name<"a">, char>;
  using short_f = kumi::field<kumi::name<"b">, short>;
  using int_f = kumi::field<kumi::name<"c">, int>;
  using double_f = kumi::field<kumi::name<"d">, double>;

  using record_t = kumi::record<char_f, short_f, int_f, double_f>;

  TTS_TYPE_IS((kumi::result::reorder_fields_t<record_t, "a"_id, "b"_id, "c"_id, "d"_id>), record_t);
  TTS_TYPE_IS((kumi::result::reorder_fields_t<record_t, "b"_id, "c"_id, "d"_id, "a"_id>),
              (kumi::record<short_f, int_f, double_f, char_f>));
  TTS_TYPE_IS((kumi::result::reorder_t<record_t>), kumi::record<>);
};

TTS_CASE("Check reorder<I...>(record) behavior"){
  {auto t = kumi::record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f, "d"_id = '5'};

{
  auto s = kumi::reorder<0, 1, 2, 3>(t);
  TTS_EQUAL(s, t);
}

{
  auto s = kumi::reorder<3, 2, 1, 0>(t);
  TTS_EQUAL(s, (kumi::record{"d"_id = '5', "c"_id = 3.4f, "b"_id = 2., "a"_id = 1}));
}

{
  auto s = kumi::reorder<0, 1, 2>(t);
  TTS_EQUAL(s, (kumi::record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f}));
}

{
  auto s = kumi::reorder<0, 1>(t);
  TTS_EQUAL(s, (kumi::record{"a"_id = 1, "b"_id = 2.}));
}

{
  auto s = kumi::reorder<0>(t);
  TTS_EQUAL(s, (kumi::record{"a"_id = 1}));
}

{
  auto s = kumi::reorder<1>(t);
  TTS_EQUAL(s, (kumi::record{"b"_id = 2.}));
}

{
  auto s = kumi::reorder<2>(t);
  TTS_EQUAL(s, (kumi::record{"c"_id = 3.4f}));
}

{
  auto s = kumi::reorder<3>(t);
  TTS_EQUAL(s, (kumi::record{"d"_id = '5'}));
}
}
}
;

TTS_CASE("Check reorder_fields<Name...>(record) behavior"){
  {auto t = kumi::record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f, "d"_id = '5'};

{
  auto s = kumi::reorder_fields<"a"_id, "b"_id, "c"_id, "d"_id>(t);
  TTS_EQUAL(s, t);
}

{
  auto s = kumi::reorder_fields<"d"_id, "b"_id, "c"_id, "a"_id>(t);
  TTS_EQUAL(s, (kumi::record{"d"_id = '5', "c"_id = 3.4f, "b"_id = 2., "a"_id = 1}));
}

{
  auto s = kumi::reorder_fields<"a"_id, "b"_id, "c"_id>(t);
  TTS_EQUAL(s, (kumi::record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f}));
}

{
  auto s = kumi::reorder_fields<"a"_id, "b"_id>(t);
  TTS_EQUAL(s, (kumi::record{"a"_id = 1, "b"_id = 2.}));
}

{
  auto s = kumi::reorder_fields<"a"_id>(t);
  TTS_EQUAL(s, (kumi::record{"a"_id = 1}));
}

{
  auto s = kumi::reorder_fields<"b"_id>(t);
  TTS_EQUAL(s, (kumi::record{"b"_id = 2.}));
}

{
  auto s = kumi::reorder_fields<"c"_id>(t);
  TTS_EQUAL(s, (kumi::record{"c"_id = 3.4f}));
}

{
  auto s = kumi::reorder_fields<"d"_id>(t);
  TTS_EQUAL(s, (kumi::record{"d"_id = '5'}));
}
}
}
;

TTS_CASE("Check reorder<I...>(record) constexpr behavior"){
  {constexpr auto t = kumi::record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f, "d"_id = '5'};

{
  constexpr auto s = kumi::reorder<0, 1, 2, 3>(t);
  TTS_CONSTEXPR_EQUAL(s, t);
}

{
  constexpr auto s = kumi::reorder<3, 2, 1, 0>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"d"_id = '5', "c"_id = 3.4f, "b"_id = 2., "a"_id = 1}));
}

{
  constexpr auto s = kumi::reorder<0, 1, 2>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f}));
}

{
  constexpr auto s = kumi::reorder<0, 1>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"a"_id = 1, "b"_id = 2.}));
}

{
  constexpr auto s = kumi::reorder<0>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"a"_id = 1}));
}

{
  constexpr auto s = kumi::reorder<1>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"b"_id = 2.}));
}

{
  constexpr auto s = kumi::reorder<2>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"c"_id = 3.4f}));
}

{
  constexpr auto s = kumi::reorder<3>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"d"_id = '5'}));
}
}
}
;

TTS_CASE("Check reorder_fields<Name...>(record) constexpr behavior"){
  {constexpr auto t = kumi::record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f, "d"_id = '5'};

{
  constexpr auto s = kumi::reorder_fields<"a"_id, "b"_id, "c"_id, "d"_id>(t);
  TTS_CONSTEXPR_EQUAL(s, t);
}

{
  constexpr auto s = kumi::reorder_fields<"d"_id, "c"_id, "b"_id, "a"_id>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"d"_id = '5', "c"_id = 3.4f, "b"_id = 2., "a"_id = 1}));
}

{
  constexpr auto s = kumi::reorder_fields<"a"_id, "b"_id, "c"_id>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f}));
}

{
  constexpr auto s = kumi::reorder_fields<"a"_id, "b"_id>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"a"_id = 1, "b"_id = 2.}));
}

{
  constexpr auto s = kumi::reorder_fields<"a"_id>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"a"_id = 1}));
}

{
  constexpr auto s = kumi::reorder_fields<"b"_id>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"b"_id = 2.}));
}

{
  constexpr auto s = kumi::reorder_fields<"c"_id>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"c"_id = 3.4f}));
}

{
  constexpr auto s = kumi::reorder_fields<"d"_id>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"d"_id = '5'}));
}
}
}
;
