//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/partition.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check result::filter_t<Func,Array> behavior")
{
  TTS_TYPE_IS((kumi::result::filter_t<std::is_integral, kumi::array<int, 0>>), (kumi::array<>));

  TTS_TYPE_IS((kumi::result::filter_t<std::is_integral, kumi::array<int, 4>>), (kumi::array<int, 4>));

  TTS_TYPE_IS((kumi::result::filter_t<std::is_pointer, kumi::array<int, 4>>), (kumi::array<>));
};

TTS_CASE("Check filter(kumi::array<int, 0>{}) behavior")
{
  TTS_EQUAL((kumi::filter<std::is_pointer>(kumi::array<int, 0>{})), (kumi::array<int, 0>{}));
};

TTS_CASE("Check filter() behavior with values")
{
  TTS_EQUAL(kumi::filter<std::is_integral>(kumi::array{1, 2, 3, 4}), (kumi::array{1, 2, 3, 4}));

  TTS_EQUAL(kumi::filter<std::is_floating_point>(kumi::array{1, 2, 3, 4}), (kumi::array<int, 0>{}));

  TTS_EQUAL(kumi::filter<std::is_pointer>(kumi::array{1, 2, 3, 4}), (kumi::array<int, 0>{}));

  auto t = kumi::array{moveonly{}, moveonly{}};
  TTS_EXPECT_COMPILES(t, { kumi::filter<is_moveonly_type>(std::move(t)); });
};
