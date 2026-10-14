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
#include <sstream>
#include <type_traits>
#include "test.hpp"

TTS_CASE("Check that the empty power type is kumi::array<void, 0>")
{
  TTS_TYPE_IS((kumi::array<>), (kumi::array<void, 0>));
  TTS_TYPE_IS((decltype(kumi::array{})), (kumi::array<void, 0>));

  TTS_CONSTEXPR_EXPECT((kumi::concepts::power_type<kumi::array<>>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::empty_product_type<kumi::array<>>));
  TTS_CONSTEXPR_EXPECT((kumi::concepts::unit_type<kumi::array<>>));
};

TTS_CASE("Check kumi::array<> basic properties")
{
  constexpr auto e = kumi::array<>{};

  static_assert(e.size() == 0);
  static_assert(e.empty());

  TTS_CONSTEXPR_EQUAL(e.size(), 0ULL);
  TTS_CONSTEXPR_EXPECT(e.empty());
};

TTS_CASE("Check kumi::array<> printable as []")
{
  std::stringstream ss;
  kumi::array<> e{};

  ss << e;

  TTS_EQUAL(ss.str(), "[]");
};

TTS_CASE("Check kumi::array<> equality and comparison")
{
  constexpr kumi::array<> e0{};
  constexpr kumi::array<> e1{};

  TTS_CONSTEXPR_EXPECT(e0 == e1);
  TTS_CONSTEXPR_EXPECT(!(e0 != e1));
  TTS_CONSTEXPR_EXPECT(!(e0 < e1));
  TTS_CONSTEXPR_EXPECT(e0 <= e1);
  TTS_CONSTEXPR_EXPECT(e0 >= e1);

  TTS_CONSTEXPR_EXPECT((e0 <=> e1) == std::strong_ordering::equal);
};

TTS_CASE("Check kumi::array<> interconversion with other unit types")
{
  TTS_CONSTEXPR_EXPECT((std::convertible_to<kumi::array<>, kumi::unit>));
  TTS_CONSTEXPR_EXPECT((std::convertible_to<kumi::array<>, std::nullptr_t>));
  TTS_CONSTEXPR_EXPECT((std::convertible_to<kumi::array<>, kumi::tuple<>>));

  TTS_CONSTEXPR_EXPECT((std::convertible_to<kumi::unit, kumi::array<>>));
};
