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
#include <array>
#include <span>
#include <string>

struct my_product_type
{
  std::size_t n;
  std::size_t data;
  constexpr auto operator<=>(my_product_type const&) const = default;
};

template<std::size_t I> constexpr decltype(auto) get(my_product_type const& m) noexcept
{
  if constexpr (I == 0) return m.n;
  if constexpr (I == 1) return m.data;
}

template<std::size_t I> constexpr decltype(auto) get(my_product_type& m) noexcept
{
  if constexpr (I == 0) return m.n;
  if constexpr (I == 1) return m.data;
}

// Adapt as structured bindable type
template<> struct std::tuple_size<my_product_type> : std::integral_constant<std::size_t, 2>
{
};

template<std::size_t I> struct std::tuple_element<I, my_product_type>
{
  using type = std::size_t;
};

TTS_CASE("Check tuple to constructible type conversion")
{
  kumi::tuple in{std::size_t{9}, 13.37};

  TTS_EQUAL(kumi::from_tuple<arbitrary_struct>(in), (arbitrary_struct{9, 13.37}));
};

TTS_CASE("Check tuple to constructible type constexpr conversion")
{
  constexpr kumi::tuple in{std::size_t{9}, 13.37};

  TTS_CONSTEXPR_EQUAL(kumi::from_tuple<arbitrary_struct>(in), (arbitrary_struct{9, 13.37}));
};

TTS_CASE("Check type to tuple conversion")
{
  my_product_type in{9, 13};
  auto a = std::array{1, 2, 3, 4, 5};
  auto s = std::span{a};

  TTS_EQUAL(kumi::to_tuple(in), (kumi::tuple{std::size_t{9}, std::size_t{13}}));
  TTS_EQUAL(kumi::to_tuple(a), (kumi::tuple{1, 2, 3, 4, 5}));
  TTS_EQUAL(kumi::to_tuple(s), (kumi::tuple{1, 2, 3, 4, 5}));

  TTS_EQUAL(kumi::to_tuple(std::move(a)), (kumi::tuple{1, 2, 3, 4, 5}));
  TTS_EQUAL(kumi::to_tuple(std::move(s)), (kumi::tuple{1, 2, 3, 4, 5}));
};

TTS_CASE("Check type to tuple constexpr conversion")
{
  constexpr my_product_type in{9, 13};
  constexpr auto a = std::array{1, 2, 3, 4, 5};

  static constexpr auto a2 = std::array{1, 2, 3, 4, 5};
  constexpr auto s = std::span{a2};

  TTS_CONSTEXPR_EQUAL(kumi::to_tuple(in), (kumi::tuple{std::size_t{9}, std::size_t{13}}));
  TTS_CONSTEXPR_EQUAL(kumi::to_tuple(a), (kumi::tuple{1, 2, 3, 4, 5}));
  TTS_CONSTEXPR_EQUAL(kumi::to_tuple(s), (kumi::tuple{1, 2, 3, 4, 5}));
};

struct ExpInt
{
  explicit ExpInt(int) {}
};

void takes_tuple_int(kumi::tuple<int, int>);
void requires_cast(kumi::tuple<ExpInt, ExpInt>);
void takes_nullptr_t(std::nullptr_t);
void takes_unit(kumi::unit);
void takes_empty_tuple(kumi::tuple<>);

TTS_CASE("Check empty tuple conversions")
{
  kumi::unit n{};
  kumi::tuple empty_t{};

  TTS_EXPECT_COMPILES(empty_t, { takes_nullptr_t(empty_t); });
  TTS_EXPECT_COMPILES(empty_t, { takes_unit(empty_t); });
  TTS_EXPECT_COMPILES(empty_t, { takes_empty_tuple(empty_t); });

  TTS_EXPECT_COMPILES(n, { takes_nullptr_t(n); });
  TTS_EXPECT_COMPILES(n, { takes_unit(n); });
  TTS_EXPECT_COMPILES(n, { takes_empty_tuple(n); });
};

TTS_CASE("Check tuple to tuple conversion")
{
  kumi::tuple in{short{49}, 62.5f};

  TTS_EQUAL((static_cast<kumi::tuple<int, double>>(in)), (kumi::tuple{49, 62.5}));
  TTS_EQUAL((static_cast<kumi::tuple<char, int>>(in)), (kumi::tuple{'1', 62}));

  TTS_EQUAL(static_cast<kumi::tuple<std::string>>(kumi::tuple{"some text"}), kumi::tuple{std::string("some text")});

  TTS_EXPECT_COMPILES(in, { takes_tuple_int(in); });
  TTS_EXPECT_COMPILES(in, { requires_cast(static_cast<kumi::tuple<ExpInt, ExpInt>>(in)); });
  TTS_EXPECT_NOT_COMPILES(in, { requires_cast(in); });
};

TTS_CASE("Check tuple to tuple constexpr conversion")
{
  constexpr kumi::tuple in{short{49}, 62.5f};

  TTS_CONSTEXPR_EQUAL((static_cast<kumi::tuple<int, double>>(in)), (kumi::tuple{49, 62.5}));
  TTS_CONSTEXPR_EQUAL((static_cast<kumi::tuple<char, int>>(in)), (kumi::tuple{'1', 62}));
};
