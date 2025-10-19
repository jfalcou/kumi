//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>
#include <string>
#include <compare>

#define KUMI_NO_STD_ADAPTORS

struct my_struct
{
  std::size_t n;
  double      data;
  constexpr auto operator<=>(my_struct const&) const = default;
};

struct my_product_type
{
  std::size_t n;
  std::size_t data;
  constexpr auto operator<=>(my_product_type const&) const = default;
};

template<std::size_t I>
constexpr decltype(auto) get(my_product_type const& m) noexcept
{
  if constexpr (I == 0) return m.n;
  if constexpr (I == 1) return m.data;
}

template<std::size_t I>
constexpr decltype(auto) get(my_product_type & m) noexcept
{
  if constexpr (I == 0) return m.n;
  if constexpr (I == 1) return m.data;
}

template<>
struct kumi::is_product_type<my_product_type> : std::true_type
{};

// Adapt as structured bindable type
template<>
struct  std::tuple_size<my_product_type>
      : std::integral_constant<std::size_t,2> {};

template<std::size_t I> struct std::tuple_element<I,my_product_type> { using type = std::size_t; };


TTS_CASE("Check tuple to constructible type conversion")
{
  kumi::tuple in{std::size_t{9}, 13.37};

  TTS_EQUAL ( kumi::from_tuple<my_struct>(in), (my_struct{9,13.37}) );
};

TTS_CASE("Check tuple to constructible type constexpr conversion")
{
  constexpr kumi::tuple in{std::size_t{9}, 13.37};

  TTS_CONSTEXPR_EQUAL ( kumi::from_tuple<my_struct>(in), (my_struct{9,13.37}) );
};

TTS_CASE("Check type to tuple conversion")
{
  my_product_type in{9, 13};
  auto a = std::array{1,2,3,4,5};
  auto s = std::span{a};

  TTS_EQUAL ( kumi::to_tuple(in), (kumi::tuple{std::size_t{9},std::size_t{13}}) );
  TTS_EQUAL ( kumi::to_tuple( a), (kumi::tuple{1,2,3,4,5}) );
  TTS_EQUAL ( kumi::to_tuple( s), (kumi::tuple{1,2,3,4,5}) );

  TTS_EQUAL ( kumi::to_tuple(std::move(a)), (kumi::tuple{1,2,3,4,5}));
  TTS_EQUAL ( kumi::to_tuple(std::move(s)), (kumi::tuple{1,2,3,4,5}));
};

TTS_CASE("Check type to tuple constexpr conversion")
{
  constexpr my_product_type in{9, 13};
  constexpr auto a = std::array{1,2,3,4,5};

  static constexpr auto a2 = std::array{1,2,3,4,5};
  constexpr auto s = std::span{a2};

  TTS_CONSTEXPR_EQUAL ( kumi::to_tuple(in), (kumi::tuple{std::size_t{9}, std::size_t{13}}) );
  TTS_CONSTEXPR_EQUAL ( kumi::to_tuple( a), (kumi::tuple{1,2,3,4,5}) );
  TTS_CONSTEXPR_EQUAL ( kumi::to_tuple( s), (kumi::tuple{1,2,3,4,5}) );
};
