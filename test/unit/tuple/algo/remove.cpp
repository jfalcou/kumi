//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <kumi/algorithm/extract.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check kumi::remove behavior on tuples")
{
  using namespace kumi::literals;

  kumi::tuple t = {'1', 2., 3.f, 4};

  TTS_EQUAL((kumi::remove(t, 0_c)), (kumi::tuple{}));
  TTS_EQUAL((kumi::remove(t, 0_c, 4_c)), (kumi::tuple{}));
  TTS_EQUAL((kumi::remove(t, 0_c, 3_c)), (kumi::tuple{4}));
  TTS_EQUAL((kumi::remove(t, 0_c, 2_c)), (kumi::tuple{3.f, 4}));
  TTS_EQUAL((kumi::remove(t, 0_c, 1_c)), (kumi::tuple{2., 3.f, 4}));
  TTS_EQUAL((kumi::remove(t, 0_c, 0_c)), (kumi::tuple{'1', 2., 3.f, 4}));
  TTS_EQUAL((kumi::remove(t, 1_c)), (kumi::tuple{'1'}));
  TTS_EQUAL((kumi::remove(t, 1_c, 4_c)), (kumi::tuple{'1'}));
  TTS_EQUAL((kumi::remove(t, 1_c, 3_c)), (kumi::tuple{'1', 4}));
  TTS_EQUAL((kumi::remove(t, 1_c, 2_c)), (kumi::tuple{'1', 3.f, 4}));
  TTS_EQUAL((kumi::remove(t, 1_c, 1_c)), (kumi::tuple{'1', 2., 3.f, 4}));
  TTS_EQUAL((kumi::remove(t, 2_c)), (kumi::tuple{'1', 2.}));
  TTS_EQUAL((kumi::remove(t, 2_c, 4_c)), (kumi::tuple{'1', 2.}));
  TTS_EQUAL((kumi::remove(t, 2_c, 3_c)), (kumi::tuple{'1', 2., 4}));
  TTS_EQUAL((kumi::remove(t, 2_c, 2_c)), (kumi::tuple{'1', 2., 3.f, 4}));
  TTS_EQUAL((kumi::remove(t, 3_c)), (kumi::tuple{'1', 2., 3.f}));
  TTS_EQUAL((kumi::remove(t, 3_c, 4_c)), (kumi::tuple{'1', 2., 3.f}));
  TTS_EQUAL((kumi::remove(t, 3_c, 3_c)), (kumi::tuple{'1', 2., 3.f, 4}));
  TTS_EQUAL((kumi::remove(t, 4_c)), (kumi::tuple{'1', 2., 3.f, 4}));
  TTS_EQUAL((kumi::remove(t, 4_c, 4_c)), (kumi::tuple{'1', 2., 3.f, 4}));

  TTS_EQUAL((kumi::remove(t, 0_c, 4_c, 1_c)), (kumi::tuple{}));
  TTS_EQUAL((kumi::remove(t, 0_c, 3_c, 2_c)), (kumi::tuple{2., 4}));
  TTS_EQUAL((kumi::remove(t, 0_c, 2_c, 2_c)), (kumi::tuple{2., 3.f, 4}));
  TTS_EQUAL((kumi::remove(t, 0_c, 1_c, 3_c)), (kumi::tuple{2., 3.f, 4}));
  TTS_EQUAL((kumi::remove(t, 0_c, 0_c, 4_c)), (kumi::tuple{'1', 2., 3.f, 4}));

  TTS_EQUAL((kumi::remove(std::move(t), 0_c)), (kumi::tuple{}));

  kumi::tuple t2 = {moveonly{}, 3., 'f'};
  TTS_EXPECT_COMPILES(t2, { kumi::remove(std::move(t2), 2_c); });
};

TTS_CASE("Check kumi::remove constexpr behavior on tuples")
{
  using namespace kumi::literals;

  constexpr kumi::tuple t = {'1', 2., 3.f, 4};

  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c)), (kumi::tuple{}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 4_c)), (kumi::tuple{}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 3_c)), (kumi::tuple{4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 2_c)), (kumi::tuple{3.f, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 1_c)), (kumi::tuple{2., 3.f, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 0_c)), (kumi::tuple{'1', 2., 3.f, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 1_c)), (kumi::tuple{'1'}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 1_c, 4_c)), (kumi::tuple{'1'}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 1_c, 3_c)), (kumi::tuple{'1', 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 1_c, 2_c)), (kumi::tuple{'1', 3.f, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 1_c, 1_c)), (kumi::tuple{'1', 2., 3.f, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 2_c)), (kumi::tuple{'1', 2.}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 2_c, 4_c)), (kumi::tuple{'1', 2.}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 2_c, 3_c)), (kumi::tuple{'1', 2., 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 2_c, 2_c)), (kumi::tuple{'1', 2., 3.f, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 3_c)), (kumi::tuple{'1', 2., 3.f}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 3_c, 4_c)), (kumi::tuple{'1', 2., 3.f}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 3_c, 3_c)), (kumi::tuple{'1', 2., 3.f, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 4_c)), (kumi::tuple{'1', 2., 3.f, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 4_c, 4_c)), (kumi::tuple{'1', 2., 3.f, 4}));

  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 4_c, 1_c)), (kumi::tuple{}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 3_c, 2_c)), (kumi::tuple{2., 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 2_c, 2_c)), (kumi::tuple{2., 3.f, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 1_c, 3_c)), (kumi::tuple{2., 3.f, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(t, 0_c, 0_c, 4_c)), (kumi::tuple{'1', 2., 3.f, 4}));
};
