
//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

struct my_record_type
{
  std::size_t n;
  std::size_t data;
  constexpr auto operator<=>(my_record_type const&) const = default;
};

template<std::size_t I> constexpr decltype(auto) get(my_record_type const& m) noexcept
{
  if constexpr (I == 0) return kumi::capture_field<"a"_n>(m.n);
  if constexpr (I == 1) return kumi::capture_field<"data"_n>(m.data);
}

template<std::size_t I> constexpr decltype(auto) get(my_record_type& m) noexcept
{
  if constexpr (I == 0) return kumi::capture_field<"n"_n>(m.n);
  if constexpr (I == 1) return kumi::capture_field<"data"_n>(m.data);
}

template<> struct kumi::is_record_type<my_record_type> : std::true_type
{
};

// Adapt as structured bindable type
template<> struct std::tuple_size<my_record_type> : std::integral_constant<std::size_t, 2>
{
};

template<> struct std::tuple_element<0, my_record_type>
{
  using type = kumi::field<kumi::name<"n">, std::size_t>;
};

template<> struct std::tuple_element<1, my_record_type>
{
  using type = kumi::field<kumi::name<"data">, std::size_t>;
};

TTS_CASE("Check record to constructible type conversion")
{
  kumi::record in{"data"_n = std::size_t{13}, "n"_n = std::size_t{9}};

  TTS_EQUAL(kumi::from_record<my_record_type>(in), (my_record_type{9, 13}));
};

TTS_CASE("Check tuple to constructible type constexpr conversion")
{
  constexpr kumi::record in{"data"_n = std::size_t{13}, "n"_n = std::size_t{9}};

  TTS_CONSTEXPR_EQUAL(kumi::from_record<my_record_type>(in), (my_record_type{9, 13}));
};

TTS_CASE("Check type to record conversion")
{
  my_record_type in{9, 13};

  TTS_EQUAL(kumi::to_record(in), (kumi::record{"n"_n = std::size_t{9}, "data"_n = std::size_t{13}}));
};

TTS_CASE("Check type to tuple constexpr conversion")
{
  using namespace kumi::literals;
  constexpr my_record_type in{9, 13};

  TTS_CONSTEXPR_EQUAL(kumi::to_record(in), (kumi::record{"n"_n = std::size_t{9}, "data"_n = std::size_t{13}}));
};
