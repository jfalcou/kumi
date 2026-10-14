//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/reverse.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check result::reverse<Array> behavior")
{
  using array_t = kumi::array<int, 4>;
  TTS_TYPE_IS((kumi::result::reverse_t<array_t>), array_t);
};

TTS_CASE("Check reverse(array) behavior")
{
  auto t = kumi::array{1, 2, 3, 4};
  TTS_EQUAL(kumi::reverse(t), (kumi::array{4, 3, 2, 1}));
  TTS_EQUAL(kumi::reverse(kumi::array<>{}), (kumi::array{}));
  TTS_EQUAL(kumi::reverse(kumi::array{7}), (kumi::array{7}));
  TTS_EQUAL(kumi::reverse(std::move(t)), (kumi::array{4, 3, 2, 1}));
};

TTS_CASE("Check reverse(array) constexpr behavior")
{
  constexpr auto t = kumi::array{1, 2, 3, 4};
  TTS_CONSTEXPR_EQUAL(kumi::reverse(t), (kumi::array{4, 3, 2, 1}));
  TTS_CONSTEXPR_EQUAL(kumi::reverse(kumi::array<>{}), (kumi::array{}));
  TTS_CONSTEXPR_EQUAL(kumi::reverse(kumi::array{7}), (kumi::array{7}));
};
