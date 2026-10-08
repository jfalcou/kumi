//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

using namespace kumi::literals;

TTS_CASE("Check adapted types model kumi::concepts::product_type concept")
{
  TTS_EXPECT(kumi::concepts::product_type<tuple_box>);
  TTS_EXPECT(kumi::concepts::product_type<record_box>);

  TTS_EXPECT_NOT(kumi::concepts::record_type<tuple_box>);
  TTS_EXPECT(kumi::concepts::record_type<record_box>);
};

TTS_CASE("Check get methods on adapted types")
{
  using namespace kumi::literals;
  tuple_box tb = {1, 3.f, 'x'};

  TTS_EQUAL((get<0>(tb)), 1);
  TTS_EQUAL((get<1>(tb)), 3.f);
  TTS_EQUAL((get<2>(tb)), 'x');

  TTS_EXPECT_NOT_COMPILES(tb, { get<"i">(tb); });
  TTS_EXPECT_NOT_COMPILES(tb, { get<"f">(tb); });
  TTS_EXPECT_NOT_COMPILES(tb, { get<"c">(tb); });
};

TTS_CASE("Check get return type on adapted types")
{
  using tuple_box_t = tuple_box;
  using ctuple_box_t = tuple_box const;

  TTS_TYPE_IS((decltype(get<0>(std::declval<tuple_box_t>()))), (int&&));
  TTS_TYPE_IS((decltype(get<1>(std::declval<tuple_box_t>()))), (float&&));
  TTS_TYPE_IS((decltype(get<2>(std::declval<tuple_box_t>()))), (char&&));

  TTS_TYPE_IS((decltype(get<0>(std::declval<ctuple_box_t>()))), (int const&&));
  TTS_TYPE_IS((decltype(get<1>(std::declval<ctuple_box_t>()))), (float const&&));
  TTS_TYPE_IS((decltype(get<2>(std::declval<ctuple_box_t>()))), (char const&&));
};
