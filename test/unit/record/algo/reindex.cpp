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

  using char_t = field<name<"c">, char>;
  using short_t = field<name<"s">, short>;
  using int_t = field<name<"i">, int>;
  using double_t = field<name<"d">, double>;
  using float_t = field<name<"f">, float>;

  using record_t = record<char_t, short_t, int_t, double_t>;

  constexpr auto id1 = indexes(0, 1, 2, 3);
  constexpr auto id2 = indexes(1, 2, 3, 0);

  TTS_TYPE_IS((result::reindex_t<record_t, id1>), record_t);
  TTS_TYPE_IS((result::reindex_t<record_t, id2>), (record<short_t, int_t, double_t, char_t>));

  using nested_t = record<field<name<"inner">, record<int_t, float_t>>, int_t>;
  TTS_TYPE_IS((kumi::result::reindex_t<nested_t, indexes(0)>), (record<field<name<"inner">, record<int_t, float_t>>>));
};

TTS_CASE("Check reindex<Indexes>(record) behavior")
{
  using namespace kumi;
  auto t = record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f, "d"_id = '5'};
  {
    constexpr auto id = indexes(0, 1, 2, 3);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, t);
  }

  {
    constexpr auto id = indexes(3, 2, 1, 0);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"d"_id = '5', "c"_id = 3.4f, "b"_id = 2., "a"_id = 1}));
  }

  {
    constexpr auto id = indexes(0, 1, 2);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f}));
  }

  {
    constexpr auto id = indexes(0, 1);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"a"_id = 1, "b"_id = 2.}));
  }

  {
    constexpr auto id = indexes(0);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"a"_id = 1}));
  }

  {
    constexpr auto id = indexes(1);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"b"_id = 2.}));
  }

  {
    constexpr auto id = indexes(2);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"c"_id = 3.4f}));
  }

  {
    constexpr auto id = indexes(3);
    auto s = reindex<id>(t);
    TTS_EQUAL(s, (record{"d"_id = '5'}));
  }
};

TTS_CASE("Check reindex<Indexes>(record) constexpr behavior")
{
  using namespace kumi;
  constexpr auto t = record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f, "d"_id = '5'};
  {
    constexpr auto id = indexes(0, 1, 2, 3);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, t);
  }

  {
    constexpr auto id = indexes(3, 2, 1, 0);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"d"_id = '5', "c"_id = 3.4f, "b"_id = 2., "a"_id = 1}));
  }

  {
    constexpr auto id = indexes(0, 1, 2);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"a"_id = 1, "b"_id = 2., "c"_id = 3.4f}));
  }

  {
    constexpr auto id = indexes(0, 1);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"a"_id = 1, "b"_id = 2.}));
  }

  {
    constexpr auto id = indexes(0);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"a"_id = 1}));
  }

  {
    constexpr auto id = indexes(1);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"b"_id = 2.}));
  }

  {
    constexpr auto id = indexes(2);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"c"_id = 3.4f}));
  }

  {
    constexpr auto id = indexes(3);
    constexpr auto s = reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (record{"d"_id = '5'}));
  }
};
