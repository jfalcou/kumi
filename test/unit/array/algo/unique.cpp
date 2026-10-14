//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/unique.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

// unique/all_unique remove adjacent duplicated *types*. As an array is homogeneous (all elements
// share the same type), they collapse to a single-element array holding the first element.
TTS_CASE("Check result::unique/all_unique<Array> behavior")
{
  TTS_TYPE_IS((kumi::result::unique_t<kumi::array<int, 6>>), (kumi::array<int, 1>));
  TTS_TYPE_IS((kumi::result::all_unique_t<kumi::array<int, 6>>), (kumi::array<int, 1>));
};

TTS_CASE("Check runtime kumi::unique behavior on arrays")
{
  TTS_EQUAL(kumi::unique(kumi::array{}), kumi::array{});
  TTS_EQUAL(kumi::unique(kumi::array{1}), (kumi::array{1}));
  TTS_EQUAL(kumi::unique(kumi::array{1, 1, 2, 2, 2, 3, 3, 4}), (kumi::array{1}));
  TTS_EQUAL(kumi::unique(kumi::array{1, 2, 2, 3, 3, 3, 4, 4}), (kumi::array{1}));
  TTS_EQUAL(kumi::unique(kumi::array{5, 5, 5}), (kumi::array{5}));
};

TTS_CASE("Check runtime kumi::all_unique behavior on arrays")
{
  TTS_EQUAL(kumi::all_unique(kumi::array{}), kumi::array{});
  TTS_EQUAL(kumi::all_unique(kumi::array{1}), (kumi::array{1}));
  TTS_EQUAL(kumi::all_unique(kumi::array{1, 1, 2, 2, 2, 3, 3, 4}), (kumi::array{1}));
  TTS_EQUAL(kumi::all_unique(kumi::array{1, 2, 2, 3, 3, 3, 4, 4}), (kumi::array{1}));
};

TTS_CASE("Check constexpr kumi::unique behavior on arrays")
{
  TTS_CONSTEXPR_EQUAL(kumi::unique(kumi::array{}), kumi::array{});
  TTS_CONSTEXPR_EQUAL(kumi::unique(kumi::array{1, 1, 2, 2, 2, 3, 3, 4}), (kumi::array{1}));
  TTS_CONSTEXPR_EQUAL(kumi::all_unique(kumi::array{1, 2, 2, 3, 3, 3, 4, 4}), (kumi::array{1}));
};
