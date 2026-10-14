//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm/cartesian_product.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check result::cartesian_product<Array...> behavior")
{
  TTS_TYPE_IS(kumi::result::cartesian_product_t<>, kumi::tuple<>);

  TTS_TYPE_IS((kumi::result::cartesian_product_t<kumi::array<int, 3>>),
              (kumi::tuple<kumi::array<int, 1>, kumi::array<int, 1>, kumi::array<int, 1>>));

  TTS_TYPE_IS((kumi::result::cartesian_product_t<kumi::array<int, 2>, kumi::array<int, 3>>),
              (kumi::tuple<kumi::array<int, 2>, kumi::array<int, 2>, kumi::array<int, 2>, kumi::array<int, 2>,
                           kumi::array<int, 2>, kumi::array<int, 2>>));
};

TTS_CASE("Check cartesian_product() behavior")
{
  TTS_EQUAL(kumi::cartesian_product(), kumi::tuple<>{});
};

TTS_CASE("Check cartesian_product(arrays...) behavior")
{
  using kumi::array;

  auto t1 = kumi::array{1, 2};
  auto t2 = kumi::array{3, 4, 5};
  auto t3 = kumi::array{6, 7};

  auto cp = kumi::cartesian_product(t1, t2, t3);

  TTS_EQUAL(kumi::get<0>(kumi::get<0>(cp)), kumi::get<0>(t1));
  TTS_EQUAL(kumi::get<1>(kumi::get<0>(cp)), kumi::get<0>(t2));
  TTS_EQUAL(kumi::get<2>(kumi::get<0>(cp)), kumi::get<0>(t3));
  TTS_EQUAL(kumi::get<0>(kumi::get<1>(cp)), kumi::get<1>(t1));
  TTS_EQUAL(kumi::get<1>(kumi::get<1>(cp)), kumi::get<0>(t2));
  TTS_EQUAL(kumi::get<2>(kumi::get<1>(cp)), kumi::get<0>(t3));
  TTS_EQUAL(kumi::get<0>(kumi::get<2>(cp)), kumi::get<0>(t1));
  TTS_EQUAL(kumi::get<1>(kumi::get<2>(cp)), kumi::get<1>(t2));
  TTS_EQUAL(kumi::get<2>(kumi::get<2>(cp)), kumi::get<0>(t3));
  TTS_EQUAL(kumi::get<0>(kumi::get<3>(cp)), kumi::get<1>(t1));
  TTS_EQUAL(kumi::get<1>(kumi::get<3>(cp)), kumi::get<1>(t2));
  TTS_EQUAL(kumi::get<2>(kumi::get<3>(cp)), kumi::get<0>(t3));
  TTS_EQUAL(kumi::get<0>(kumi::get<4>(cp)), kumi::get<0>(t1));
  TTS_EQUAL(kumi::get<1>(kumi::get<4>(cp)), kumi::get<2>(t2));
  TTS_EQUAL(kumi::get<2>(kumi::get<4>(cp)), kumi::get<0>(t3));
  TTS_EQUAL(kumi::get<0>(kumi::get<5>(cp)), kumi::get<1>(t1));
  TTS_EQUAL(kumi::get<1>(kumi::get<5>(cp)), kumi::get<2>(t2));
  TTS_EQUAL(kumi::get<2>(kumi::get<5>(cp)), kumi::get<0>(t3));
  TTS_EQUAL(kumi::get<0>(kumi::get<6>(cp)), kumi::get<0>(t1));
  TTS_EQUAL(kumi::get<1>(kumi::get<6>(cp)), kumi::get<0>(t2));
  TTS_EQUAL(kumi::get<2>(kumi::get<6>(cp)), kumi::get<1>(t3));
  TTS_EQUAL(kumi::get<0>(kumi::get<7>(cp)), kumi::get<1>(t1));
  TTS_EQUAL(kumi::get<1>(kumi::get<7>(cp)), kumi::get<0>(t2));
  TTS_EQUAL(kumi::get<2>(kumi::get<7>(cp)), kumi::get<1>(t3));
  TTS_EQUAL(kumi::get<0>(kumi::get<8>(cp)), kumi::get<0>(t1));
  TTS_EQUAL(kumi::get<1>(kumi::get<8>(cp)), kumi::get<1>(t2));
  TTS_EQUAL(kumi::get<2>(kumi::get<8>(cp)), kumi::get<1>(t3));
  TTS_EQUAL(kumi::get<0>(kumi::get<9>(cp)), kumi::get<1>(t1));
  TTS_EQUAL(kumi::get<1>(kumi::get<9>(cp)), kumi::get<1>(t2));
  TTS_EQUAL(kumi::get<2>(kumi::get<9>(cp)), kumi::get<1>(t3));
  TTS_EQUAL(kumi::get<0>(kumi::get<10>(cp)), kumi::get<0>(t1));
  TTS_EQUAL(kumi::get<1>(kumi::get<10>(cp)), kumi::get<2>(t2));
  TTS_EQUAL(kumi::get<2>(kumi::get<10>(cp)), kumi::get<1>(t3));
  TTS_EQUAL(kumi::get<0>(kumi::get<11>(cp)), kumi::get<1>(t1));
  TTS_EQUAL(kumi::get<1>(kumi::get<11>(cp)), kumi::get<2>(t2));
  TTS_EQUAL(kumi::get<2>(kumi::get<11>(cp)), kumi::get<1>(t3));
};
