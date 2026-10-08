//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/record.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

using namespace kumi::literals;

TTS_CASE("Check adapted types model kumi::concepts::record_type concept")
{
  TTS_EXPECT(!kumi::concepts::record_type<tuple_box>);
  TTS_EXPECT(kumi::concepts::record_type<record_box>);

  TTS_EXPECT_NOT(kumi::concepts::record_type<tuple_box>);
  TTS_EXPECT(kumi::concepts::record_type<record_box>);
};

TTS_CASE("Check get methods on adapted types")
{
  using namespace kumi::literals;
  record_box rb = {1, 3.f, 'x'};

  TTS_EQUAL((field_value_of(get<0>(rb))), (1));
  TTS_EQUAL((field_value_of(get<1>(rb))), (3.f));
  TTS_EQUAL((field_value_of(get<2>(rb))), ('x'));

  TTS_EQUAL((get<"i"_id>(rb)), (1));
  TTS_EQUAL((get<"f"_id>(rb)), (3.f));
  TTS_EQUAL((get<"c"_id>(rb)), ('x'));
};

TTS_CASE("Check get return type on adapted types")
{
  using record_box_t = record_box;
  using crecord_box_t = record_box const;

  TTS_TYPE_IS((decltype(get<0>(std::declval<record_box_t>()))), (kumi::field<kumi::name<"i">, int>));
  TTS_TYPE_IS((decltype(get<1>(std::declval<record_box_t>()))), (kumi::field<kumi::name<"f">, float>));
  TTS_TYPE_IS((decltype(get<2>(std::declval<record_box_t>()))), (kumi::field<kumi::name<"c">, char>));

  TTS_TYPE_IS((decltype(get<"i"_id>(std::declval<record_box_t>()))), (int&&));
  TTS_TYPE_IS((decltype(get<"f"_id>(std::declval<record_box_t>()))), (float&&));
  TTS_TYPE_IS((decltype(get<"c"_id>(std::declval<record_box_t>()))), (char&&));

  TTS_TYPE_IS((decltype(get<0>(std::declval<crecord_box_t>()))), (kumi::field<kumi::name<"i">, int const>));
  TTS_TYPE_IS((decltype(get<1>(std::declval<crecord_box_t>()))), (kumi::field<kumi::name<"f">, float const>));
  TTS_TYPE_IS((decltype(get<2>(std::declval<crecord_box_t>()))), (kumi::field<kumi::name<"c">, char const>));

  TTS_TYPE_IS((decltype(get<"i"_id>(std::declval<crecord_box_t>()))), (int const&&));
  TTS_TYPE_IS((decltype(get<"f"_id>(std::declval<crecord_box_t>()))), (float const&&));
  TTS_TYPE_IS((decltype(get<"c"_id>(std::declval<crecord_box_t>()))), (char const&&));
};
