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

TTS_CASE("Check result::reindex<Record,Indexes> behavior")
{
  using namespace kumi;

  using charf_t = field<name<"c">, char>;
  using shortf_t = field<name<"s">, short>;
  using intf_t = field<name<"i">, int>;
  using doublef_t = field<name<"d">, double>;
  using floatf_t = field<name<"f">, float>;

  using record_t = record<charf_t, shortf_t, intf_t, doublef_t>;

  constexpr auto id1 = indexes(0_c, 1_c, 2_c, 3_c);
  constexpr auto id2 = indexes(1_c, 2_c, 3_c, 0_c);

  TTS_TYPE_IS((result::reindex_t<record_t, id1>), record_t);
  TTS_TYPE_IS((result::reindex_t<record_t, id2>), (record<shortf_t, intf_t, doublef_t, charf_t>));

  using nested_t = record<field<name<"inner">, record<intf_t, floatf_t>>, intf_t>;
  TTS_TYPE_IS((kumi::result::reindex_t<nested_t, indexes(0_c)>),
              (record<field<name<"inner">, record<intf_t, floatf_t>>>));
};

TTS_CASE("Check reindex<Indexes>(record) behavior")
{
  using namespace kumi;
  auto t = record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f, "d"_id = '5'};
  {
    constexpr auto id = indexes(0_c, 1_c, 2_c, 3_c);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, t);
  }

  {
    constexpr auto id = indexes(3_c, 2_c, 1_c, 0_c);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"d"_id = '5', "c"_id = 3.4f, "b"_id = 2., "a"_id = 1}));
  }

  {
    constexpr auto id = indexes(0_c, 1_c, 2_c);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f}));
  }

  {
    constexpr auto id = indexes(0_c, 1_c);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"a"_id = 1, "b"_id = 2.}));
  }

  {
    constexpr auto id = indexes(0_c);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"a"_id = 1}));
  }

  {
    constexpr auto id = indexes(1_c);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"b"_id = 2.}));
  }

  {
    constexpr auto id = indexes(2_c);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"c"_id = 3.4f}));
  }

  {
    constexpr auto id = indexes(3_c);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"d"_id = '5'}));
  }
};

TTS_CASE("Check reindex<Indexes>(record) constexpr behavior")
{
  using namespace kumi;
  constexpr auto t = record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f, "d"_id = '5'};
  {
    constexpr auto id = indexes(0_c, 1_c, 2_c, 3_c);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, t);
  }

  {
    constexpr auto id = indexes(3_c, 2_c, 1_c, 0_c);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"d"_id = '5', "c"_id = 3.4f, "b"_id = 2., "a"_id = 1}));
  }

  {
    constexpr auto id = indexes(0_c, 1_c, 2_c);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f}));
  }

  {
    constexpr auto id = indexes(0_c, 1_c);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"a"_id = 1, "b"_id = 2.}));
  }

  {
    constexpr auto id = indexes(0_c);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"a"_id = 1}));
  }

  {
    constexpr auto id = indexes(1_c);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"b"_id = 2.}));
  }

  {
    constexpr auto id = indexes(2_c);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"c"_id = 3.4f}));
  }

  {
    constexpr auto id = indexes(3_c);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"d"_id = '5'}));
  }
};
