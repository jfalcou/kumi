//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/rotate.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check result::rotate_left<R,Array> behavior")
{
  using array_t = kumi::array<int, 4>;

  TTS_TYPE_IS((kumi::result::rotate_left_t<0, array_t>), array_t);
  TTS_TYPE_IS((kumi::result::rotate_left_t<1, array_t>), array_t);
  TTS_TYPE_IS((kumi::result::rotate_left_t<2, array_t>), array_t);
  TTS_TYPE_IS((kumi::result::rotate_left_t<kumi::size_v<array_t>, array_t>), array_t);
  TTS_TYPE_IS((kumi::result::rotate_left_t<1, kumi::array<>>), kumi::array<>);
};

TTS_CASE("Check rotate_left<I...>(array) behavior")
{
  auto t = kumi::array{1, 2, 3, 4};

  {
    auto s = kumi::rotate_left<0>(t);
    TTS_EQUAL(s, t);
  }
  {
    auto s = kumi::rotate_left<1>(t);
    TTS_EQUAL(s, (kumi::array{2, 3, 4, 1}));
  }

  {
    auto s = kumi::rotate_left<2>(t);
    TTS_EQUAL(s, (kumi::array{3, 4, 1, 2}));
  }

  {
    auto s = kumi::rotate_left<3>(t);
    TTS_EQUAL(s, (kumi::array{4, 1, 2, 3}));
  }

  {
    auto s = kumi::rotate_left<4>(t);
    TTS_EQUAL(s, t);
  }
};

TTS_CASE("Check rotate_left<I...>(array) constexpr behavior")
{
  constexpr auto t = kumi::array{1, 2, 3, 4};

  {
    constexpr auto s = kumi::rotate_left<0>(t);
    TTS_CONSTEXPR_EQUAL(s, t);
  }
  {
    constexpr auto s = kumi::rotate_left<1>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{2, 3, 4, 1}));
  }

  {
    constexpr auto s = kumi::rotate_left<2>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{3, 4, 1, 2}));
  }

  {
    constexpr auto s = kumi::rotate_left<3>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::array{4, 1, 2, 3}));
  }

  {
    constexpr auto s = kumi::rotate_left<4>(t);
    TTS_CONSTEXPR_EQUAL(s, t);
  }
};
