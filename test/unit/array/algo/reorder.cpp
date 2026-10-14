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

TTS_CASE("Check result::reorder<Array,I...> behavior")
{
  using array_t = kumi::array<int, 4>;

  TTS_TYPE_IS((kumi::result::reorder_t<array_t, 0, 1, 2, 3>), array_t);
  TTS_TYPE_IS((kumi::result::reorder_t<array_t, 1, 2, 3, 0>), array_t);
  TTS_TYPE_IS((kumi::result::reorder_t<array_t, 3, 3>), (kumi::array<int, 2>));
  TTS_TYPE_IS((kumi::result::reorder_t<array_t>), (kumi::array<>));
};

TTS_CASE("Check reorder<I...>(array) behavior")
{
  auto t = kumi::array{1, 2, 3, 4};

  {
    auto s = kumi::reorder<>(t);
    TTS_EQUAL(s, (kumi::array<int, 0>{}));
  }
  {
    auto s = kumi::reorder<0, 1, 2, 3>(t);
    TTS_EQUAL(s, t);
  }

  {
    auto s = kumi::reorder<3, 2, 1, 0>(t);
    TTS_EQUAL(s, (kumi::array{4, 3, 2, 1}));
  }

  {
    auto s = kumi::reorder<0, 1, 2>(t);
    TTS_EQUAL(s, (kumi::array{1, 2, 3}));
  }

  {
    auto s = kumi::reorder<0, 1>(t);
    TTS_EQUAL(s, (kumi::array{1, 2}));
  }

  {
    auto s = kumi::reorder<0>(t);
    TTS_EQUAL(s, (kumi::array{1}));
  }

  {
    auto s = kumi::reorder<1>(t);
    TTS_EQUAL(s, (kumi::array{2}));
  }

  {
    auto s = kumi::reorder<2>(t);
    TTS_EQUAL(s, (kumi::array{3}));
  }

  {
    auto s = kumi::reorder<3>(t);
    TTS_EQUAL(s, (kumi::array{4}));
  }

  {
    auto s = kumi::reorder<0, 1, 2, 3, 2, 1, 0>(t);
    TTS_EQUAL(s, (kumi::array{1, 2, 3, 4, 3, 2, 1}));
  }
  {
    auto s = kumi::reorder<0, 1, 2, 3, 2, 1, 0>(std::move(t));
    TTS_EQUAL(s, (kumi::array{1, 2, 3, 4, 3, 2, 1}));
  }
};

TTS_CASE("Check reorder<I...>(array) constexpr behavior")
{
  constexpr auto t = kumi::array{1, 2, 3, 4};

  {
    constexpr auto s = kumi::reorder<>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array<int, 0>{}));
  }
  {
    constexpr auto s = kumi::reorder<0, 1, 2, 3>(t);
    TTS_CONSTEXPR_EQUAL(s, t);
  }

  {
    constexpr auto s = kumi::reorder<3, 2, 1, 0>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{4, 3, 2, 1}));
  }

  {
    constexpr auto s = kumi::reorder<0, 1, 2>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{1, 2, 3}));
  }

  {
    constexpr auto s = kumi::reorder<0, 1>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{1, 2}));
  }

  {
    constexpr auto s = kumi::reorder<0>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{1}));
  }

  {
    constexpr auto s = kumi::reorder<1>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{2}));
  }

  {
    constexpr auto s = kumi::reorder<2>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{3}));
  }

  {
    constexpr auto s = kumi::reorder<3>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{4}));
  }

  {
    constexpr auto s = kumi::reorder<0, 1, 2, 3, 2, 1, 0>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{1, 2, 3, 4, 3, 2, 1}));
  }
};
