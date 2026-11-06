//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/flatten.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check kumi::result::compress behavior on arrays")
{
  TTS_TYPE_IS((kumi::result::compress_t<kumi::array<int, 0>>), (kumi::array<int, 0>));

  TTS_TYPE_IS((kumi::result::compress_t<kumi::array<kumi::array<int, 3>, 1>>), (kumi::array<int, 3>));

  TTS_TYPE_IS((kumi::result::compress_t<kumi::array<kumi::array<int, 3>, 1>>), (kumi::array<int, 3>));

  TTS_TYPE_IS((kumi::result::compress_t<kumi::array<kumi::array<int, 3>, 3>>), (kumi::array<kumi::array<int, 3>, 3>));
};

TTS_CASE("Check kumi::compress behavior on arrays")
{
  auto empty = kumi::array<int, 0>{};
  auto singleton = kumi::array{kumi::array{1, 2, 3}};
  auto nested = kumi::array{kumi::array{1, 2, 3}, kumi::array{4, 5, 6}};

  TTS_EQUAL(kumi::compress(empty), empty);
  TTS_EQUAL(kumi::compress(singleton), (kumi::array{1, 2, 3}));
  TTS_EQUAL(kumi::compress(nested), nested);

  auto t = kumi::array{moveonly{}, moveonly{}};
  TTS_EXPECT_COMPILES(t, { kumi::compress(std::move(t)); });
};

TTS_CASE("Check kumi::compress constexpr behavior on arrays")
{
  constexpr auto t0 = kumi::array{1, 2, 3};
  constexpr auto t1 = kumi::array{kumi::array{1, 2, 3}};
  constexpr auto empty = kumi::array<int, 0>{};

  TTS_CONSTEXPR_EQUAL(kumi::compress(empty), empty);
  TTS_CONSTEXPR_EQUAL(kumi::compress(t1), t0);
  TTS_CONSTEXPR_EQUAL(kumi::compress(t0), t0);
};
