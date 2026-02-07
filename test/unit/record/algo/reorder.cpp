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

  TTS_TYPE_IS((kumi::result::reorder_fields_t<record_t, "a"_n, "b"_n, "c"_n, "d"_n>), record_t);
  TTS_TYPE_IS((kumi::result::reorder_fields_t<record_t, "b"_n, "c"_n, "d"_n, "a"_n>),
              (kumi::record<short_f, int_f, double_f, char_f>));
  TTS_TYPE_IS((kumi::result::reorder_t<record_t>), kumi::record<>);
};

TTS_CASE("Check reorder<I...>(record) behavior"){
  {auto t = kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f, "d"_n = '5'};

{
  auto s = kumi::reorder<0, 1, 2, 3>(t);
  TTS_EQUAL(s, t);
}

{
  auto s = kumi::reorder<3, 2, 1, 0>(t);
  TTS_EQUAL(s, (kumi::record{"d"_n = '5', "c"_n = 3.4f, "b"_n = 2., "a"_n = 1}));
}

{
  auto s = kumi::reorder<0, 1, 2>(t);
  TTS_EQUAL(s, (kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f}));
}

{
  auto s = kumi::reorder<0, 1>(t);
  TTS_EQUAL(s, (kumi::record{"a"_n = 1, "b"_n = 2.}));
}

{
  auto s = kumi::reorder<0>(t);
  TTS_EQUAL(s, (kumi::record{"a"_n = 1}));
}

{
  auto s = kumi::reorder<1>(t);
  TTS_EQUAL(s, (kumi::record{"b"_n = 2.}));
}

{
  auto s = kumi::reorder<2>(t);
  TTS_EQUAL(s, (kumi::record{"c"_n = 3.4f}));
}

{
  auto s = kumi::reorder<3>(t);
  TTS_EQUAL(s, (kumi::record{"d"_n = '5'}));
}
}
}
;

TTS_CASE("Check reorder_fields<Name...>(record) behavior"){
  {auto t = kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f, "d"_n = '5'};

{
  auto s = kumi::reorder_fields<"a"_n, "b"_n, "c"_n, "d"_n>(t);
  TTS_EQUAL(s, t);
}

{
  auto s = kumi::reorder_fields<"d"_n, "b"_n, "c"_n, "a"_n>(t);
  TTS_EQUAL(s, (kumi::record{"d"_n = '5', "c"_n = 3.4f, "b"_n = 2., "a"_n = 1}));
}

{
  auto s = kumi::reorder_fields<"a"_n, "b"_n, "c"_n>(t);
  TTS_EQUAL(s, (kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f}));
}

{
  auto s = kumi::reorder_fields<"a"_n, "b"_n>(t);
  TTS_EQUAL(s, (kumi::record{"a"_n = 1, "b"_n = 2.}));
}

{
  auto s = kumi::reorder_fields<"a"_n>(t);
  TTS_EQUAL(s, (kumi::record{"a"_n = 1}));
}

{
  auto s = kumi::reorder_fields<"b"_n>(t);
  TTS_EQUAL(s, (kumi::record{"b"_n = 2.}));
}

{
  auto s = kumi::reorder_fields<"c"_n>(t);
  TTS_EQUAL(s, (kumi::record{"c"_n = 3.4f}));
}

{
  auto s = kumi::reorder_fields<"d"_n>(t);
  TTS_EQUAL(s, (kumi::record{"d"_n = '5'}));
}
}
}
;

TTS_CASE("Check reorder<I...>(record) constexpr behavior"){
  {constexpr auto t = kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f, "d"_n = '5'};

{
  constexpr auto s = kumi::reorder<0, 1, 2, 3>(t);
  TTS_CONSTEXPR_EQUAL(s, t);
}

{
  constexpr auto s = kumi::reorder<3, 2, 1, 0>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"d"_n = '5', "c"_n = 3.4f, "b"_n = 2., "a"_n = 1}));
}

{
  constexpr auto s = kumi::reorder<0, 1, 2>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f}));
}

{
  constexpr auto s = kumi::reorder<0, 1>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"a"_n = 1, "b"_n = 2.}));
}

{
  constexpr auto s = kumi::reorder<0>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"a"_n = 1}));
}

{
  constexpr auto s = kumi::reorder<1>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"b"_n = 2.}));
}

{
  constexpr auto s = kumi::reorder<2>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"c"_n = 3.4f}));
}

{
  constexpr auto s = kumi::reorder<3>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"d"_n = '5'}));
}
}
}
;

TTS_CASE("Check reorder_fields<Name...>(record) constexpr behavior"){
  {constexpr auto t = kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f, "d"_n = '5'};

{
  constexpr auto s = kumi::reorder_fields<"a"_n, "b"_n, "c"_n, "d"_n>(t);
  TTS_CONSTEXPR_EQUAL(s, t);
}

{
  constexpr auto s = kumi::reorder_fields<"d"_n, "c"_n, "b"_n, "a"_n>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"d"_n = '5', "c"_n = 3.4f, "b"_n = 2., "a"_n = 1}));
}

{
  constexpr auto s = kumi::reorder_fields<"a"_n, "b"_n, "c"_n>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"a"_n = 1, "b"_n = 2., "c"_n = 3.4f}));
}

{
  constexpr auto s = kumi::reorder_fields<"a"_n, "b"_n>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"a"_n = 1, "b"_n = 2.}));
}

{
  constexpr auto s = kumi::reorder_fields<"a"_n>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"a"_n = 1}));
}

{
  constexpr auto s = kumi::reorder_fields<"b"_n>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"b"_n = 2.}));
}

{
  constexpr auto s = kumi::reorder_fields<"c"_n>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"c"_n = 3.4f}));
}

{
  constexpr auto s = kumi::reorder_fields<"d"_n>(t);
  TTS_CONSTEXPR_EQUAL(s, (kumi::record{"d"_n = '5'}));
}
}
}
;
