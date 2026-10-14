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

TTS_CASE("Check kumi::remove behavior on arrays")
{
  using namespace kumi::literals;

  kumi::array t = {1, 2, 3, 4};

  TTS_EQUAL((kumi::remove(t, 0_c)), (kumi::array<int, 0>{}));
  TTS_EQUAL((kumi::remove(t, 0_c, 4_c)), (kumi::array<int, 0>{}));
  TTS_EQUAL((kumi::remove(t, 0_c, 3_c)), (kumi::array{4}));
  TTS_EQUAL((kumi::remove(t, 0_c, 2_c)), (kumi::array{3, 4}));
  TTS_EQUAL((kumi::remove(t, 0_c, 1_c)), (kumi::array{2, 3, 4}));
  TTS_EQUAL((kumi::remove(t, 0_c, 0_c)), (kumi::array{1, 2, 3, 4}));
  TTS_EQUAL((kumi::remove(t, 1_c)), (kumi::array{1}));
  TTS_EQUAL((kumi::remove(t, 1_c, 4_c)), (kumi::array{1}));
  TTS_EQUAL((kumi::remove(t, 1_c, 3_c)), (kumi::array{1, 4}));
  TTS_EQUAL((kumi::remove(t, 1_c, 2_c)), (kumi::array{1, 3, 4}));
  TTS_EQUAL((kumi::remove(t, 1_c, 1_c)), (kumi::array{1, 2, 3, 4}));
  TTS_EQUAL((kumi::remove(t, 2_c)), (kumi::array{1, 2}));
  TTS_EQUAL((kumi::remove(t, 2_c, 4_c)), (kumi::array{1, 2}));
  TTS_EQUAL((kumi::remove(t, 2_c, 3_c)), (kumi::array{1, 2, 4}));
  TTS_EQUAL((kumi::remove(t, 2_c, 2_c)), (kumi::array{1, 2, 3, 4}));
  TTS_EQUAL((kumi::remove(t, 3_c)), (kumi::array{1, 2, 3}));
  TTS_EQUAL((kumi::remove(t, 3_c, 4_c)), (kumi::array{1, 2, 3}));
  TTS_EQUAL((kumi::remove(t, 3_c, 3_c)), (kumi::array{1, 2, 3, 4}));
  TTS_EQUAL((kumi::remove(t, 4_c)), (kumi::array{1, 2, 3, 4}));
  TTS_EQUAL((kumi::remove(t, 4_c, 4_c)), (kumi::array{1, 2, 3, 4}));

  TTS_EQUAL((kumi::remove(t, 0_c, 4_c, 1_c)), (kumi::array<int, 0>{}));
  TTS_EQUAL((kumi::remove(t, 0_c, 3_c, 2_c)), (kumi::array{2, 4}));
  TTS_EQUAL((kumi::remove(t, 0_c, 2_c, 2_c)), (kumi::array{2, 3, 4}));
  TTS_EQUAL((kumi::remove(t, 0_c, 1_c, 3_c)), (kumi::array{2, 3, 4}));
  TTS_EQUAL((kumi::remove(t, 0_c, 0_c, 4_c)), (kumi::array{1, 2, 3, 4}));

  TTS_EQUAL((kumi::remove(std::move(t), 0_c)), (kumi::array<int, 0>{}));
};

TTS_CASE("Check kumi::remove constexpr behavior on arrays")
{
  using namespace kumi::literals;

  constexpr kumi::array t = {1, 2, 3, 4};

  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c)), (kumi::array<int, 0>{}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 4_c)), (kumi::array<int, 0>{}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 3_c)), (kumi::array{4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 2_c)), (kumi::array{3, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 1_c)), (kumi::array{2, 3, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 0_c)), (kumi::array{1, 2, 3, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 1_c)), (kumi::array{1}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 1_c, 4_c)), (kumi::array{1}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 1_c, 3_c)), (kumi::array{1, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 1_c, 2_c)), (kumi::array{1, 3, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 1_c, 1_c)), (kumi::array{1, 2, 3, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 2_c)), (kumi::array{1, 2}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 2_c, 4_c)), (kumi::array{1, 2}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 2_c, 3_c)), (kumi::array{1, 2, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 2_c, 2_c)), (kumi::array{1, 2, 3, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 3_c)), (kumi::array{1, 2, 3}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 3_c, 4_c)), (kumi::array{1, 2, 3}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 3_c, 3_c)), (kumi::array{1, 2, 3, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 4_c)), (kumi::array{1, 2, 3, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 4_c, 4_c)), (kumi::array{1, 2, 3, 4}));

  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 4_c, 1_c)), (kumi::array<int, 0>{}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 3_c, 2_c)), (kumi::array{2, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 2_c, 2_c)), (kumi::array{2, 3, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 1_c, 3_c)), (kumi::array{2, 3, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 0_c, 4_c)), (kumi::array{1, 2, 3, 4}));
};
