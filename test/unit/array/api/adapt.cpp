//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include <array>
#include "test.hpp"

TTS_CASE("Check arrays model kumi::concepts::product_type concept")
{
  TTS_EXPECT((kumi::concepts::product_type<kumi::array<int, 4>>));
  TTS_EXPECT((kumi::concepts::product_type<std::array<int, 4>>));
  TTS_EXPECT((kumi::concepts::homogeneous_product_type<kumi::array<float, 3>>));
};

TTS_CASE("Check arrays behave like a product_type")
{
  auto r = kumi::apply([](auto... x) { return (x + ...); }, kumi::array{1, 2, 5, 4});
  TTS_EQUAL(r, 12);

  auto zz = kumi::zip(kumi::array{1, 2, 3}, kumi::array{4, 5, 6});
  auto zz_expected = kumi::tuple{kumi::array{1, 4}, kumi::array{2, 5}, kumi::array{3, 6}};
  TTS_EQUAL(zz, zz_expected);

  auto cc = kumi::cat(kumi::array{1, 2, 3}, kumi::array{4, 5, 6});
  TTS_EQUAL(cc, (kumi::array{1, 2, 3, 4, 5, 6}));
};

TTS_CASE("Check adapted external type behave like a product_type")
{
  auto r = kumi::apply([](auto... x) { return (x + ...); }, std::array{1, 2, 5, 4});
  TTS_EQUAL(r, 12);

  auto zz = kumi::zip(std::array{1, 2, 3}, std::array{4, 5, 6});
  auto zz_expected = kumi::tuple{kumi::array{1, 4}, kumi::array{2, 5}, kumi::array{3, 6}};
  TTS_EQUAL(zz, zz_expected);

  auto cc = kumi::cat(std::array{1, 2, 3}, std::array{4, 5, 6});
  TTS_EQUAL(cc, (kumi::array{1, 2, 3, 4, 5, 6}));
};
