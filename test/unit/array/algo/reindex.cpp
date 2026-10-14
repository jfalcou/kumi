//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/reorder.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check result::reindex<Array,Indexes> behavior")
{
  using namespace kumi::literals;
  using array_t = kumi::array<int, 4>;

  constexpr auto id1 = kumi::indexes(0_c, 1_c, 2_c, 3_c);
  constexpr auto id2 = kumi::indexes(1_c, 2_c, 3_c, 0_c);
  constexpr auto id3 = kumi::indexes(3_c, 3_c);

  TTS_TYPE_IS((kumi::result::reindex_t<array_t, id1>), array_t);
  TTS_TYPE_IS((kumi::result::reindex_t<array_t, id2>), array_t);
  TTS_TYPE_IS((kumi::result::reindex_t<array_t, id3>), (kumi::array<int, 2>));
};

TTS_CASE("Check reindex<Indexes>(array) behavior")
{
  using namespace kumi::literals;
  auto t = kumi::array{1, 2, 3, 4};
  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c, 3_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, t);
  }

  {
    constexpr auto id = kumi::indexes(3_c, 2_c, 1_c, 0_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::array{4, 3, 2, 1}));
  }

  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::array{1, 2, 3}));
  }

  {
    constexpr auto id = kumi::indexes(0_c, 1_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::array{1, 2}));
  }

  {
    constexpr auto id = kumi::indexes(0_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::array{1}));
  }

  {
    constexpr auto id = kumi::indexes(1_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::array{2}));
  }

  {
    constexpr auto id = kumi::indexes(2_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::array{3}));
  }

  {
    constexpr auto id = kumi::indexes(3_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::array{4}));
  }

  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c, 3_c, 2_c, 1_c, 0_c);
    auto s = kumi::reindex<id>(t);
    TTS_EQUAL(s, (kumi::array{1, 2, 3, 4, 3, 2, 1}));
  }
  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c, 3_c, 2_c, 1_c, 0_c);
    auto s = kumi::reindex<id>(std::move(t));
    TTS_EQUAL(s, (kumi::array{1, 2, 3, 4, 3, 2, 1}));
  }
};

TTS_CASE("Check reindex<Indexes>(array) constexpr behavior")
{
  using namespace kumi::literals;
  constexpr auto t = kumi::array{1, 2, 3, 4};
  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c, 3_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, t);
  }
  {
    constexpr auto id = kumi::indexes(3_c, 2_c, 1_c, 0_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{4, 3, 2, 1}));
  }
  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{1, 2, 3}));
  }
  {
    constexpr auto id = kumi::indexes(0_c, 1_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{1, 2}));
  }
  {
    constexpr auto id = kumi::indexes(0_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{1}));
  }
  {
    constexpr auto id = kumi::indexes(1_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{2}));
  }
  {
    constexpr auto id = kumi::indexes(2_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{3}));
  }
  {
    constexpr auto id = kumi::indexes(3_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{4}));
  }
  {
    constexpr auto id = kumi::indexes(0_c, 1_c, 2_c, 3_c, 2_c, 1_c, 0_c);
    constexpr auto s = kumi::reindex<id>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{1, 2, 3, 4, 3, 2, 1}));
  }
};
