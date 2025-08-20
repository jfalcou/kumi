//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

TTS_CASE("Check result::reverse<Tuple> behavior")
{
  using tuple_t = kumi::tuple<char,short,int,double>;

  TTS_TYPE_IS( (kumi::result::reverse_t<tuple_t>), (kumi::tuple<double,int,short,char>) );
};

TTS_CASE("Check reverse(tuple) behavior")
{
  auto t = kumi::tuple {1, 2., 3.4f, '5'};
  auto t2 = kumi::tuple { 1, 'x', moveonly{}};

  TTS_EQUAL(kumi::reverse(t), (kumi::tuple {'5', 3.4f, 2., 1 }));
  TTS_EQUAL(kumi::reverse(kumi::tuple<>{}), (kumi::tuple{}));
  TTS_EQUAL(kumi::reverse(std::move(t)), (kumi::tuple{'5', 3.4f, 2., 1 }));
  TTS_EXPECT_COMPILES(t2, {kumi::reverse(std::move(t2)); });
};

TTS_CASE("Check reverse(tuple) constexpr behavior")
{
  constexpr auto t = kumi::tuple {1, 2., 3.4f, '5'};
  TTS_CONSTEXPR_EQUAL(kumi::reverse(t), (kumi::tuple {'5', 3.4f, 2., 1 }));
  TTS_CONSTEXPR_EQUAL(kumi::reverse(kumi::tuple<>{}), (kumi::tuple{}));
};
