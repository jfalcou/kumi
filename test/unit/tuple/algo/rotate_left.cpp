//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/tuple.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check result::rotate_left<R,Tuple> behavior")
{
  using tuple_t = kumi::tuple<char, short, int, double>;

  TTS_TYPE_IS((kumi::result::rotate_left_t<0, tuple_t>), tuple_t);
  TTS_TYPE_IS((kumi::result::rotate_left_t<1, tuple_t>), (kumi::tuple<short, int, double, char>));
  TTS_TYPE_IS((kumi::result::rotate_left_t<2, tuple_t>), (kumi::tuple<int, double, char, short>));
  TTS_TYPE_IS((kumi::result::rotate_left_t<kumi::size_v<tuple_t>, tuple_t>), tuple_t);
  TTS_TYPE_IS((kumi::result::rotate_left_t<1, kumi::tuple<>>), kumi::tuple<>);

  using nested_t = kumi::tuple<kumi::tuple<int, float>, int>;
  TTS_TYPE_IS((kumi::result::rotate_left_t<1, nested_t>), (kumi::tuple<int, kumi::tuple<int, float>>));
};

TTS_CASE("Check rotate_left<I...>(tuple) behavior")
{
  auto t = kumi::tuple{1, 2., 3.4f, '5'};

  {
    auto s = kumi::rotate_left<0>(t);
    TTS_EQUAL(s, t);
  }
  {
    auto s = kumi::rotate_left<1>(t);
    TTS_EQUAL(s, (kumi::tuple{2., 3.4f, '5', 1}));
  }

  {
    auto s = kumi::rotate_left<2>(t);
    TTS_EQUAL(s, (kumi::tuple{3.4f, '5', 1, 2.}));
  }

  {
    auto s = kumi::rotate_left<3>(t);
    TTS_EQUAL(s, (kumi::tuple{'5', 1, 2., 3.4f}));
  }

  {
    auto s = kumi::rotate_left<4>(t);
    TTS_EQUAL(s, t);
  }
};

TTS_CASE("Check rotate_left<I...>(tuple) constexpr behavior")
{
  constexpr auto t = kumi::tuple{1, 2., 3.4f, '5'};

  {
    constexpr auto s = kumi::rotate_left<0>(t);
    TTS_CONSTEXPR_EQUAL(s, t);
  }
  {
    constexpr auto s = kumi::rotate_left<1>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{2., 3.4f, '5', 1}));
  }

  {
    constexpr auto s = kumi::rotate_left<2>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{3.4f, '5', 1, 2.}));
  }

  {
    constexpr auto s = kumi::rotate_left<3>(t);
    TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{'5', 1, 2., 3.4f}));
  }

  {
    constexpr auto s = kumi::rotate_left<4>(t);
    TTS_CONSTEXPR_EQUAL(s, t);
  }
};
