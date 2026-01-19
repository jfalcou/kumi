//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check runtime kumi::iota behavior")
{
  TTS_EQUAL(kumi::iota<1>(1), (kumi::tuple{1}));
  TTS_EQUAL(kumi::iota<2>(2.f), (kumi::tuple{2.f, 3.f}));
  TTS_EQUAL(kumi::iota<3>(3.), (kumi::tuple{3., 4., 5.}));
  TTS_EQUAL(kumi::iota<7>('0'), (kumi::tuple{'0', '1', '2', '3', '4', '5', '6'}));
};

TTS_CASE("Check constexpr kumi::iota behavior")
{
  TTS_CONSTEXPR_EQUAL(kumi::iota<1>(1), (kumi::tuple{1}));
  TTS_CONSTEXPR_EQUAL(kumi::iota<2>(2.f), (kumi::tuple{2.f, 3.f}));
  TTS_CONSTEXPR_EQUAL(kumi::iota<3>(3.), (kumi::tuple{3., 4., 5.}));
  TTS_CONSTEXPR_EQUAL(kumi::iota<7>('0'), (kumi::tuple{'0', '1', '2', '3', '4', '5', '6'}));
};
