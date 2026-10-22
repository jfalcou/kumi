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
#include <array>
#include <span>

// TTS_CASE("Check array to constructible type conversion")
//{
//   kumi::array<std::size_t, 2> in{9, 13};
//
//   TTS_EQUAL(kumi::from_array<arbitrary_struct>(in), (arbitrary_struct{9, 13}));
// };

// TTS_CASE("Check array to constructible type constexpr conversion")
//{
//   constexpr kumi::array<std::size_t, 2> in{9, 13};
//
//   TTS_CONSTEXPR_EQUAL(kumi::from_array<arbitrary_struct>(in), (arbitrary_struct{9, 13}));
// };

TTS_CASE("Check type to array conversion")
{
  auto a = std::array{1, 2, 3, 4, 5};
  auto s = std::span{a};
  auto t = kumi::tuple{1, 2, 3, 4, 5};

  TTS_EQUAL(kumi::to_array(a), (kumi::array{1, 2, 3, 4, 5}));
  TTS_EQUAL(kumi::to_array(s), (kumi::array{1, 2, 3, 4, 5}));
  TTS_EQUAL(kumi::to_array(t), (kumi::array{1, 2, 3, 4, 5}));

  TTS_EQUAL(kumi::to_array(std::move(a)), (kumi::array{1, 2, 3, 4, 5}));
  TTS_EQUAL(kumi::to_array(std::move(s)), (kumi::array{1, 2, 3, 4, 5}));
  TTS_EQUAL(kumi::to_array(std::move(t)), (kumi::array{1, 2, 3, 4, 5}));
};

TTS_CASE("Check type to array constexpr conversion")
{
  constexpr auto a = std::array{1, 2, 3, 4, 5};
  constexpr auto t = kumi::tuple{1, 2, 3, 4, 5};

  static constexpr auto a2 = std::array{1, 2, 3, 4, 5};
  constexpr auto s = std::span{a2};

  TTS_CONSTEXPR_EQUAL(kumi::to_array(a), (kumi::array{1, 2, 3, 4, 5}));
  TTS_CONSTEXPR_EQUAL(kumi::to_array(s), (kumi::array{1, 2, 3, 4, 5}));
  TTS_CONSTEXPR_EQUAL(kumi::to_array(t), (kumi::array{1, 2, 3, 4, 5}));
};

struct ExpInt
{
  explicit ExpInt(int) {}
};

void takes_array_int(kumi::array<int, 2>);
void requires_cast(kumi::array<ExpInt, 2>);
void takes_nullptr_t(std::nullptr_t);
void takes_unit(kumi::unit);
void takes_empty_array(kumi::array<>);

TTS_CASE("Check empty array conversions")
{
  kumi::unit n{};
  kumi::array empty_a{};

  TTS_EXPECT_COMPILES(empty_a, { takes_nullptr_t(empty_a); });
  TTS_EXPECT_COMPILES(empty_a, { takes_unit(empty_a); });
  TTS_EXPECT_COMPILES(empty_a, { takes_empty_array(empty_a); });

  TTS_EXPECT_COMPILES(n, { takes_nullptr_t(n); });
  TTS_EXPECT_COMPILES(n, { takes_unit(n); });
  TTS_EXPECT_COMPILES(n, { takes_empty_array(n); });
};

TTS_CASE("Check array to array conversion")
{
  kumi::array<short, 2> in{short{49}, short{62}};

  TTS_EQUAL((static_cast<kumi::array<int, 2>>(in)), (kumi::array{49, 62}));

  TTS_EXPECT_COMPILES(in, { takes_array_int(in); });

  TTS_EXPECT_NOT_COMPILES(in, { requires_cast(in); });
};

TTS_CASE("Check array to array constexpr conversion")
{
  constexpr kumi::array<short, 2> in{short{49}, short{62}};

  TTS_CONSTEXPR_EQUAL((static_cast<kumi::array<int, 2>>(in)), (kumi::array{49, 62}));
};
