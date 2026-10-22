//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

using namespace kumi::literals;

TTS_CASE("Check arrays model kumi::concepts::product_type concept")
{
  TTS_EXPECT((kumi::concepts::product_type<kumi::array<>>));
  TTS_EXPECT((kumi::concepts::product_type<kumi::array<int, 1>>));
  TTS_EXPECT((kumi::concepts::product_type<kumi::array<int, 4>>));

  TTS_EXPECT((kumi::concepts::power_type<kumi::array<>>));
  TTS_EXPECT((kumi::concepts::power_type<kumi::array<int, 4>>));

  // An array is homogeneous (a power type), not a record with named fields.
  TTS_EXPECT((kumi::concepts::homogeneous_product_type<kumi::array<int, 4>>));
  TTS_EXPECT_NOT((kumi::concepts::record_type<kumi::array<int, 4>>));
  TTS_EXPECT_NOT((kumi::concepts::record_type<kumi::array<>>));
};

TTS_CASE("Check get methods on arrays")
{
  kumi::array<int, 3> tb = {1, 2, 3};

  TTS_EQUAL(get<0>(tb), 1);
  TTS_EQUAL(get<1>(tb), 2);
  TTS_EQUAL(get<2>(tb), 3);

  // Elements are accessible through the index subscript operator too.
  TTS_EQUAL(tb[0_c], 1);
  TTS_EQUAL(tb[1_c], 2);
  TTS_EQUAL(tb[2_c], 3);

  // Arrays do not provide record-style identifier accessors.
  TTS_EXPECT_NOT_COMPILES(tb, { get<"i">(tb); });
};

TTS_CASE("Check get return type on arrays")
{
  using arr_t = kumi::array<int, 3>;
  using carr_t = kumi::array<int, 3> const;

  TTS_TYPE_IS((decltype(get<0>(std::declval<arr_t&>()))), (int&));
  TTS_TYPE_IS((decltype(get<0>(std::declval<arr_t>()))), (int&&));
  TTS_TYPE_IS((decltype(get<0>(std::declval<carr_t&>()))), (int const&));
  TTS_TYPE_IS((decltype(get<0>(std::declval<carr_t>()))), (int const&&));
};

TTS_CASE("Check structured binding on arrays")
{
  kumi::array<int, 3> a = {1, 2, 3};

  auto [x, y, z] = a;

  TTS_EQUAL(x, 1);
  TTS_EQUAL(y, 2);
  TTS_EQUAL(z, 3);
};
