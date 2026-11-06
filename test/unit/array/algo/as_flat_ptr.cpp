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

TTS_CASE("Check array::as_flat_ptr on a flat array behavior")
{
  auto t = kumi::array{3.25, 1., 2., 5.};
  auto f = kumi::as_flat_ptr(t);

  TTS_TYPE_IS((decltype(f)), (kumi::array<double*, 4>));

  TTS_EQUAL(get<0>(f), &get<0>(t));
  TTS_EQUAL(get<1>(f), &get<1>(t));
  TTS_EQUAL(get<2>(f), &get<2>(t));
  TTS_EQUAL(get<3>(f), &get<3>(t));
};

TTS_CASE("Check array::as_flat_ptr on a nested array behavior")
{
  using kumi::array;
  auto t = array{array{1, 2, 3}, array{4, 5, 6}};
  auto f = kumi::as_flat_ptr(t);

  TTS_TYPE_IS((decltype(f)), (kumi::array<int*, 6>));

  TTS_EQUAL(get<0>(f), &get<0>(get<0>(t)));
  TTS_EQUAL(get<1>(f), &get<1>(get<0>(t)));
  TTS_EQUAL(get<2>(f), &get<2>(get<0>(t)));
  TTS_EQUAL(get<3>(f), &get<0>(get<1>(t)));
  TTS_EQUAL(get<4>(f), &get<1>(get<1>(t)));
  TTS_EQUAL(get<5>(f), &get<2>(get<1>(t)));
};
