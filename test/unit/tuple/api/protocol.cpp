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
  record_box rb = {1, 3.f, 'x'};

  TTS_EQUAL((get<0>(tb)), 1);
  TTS_EQUAL((get<1>(tb)), 3.f);
  TTS_EQUAL((get<2>(tb)), 'x');

  TTS_EXPECT_NOT_COMPILES(tb, { get<"i">(tb); });
  TTS_EXPECT_NOT_COMPILES(tb, { get<"f">(tb); });
  TTS_EXPECT_NOT_COMPILES(tb, { get<"c">(tb); });

  TTS_EQUAL((field_value_of(get<0>(rb))), (1));
  TTS_EQUAL((field_value_of(get<1>(rb))), (3.f));
  TTS_EQUAL((field_value_of(get<2>(rb))), ('x'));

  TTS_EQUAL((get<"i"_id>(rb)), (1));
  TTS_EQUAL((get<"f"_id>(rb)), (3.f));
  TTS_EQUAL((get<"c"_id>(rb)), ('x'));
};

TTS_CASE("Check get return type on adapted types")
{
  tuple_box tb = {1, 3.f, 'x'};
  record_box rb = {1, 3.f, 'x'};

  tuple_box const ctb = {1, 3.f, 'x'};
  record_box const crb = {1, 3.f, 'x'};

  TTS_TYPE_IS((decltype(get<0>(tb))), (int&));
  TTS_TYPE_IS((decltype(get<1>(tb))), (float&));
  TTS_TYPE_IS((decltype(get<2>(tb))), (char&));

  TTS_TYPE_IS((decltype(get<0>(rb))), (kumi::field<kumi::name<"i">, int&>));
  TTS_TYPE_IS((decltype(get<1>(rb))), (kumi::field<kumi::name<"f">, float&>));
  TTS_TYPE_IS((decltype(get<2>(rb))), (kumi::field<kumi::name<"c">, char&>));

  TTS_TYPE_IS((decltype(get<"i"_id>(rb))), (int&));
  TTS_TYPE_IS((decltype(get<"f"_id>(rb))), (float&));
  TTS_TYPE_IS((decltype(get<"c"_id>(rb))), (char&));

  TTS_TYPE_IS((decltype(get<0>(ctb))), (int const&));
  TTS_TYPE_IS((decltype(get<1>(ctb))), (float const&));
  TTS_TYPE_IS((decltype(get<2>(ctb))), (char const&));

  TTS_TYPE_IS((decltype(get<0>(crb))), (kumi::field<kumi::name<"i">, int const&>));
  TTS_TYPE_IS((decltype(get<1>(crb))), (kumi::field<kumi::name<"f">, float const&>));
  TTS_TYPE_IS((decltype(get<2>(crb))), (kumi::field<kumi::name<"c">, char const&>));

  TTS_TYPE_IS((decltype(get<"i"_id>(crb))), (int const&));
  TTS_TYPE_IS((decltype(get<"f"_id>(crb))), (float const&));
  TTS_TYPE_IS((decltype(get<"c"_id>(crb))), (char const&));
};
