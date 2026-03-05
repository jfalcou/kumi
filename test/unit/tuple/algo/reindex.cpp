//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/reorder.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check result::reindex<Tuple,Indexes> behavior")
{
  using namespace kumi::literals;
  using tuple_t = kumi::tuple<char, short, int, double>;

  constexpr auto id1 = kumi::indexes(0_c, 1_c, 2_c, 3_c);
  constexpr auto id2 = kumi::indexes(1_c, 2_c, 3_c, 0_c);
  constexpr auto id3 = kumi::indexes(3_c, 3_c);
  constexpr auto id4 = kumi::projection_map(1_c, 2_c, 3_c, kumi::indexes(0_c, 1_c, 2_c));

  TTS_TYPE_IS((kumi::result::reindex_t<tuple_t, id1>), tuple_t);
  TTS_TYPE_IS((kumi::result::reindex_t<tuple_t, id2>), (kumi::tuple<short, int, double, char>));
  TTS_TYPE_IS((kumi::result::reindex_t<tuple_t, id3>), (kumi::tuple<double, double>));
  TTS_TYPE_IS((kumi::result::reindex_t<tuple_t, id4>),
              (kumi::tuple<short, int, double, kumi::tuple<char, short, int>>));

  using nested_t = kumi::tuple<kumi::tuple<int, float>, int>;
  TTS_TYPE_IS((kumi::result::reindex_t<nested_t, kumi::indexes(0_c)>), (kumi::tuple<kumi::tuple<int, float>>));
};

TTS_CASE("Check reindex<Indexes>(tuple) behavior")
{
  using namespace kumi::literals;
  auto t = kumi::tuple{1, 2., 3.4f, '5'};
  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c, 3_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, t);
  }

  {
    constexpr auto id = kumi::indexes(3_c, 2_c, 1_c, 0_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::tuple{'5', 3.4f, 2., 1}));
  }

  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::tuple{1, 2., 3.4f}));
  }

  {
    constexpr auto id = kumi::indexes(0_c, 1_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::tuple{1, 2.}));
  }

  {
    constexpr auto id = kumi::indexes(0_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::tuple{1}));
  }

  {
    constexpr auto id = kumi::indexes(1_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::tuple{2.}));
  }

  {
    constexpr auto id = kumi::indexes(2_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::tuple{3.4f}));
  }

  {
    constexpr auto id = kumi::indexes(3_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::tuple{'5'}));
  }

  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c, 3_c, 2_c, 1_c, 0_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::tuple{1, 2., 3.4f, '5', 3.4f, 2., 1}));
  }
  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c, 3_c, 2_c, 1_c, 0_c);
    auto s = kumi::reindex<id>(std::move(t));
    TTS_EQUAL(s, (kumi::tuple{1, 2., 3.4f, '5', 3.4f, 2., 1}));
  }
  {
    constexpr auto id = kumi::projection_map(0_c, 1_c, 2_c, 3_c, kumi::indexes(3_c, 2_c, 1_c, 0_c));
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::tuple{1, 2., 3.4f, '5', kumi::tuple{'5', 3.4f, 2., 1}}));
  }
};

TTS_CASE("Check reindex<Indexes>(tuple) constexpr behavior")
{
  using namespace kumi::literals;
  constexpr auto t = kumi::tuple{1, 2., 3.4f, '5'};
  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c, 3_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, t);
  }
  {
    constexpr auto id = kumi::indexes(3_c, 2_c, 1_c, 0_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{'5', 3.4f, 2., 1}));
  }
  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1, 2., 3.4f}));
  }
  {
    constexpr auto id = kumi::indexes(0_c, 1_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1, 2.}));
  }
  {
    constexpr auto id = kumi::indexes(0_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1}));
  }
  {
    constexpr auto id = kumi::indexes(1_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{2.}));
  }
  {
    constexpr auto id = kumi::indexes(2_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{3.4f}));
  }
  {
    constexpr auto id = kumi::indexes(3_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{'5'}));
  }
  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c, 3_c, 2_c, 1_c, 0_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1, 2., 3.4f, '5', 3.4f, 2., 1}));
  }
  {
    constexpr auto id = kumi::projection_map(0_c, 1_c, 2_c, 3_c, kumi::indexes(3_c, 2_c, 1_c, 0_c));
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1, 2., 3.4f, '5', kumi::tuple{'5', 3.4f, 2., 1}}));
  }
};
