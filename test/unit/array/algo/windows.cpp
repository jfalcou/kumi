//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/tiler.hpp>
#include <kumi/algorithm/for_each.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check kumi::result::windows_t behavior on arrays")
{
  using t1 = kumi::array<int, 5>;
  TTS_TYPE_IS((kumi::result::windows_t<1, t1>),
              (kumi::tuple<kumi::array<int, 1>, kumi::array<int, 1>, kumi::array<int, 1>, kumi::array<int, 1>,
                           kumi::array<int, 1>>));
  using t2 = kumi::array<int, 4>;
  TTS_TYPE_IS((kumi::result::windows_t<2, t2>),
              (kumi::tuple<kumi::array<int, 2>, kumi::array<int, 2>, kumi::array<int, 2>>));
};

TTS_CASE("Check runtime kumi::windows behavior on arrays")
{
  auto t1 = kumi::array{1, 3, 5, 7, 9};
  auto t2 = kumi::array{112, 18, 55, 22};

  TTS_EQUAL((kumi::windows<1>(t1)),
            (kumi::tuple{kumi::array{1}, kumi::array{3}, kumi::array{5}, kumi::array{7}, kumi::array{9}}));

  TTS_EQUAL((kumi::windows<2>(t2)), (kumi::tuple{kumi::array{112, 18}, kumi::array{18, 55}, kumi::array{55, 22}}));

  auto t4 = kumi::array{moveonly{}, moveonly{}, moveonly{}, moveonly{}};
  TTS_EXPECT_COMPILES(t4, { kumi::windows<2>(std::move(t4)); });
};

TTS_CASE("Check constexpr kumi::windows behavior")
{
  constexpr auto t1 = kumi::array{1, 3, 5, 7, 9};
  constexpr auto t2 = kumi::array{112, 18, 55, 22};

  TTS_CONSTEXPR_EQUAL((kumi::windows<1>(t1)),
                      (kumi::tuple{kumi::array{1}, kumi::array{3}, kumi::array{5}, kumi::array{7}, kumi::array{9}}));
  TTS_CONSTEXPR_EQUAL((kumi::windows<2>(t2)),
                      (kumi::tuple{kumi::array{112, 18}, kumi::array{18, 55}, kumi::array{55, 22}}));
};
