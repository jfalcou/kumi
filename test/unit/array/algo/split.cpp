//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/extract.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check result::split<Array,I> behavior")
{
  TTS_TYPE_IS((kumi::result::split_t<kumi::array<int, 4>, 0>), (kumi::tuple<kumi::array<int, 0>, kumi::array<int, 4>>));

  TTS_TYPE_IS((kumi::result::split_t<kumi::array<int, 4>, 1>), (kumi::tuple<kumi::array<int, 1>, kumi::array<int, 3>>));

  TTS_TYPE_IS((kumi::result::split_t<kumi::array<int, 4>, 2>), (kumi::tuple<kumi::array<int, 2>, kumi::array<int, 2>>));

  TTS_TYPE_IS((kumi::result::split_t<kumi::array<int, 4>, 3>), (kumi::tuple<kumi::array<int, 3>, kumi::array<int, 1>>));

  TTS_TYPE_IS((kumi::result::split_t<kumi::array<int, 4>, 4>), (kumi::tuple<kumi::array<int, 4>, kumi::array<int, 0>>));
};

TTS_CASE("Check array::split behavior")
{
  using namespace kumi::literals;

  kumi::array t = {1, 2, 3, 4, 5, 6, 7, 8};

  auto [s00, s01] = kumi::split(t, 0_c);
  TTS_EQUAL(s00, (kumi::array<int, 0>{}));
  TTS_EQUAL(s01, t);

  auto [s10, s11] = kumi::split(t, 1_c);
  TTS_EQUAL(s10, (kumi::array{1}));
  TTS_EQUAL(s11, (kumi::array{2, 3, 4, 5, 6, 7, 8}));

  auto [s20, s21] = kumi::split(t, 2_c);
  TTS_EQUAL(s20, (kumi::array{1, 2}));
  TTS_EQUAL(s21, (kumi::array{3, 4, 5, 6, 7, 8}));

  auto [s30, s31] = kumi::split(t, 3_c);
  TTS_EQUAL(s30, (kumi::array{1, 2, 3}));
  TTS_EQUAL(s31, (kumi::array{4, 5, 6, 7, 8}));

  auto [s40, s41] = kumi::split(t, 4_c);
  TTS_EQUAL(s40, (kumi::array{1, 2, 3, 4}));
  TTS_EQUAL(s41, (kumi::array{5, 6, 7, 8}));

  auto [s50, s51] = kumi::split(t, 5_c);
  TTS_EQUAL(s50, (kumi::array{1, 2, 3, 4, 5}));
  TTS_EQUAL(s51, (kumi::array{6, 7, 8}));

  auto [s60, s61] = kumi::split(t, 6_c);
  TTS_EQUAL(s60, (kumi::array{1, 2, 3, 4, 5, 6}));
  TTS_EQUAL(s61, (kumi::array{7, 8}));

  auto [s70, s71] = kumi::split(t, 7_c);
  TTS_EQUAL(s70, (kumi::array{1, 2, 3, 4, 5, 6, 7}));
  TTS_EQUAL(s71, (kumi::array{8}));

  auto [s80, s81] = kumi::split(t, 8_c);
  TTS_EQUAL(s80, t);
  TTS_EQUAL(s81, (kumi::array<int, 0>{}));

  auto [s82, s83] = kumi::split(std::move(t), 8_c);
  TTS_EQUAL(s82, (kumi::array{1, 2, 3, 4, 5, 6, 7, 8}));
  TTS_EQUAL(s83, (kumi::array<int, 0>{}));
};

TTS_CASE("Check array::split constexpr behavior")
{
  using namespace kumi::literals;

  constexpr kumi::array t = {1, 2, 3, 4, 5, 6, 7, 8};

  {
    constexpr auto s = kumi::split(t, 0_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::array<int, 0>{}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), t);
  }

  {
    constexpr auto s = kumi::split(t, 1_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::array{1}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::array{2, 3, 4, 5, 6, 7, 8}));
  }

  {
    constexpr auto s = kumi::split(t, 2_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::array{1, 2}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::array{3, 4, 5, 6, 7, 8}));
  }

  {
    constexpr auto s = kumi::split(t, 3_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::array{1, 2, 3}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::array{4, 5, 6, 7, 8}));
  }

  {
    constexpr auto s = kumi::split(t, 4_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::array{1, 2, 3, 4}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::array{5, 6, 7, 8}));
  }

  {
    constexpr auto s = kumi::split(t, 5_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::array{1, 2, 3, 4, 5}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::array{6, 7, 8}));
  }

  {
    constexpr auto s = kumi::split(t, 6_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::array{1, 2, 3, 4, 5, 6}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::array{7, 8}));
  }

  {
    constexpr auto s = kumi::split(t, 7_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::array{1, 2, 3, 4, 5, 6, 7}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::array{8}));
  }

  {
    constexpr auto s = kumi::split(t, 8_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), t);
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::array<int, 0>{}));
  }
};
