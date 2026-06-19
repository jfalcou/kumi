//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/record.hpp>
#include <kumi/algorithm/extract.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check kumi::remove behavior on records")
{
  using namespace kumi::literals;

  kumi::record r = {"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4};

  TTS_EQUAL((kumi::remove(r, 0_c)), (kumi::record{}));
  TTS_EQUAL((kumi::remove(r, 0_c, 4_c)), (kumi::record{}));
  TTS_EQUAL((kumi::remove(r, 0_c, 3_c)), (kumi::record{"d"_id = 4}));
  TTS_EQUAL((kumi::remove(r, 0_c, 2_c)), (kumi::record{"c"_id = 3.f, "d"_id = 4}));
  TTS_EQUAL((kumi::remove(r, 0_c, 1_c)), (kumi::record{"b"_id = 2., "c"_id = 3.f, "d"_id = 4}));
  TTS_EQUAL((kumi::remove(r, 0_c, 0_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4}));
  TTS_EQUAL((kumi::remove(r, 1_c)), (kumi::record{"a"_id = '1'}));
  TTS_EQUAL((kumi::remove(r, 1_c, 4_c)), (kumi::record{"a"_id = '1'}));
  TTS_EQUAL((kumi::remove(r, 1_c, 3_c)), (kumi::record{"a"_id = '1', "d"_id = 4}));
  TTS_EQUAL((kumi::remove(r, 1_c, 2_c)), (kumi::record{"a"_id = '1', "c"_id = 3.f, "d"_id = 4}));
  TTS_EQUAL((kumi::remove(r, 1_c, 1_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4}));
  TTS_EQUAL((kumi::remove(r, 2_c)), (kumi::record{"a"_id = '1', "b"_id = 2.}));
  TTS_EQUAL((kumi::remove(r, 2_c, 4_c)), (kumi::record{"a"_id = '1', "b"_id = 2.}));
  TTS_EQUAL((kumi::remove(r, 2_c, 3_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "d"_id = 4}));
  TTS_EQUAL((kumi::remove(r, 2_c, 2_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4}));
  TTS_EQUAL((kumi::remove(r, 3_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f}));
  TTS_EQUAL((kumi::remove(r, 3_c, 4_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f}));
  TTS_EQUAL((kumi::remove(r, 3_c, 3_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4}));
  TTS_EQUAL((kumi::remove(r, 4_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4}));
  TTS_EQUAL((kumi::remove(r, 4_c, 4_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4}));

  TTS_EQUAL((kumi::remove(std::move(r), 0_c)), (kumi::record{}));

  kumi::record r2 = {"a"_id = moveonly{}, "b"_id = 3., "c"_id = 'f'};
  TTS_EXPECT_COMPILES(r2, { kumi::remove(std::move(r2), 2_c); });
};

TTS_CASE("Check kumi::remove constexpr behavior on records")
{
  using namespace kumi::literals;

  constexpr kumi::record r = {"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4};

  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 0_c)), (kumi::record{}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 0_c, 4_c)), (kumi::record{}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 0_c, 3_c)), (kumi::record{"d"_id = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 0_c, 2_c)), (kumi::record{"c"_id = 3.f, "d"_id = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 0_c, 1_c)), (kumi::record{"b"_id = 2., "c"_id = 3.f, "d"_id = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 0_c, 0_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 1_c)), (kumi::record{"a"_id = '1'}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 1_c, 4_c)), (kumi::record{"a"_id = '1'}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 1_c, 3_c)), (kumi::record{"a"_id = '1', "d"_id = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 1_c, 2_c)), (kumi::record{"a"_id = '1', "c"_id = 3.f, "d"_id = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 1_c, 1_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 2_c)), (kumi::record{"a"_id = '1', "b"_id = 2.}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 2_c, 4_c)), (kumi::record{"a"_id = '1', "b"_id = 2.}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 2_c, 3_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "d"_id = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 2_c, 2_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 3_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 3_c, 4_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 3_c, 3_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 4_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4}));
  TTS_CONSTEXPR_EQUAL((kumi::remove(r, 4_c, 4_c)), (kumi::record{"a"_id = '1', "b"_id = 2., "c"_id = 3.f, "d"_id = 4}));
};
