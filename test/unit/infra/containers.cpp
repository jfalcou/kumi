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

#include <array>
#include <vector>
#include <span>

#include "test.hpp"

using v_t = std::vector<float>;
using d_t = std::span<double>;
using s_t = std::span<short, 10>;
using a_t = std::array<int, 10>;
using r_t = int[10];

TTS_CASE("Check kumi::concepts::containers behavior")
{
  TTS_EXPECT(kumi::concepts::container<v_t>);
  TTS_EXPECT(kumi::concepts::container<d_t>);

  TTS_EXPECT(kumi::concepts::container<s_t>);
  TTS_EXPECT(kumi::concepts::container<a_t>);
  TTS_EXPECT(kumi::concepts::container<r_t>);
};

TTS_CASE("Check kumi::concepts::static_containers behavior")
{
  TTS_EXPECT_NOT(kumi::concepts::static_container<v_t>);
  TTS_EXPECT_NOT(kumi::concepts::static_container<d_t>);

  TTS_EXPECT(kumi::concepts::static_container<s_t>);
  TTS_EXPECT(kumi::concepts::static_container<a_t>);
  TTS_EXPECT(kumi::concepts::static_container<r_t>);
};

TTS_CASE("Check kumi::container_size_v behavor")
{
  TTS_EQUAL((kumi::container_size_v<v_t>), kumi::_::invalid{});
  TTS_EQUAL((kumi::container_size_v<d_t>), kumi::_::invalid{});

  TTS_EQUAL((kumi::container_size_v<s_t>), (std::integral_constant<std::size_t, 10>{}));
  TTS_EQUAL((kumi::container_size_v<a_t>), (std::integral_constant<std::size_t, 10>{}));
  TTS_EQUAL((kumi::container_size_v<r_t>), (std::integral_constant<std::size_t, 10>{}));
};

TTS_CASE("Check kumi::container_type_t behavior")
{
  TTS_TYPE_IS((kumi::container_type_t<v_t>), float);
  TTS_TYPE_IS((kumi::container_type_t<d_t>), double);

  TTS_TYPE_IS((kumi::container_type_t<s_t>), short);
  TTS_TYPE_IS((kumi::container_type_t<a_t>), int);
  TTS_TYPE_IS((kumi::container_type_t<r_t>), int);
};
