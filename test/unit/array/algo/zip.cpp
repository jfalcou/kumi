//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/zip.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check result::zip/zip_min/zip_max<Array...> behavior")
{
  using arr1_t = kumi::array<int, 3>;
  using arr2_t = kumi::array<int, 3>;

  TTS_TYPE_IS((kumi::result::zip_t<arr1_t, arr2_t>),
              (kumi::tuple<kumi::array<int, 2>, kumi::array<int, 2>, kumi::array<int, 2>>));

  TTS_TYPE_IS((kumi::result::zip_t<arr1_t, arr2_t, arr2_t>),
              (kumi::tuple<kumi::array<int, 3>, kumi::array<int, 3>, kumi::array<int, 3>>));

  using one_element_t = kumi::array<int, 1>;
  TTS_TYPE_IS((kumi::result::zip_t<one_element_t>), (kumi::tuple<kumi::array<int, 1>>));
  TTS_TYPE_IS((kumi::result::zip_max_t<one_element_t>), (kumi::tuple<kumi::array<int, 1>>));
  TTS_TYPE_IS((kumi::result::zip_min_t<one_element_t>), (kumi::tuple<kumi::array<int, 1>>));

  using arr4_t = kumi::array<int, 5>;
  using arr5_t = kumi::array<int, 3>;

  TTS_TYPE_IS((kumi::result::zip_min_t<arr4_t, arr5_t>),
              (kumi::tuple<kumi::array<int, 2>, kumi::array<int, 2>, kumi::array<int, 2>>));
};

TTS_CASE("Check array::zip/zip_min/zip_max behavior")
{
  using kumi::array;

  auto numbers = array{1, 2, 3, 4};
  auto letters = array{5, 6, 7, 8};

  TTS_EQUAL((kumi::zip(array<int, 0>{}, array<int, 0>{})), kumi::tuple{});

  TTS_EQUAL((kumi::zip(numbers, letters)), (kumi::tuple{array{1, 5}, array{2, 6}, array{3, 7}, array{4, 8}}));

  TTS_EQUAL((kumi::zip_min(numbers, letters)), (kumi::tuple{array{1, 5}, array{2, 6}, array{3, 7}, array{4, 8}}));

  TTS_EQUAL((kumi::zip_max(numbers, letters)), (kumi::tuple{array{1, 5}, array{2, 6}, array{3, 7}, array{4, 8}}));

  auto numbers2 = array{1, 2, 3};
  auto letters2 = array{4, 5, 6};
  auto ratio = array{7, 8, 9};

  TTS_EQUAL((kumi::zip(numbers2, letters2, ratio)), (kumi::tuple{array{1, 4, 7}, array{2, 5, 8}, array{3, 6, 9}}));

  TTS_EQUAL((kumi::zip(std::move(numbers2), std::move(letters2), std::move(ratio))),
            (kumi::tuple{array{1, 4, 7}, array{2, 5, 8}, array{3, 6, 9}}));
};

TTS_CASE("Check array::zip/zip_min/zip_max constexpr behavior")
{
  using kumi::array;

  constexpr auto numbers = array{1, 2, 3, 4};
  constexpr auto letters = array{5, 6, 7, 8};

  TTS_CONSTEXPR_EQUAL((kumi::zip(numbers, letters)), (kumi::tuple{array{1, 5}, array{2, 6}, array{3, 7}, array{4, 8}}));

  TTS_CONSTEXPR_EQUAL((kumi::zip_min(numbers, letters)),
                      (kumi::tuple{array{1, 5}, array{2, 6}, array{3, 7}, array{4, 8}}));

  TTS_CONSTEXPR_EQUAL((kumi::zip_max(numbers, letters)),
                      (kumi::tuple{array{1, 5}, array{2, 6}, array{3, 7}, array{4, 8}}));

  constexpr auto numbers2 = array{1, 2, 3};
  constexpr auto letters2 = array{4, 5, 6};
  constexpr auto ratio = array{7, 8, 9};

  TTS_CONSTEXPR_EQUAL((kumi::zip(numbers2, letters2, ratio)),
                      (kumi::tuple{array{1, 4, 7}, array{2, 5, 8}, array{3, 6, 9}}));
};
