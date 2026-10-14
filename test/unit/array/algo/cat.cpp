//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/cat.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check result::cat<Array...> behavior")
{
  TTS_TYPE_IS((kumi::result::cat_t<kumi::array<>, kumi::array<int, 4>>), (kumi::array<int, 4>));
  TTS_TYPE_IS((kumi::result::cat_t<kumi::array<int, 1>, kumi::array<int, 3>>), (kumi::array<int, 4>));
  TTS_TYPE_IS((kumi::result::cat_t<kumi::array<int, 1>, kumi::array<int, 1>, kumi::array<int, 2>>),
              (kumi::array<int, 4>));
  TTS_TYPE_IS((kumi::result::cat_t<kumi::array<int, 2>, kumi::array<int, 3>>), (kumi::array<int, 5>));
};

TTS_CASE("Check cat(array) behavior")
{
  TTS_EQUAL((kumi::cat(kumi::array{}, kumi::array{})), (kumi::array{}));
  TTS_EQUAL((kumi::cat(kumi::array{1, 2}, kumi::array{})), (kumi::array{1, 2}));
  TTS_EQUAL((kumi::cat(kumi::array{}, kumi::array{1, 2})), (kumi::array{1, 2}));
  TTS_EQUAL((kumi::cat(kumi::array{1}, kumi::array{2, 3, 4})), (kumi::array{1, 2, 3, 4}));
  TTS_EQUAL((kumi::cat(kumi::array{1, 2}, kumi::array{3, 4})), (kumi::array{1, 2, 3, 4}));
  TTS_EQUAL((kumi::cat(kumi::array{1, 2}, kumi::array{3, 4}, kumi::array{5, 6, 7})),
            (kumi::array{1, 2, 3, 4, 5, 6, 7}));
};

TTS_CASE("Check cat(array) constexpr behavior")
{
  TTS_CONSTEXPR_EQUAL((kumi::cat(kumi::array{}, kumi::array{})), (kumi::array{}));
  TTS_CONSTEXPR_EQUAL((kumi::cat(kumi::array{1, 2}, kumi::array{})), (kumi::array{1, 2}));
  TTS_CONSTEXPR_EQUAL((kumi::cat(kumi::array{1}, kumi::array{2, 3, 4})), (kumi::array{1, 2, 3, 4}));
  TTS_CONSTEXPR_EQUAL((kumi::cat(kumi::array{1, 2}, kumi::array{3, 4}, kumi::array{5, 6, 7})),
                      (kumi::array{1, 2, 3, 4, 5, 6, 7}));
};
