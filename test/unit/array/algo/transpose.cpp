//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/transpose.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check result::transpose<Array> behavior")
{
  using row_t = kumi::array<int, 2>;
  using matrix_t = kumi::array<row_t, 2>;

  TTS_TYPE_IS((kumi::result::transpose_t<matrix_t>), (kumi::tuple<row_t, row_t>));

  using nested_t = kumi::array<kumi::array<int, 1>, 1>;
  TTS_TYPE_IS((kumi::result::transpose_t<nested_t>), (kumi::tuple<kumi::array<int, 1>>));
};

TTS_CASE("Check array::transpose behavior")
{
  using kumi::array;

  auto r1 = array{1, 2};
  auto r2 = array{3, 4};

  auto m = array{r1, r2};

  TTS_EQUAL((kumi::transpose(m)), (kumi::tuple{array{1, 3}, array{2, 4}}));
};

TTS_CASE("Check constexpr array::transpose behavior")
{
  using kumi::array;

  constexpr auto m = array{array{1, 2}, array{3, 4}};

  TTS_CONSTEXPR_EQUAL((kumi::transpose(m)), (kumi::tuple{array{1, 3}, array{2, 4}}));
};
