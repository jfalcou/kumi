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

TTS_CASE("Check tuple::as_flat_ptr function behavior")
{
  auto t = kumi::tuple{3.25f, kumi::tuple{2., kumi::tuple{2., 1, short{55}}, short{55}}, 'a'};
  auto f = kumi::as_flat_ptr(t);

  TTS_EQUAL(get<0>(f), &get<0>(t));
  TTS_EQUAL(get<1>(f), &get<0>(get<1>(t)));
  TTS_EQUAL(get<2>(f), &get<0>(get<1>(get<1>(t))));
  TTS_EQUAL(get<3>(f), &get<1>(get<1>(get<1>(t))));
  TTS_EQUAL(get<4>(f), &get<2>(get<1>(get<1>(t))));
  TTS_EQUAL(get<5>(f), &get<2>(get<1>(t)));
  TTS_EQUAL(get<6>(f), &get<2>(t));
};
