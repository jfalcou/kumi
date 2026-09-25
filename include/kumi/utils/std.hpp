//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#if !defined(KUMI_DOXYGEN_INVOKED)
//======================================================================================================================
// Helpers avoiding the definition of recursive types
//======================================================================================================================
namespace kumi::_
{
  struct out_of_range_index;

  template<std::size_t I, typename T> extern out_of_range_index tuple_element;

  template<template<class...> class Box, typename Head, typename... Tail>
  extern Head tuple_element<0, Box<Head, Tail...>>;

  template<std::size_t I, template<class...> typename Box, typename Head, typename... Tail>
  extern decltype(tuple_element<I - 1, Box<Tail...>>) tuple_element<I, Box<Head, Tail...>>;

  template<std::size_t I, template<class...> typename Box, typename... Ts>
  extern decltype(tuple_element<I, Box<Ts...>>) const tuple_element<I, Box<Ts...> const>;
}

//======================================================================================================================
// Structured binding adaptation for tuples
//======================================================================================================================
template<std::size_t I, typename... Ts> struct std::tuple_element<I, kumi::tuple<Ts...>>
{
  static_assert(I < sizeof...(Ts), "[KUMI] - Tuple index must be in range");
  using type = decltype(kumi::_::tuple_element<I, kumi::tuple<Ts...>>);
};

template<typename... Ts> struct std::tuple_size<kumi::tuple<Ts...>> : std::integral_constant<std::size_t, sizeof...(Ts)>
{
};

//======================================================================================================================
// Structured binding adaptation for records
//======================================================================================================================
template<std::size_t I, typename... Ts> struct std::tuple_element<I, kumi::record<Ts...>>
{
  static_assert(I < sizeof...(Ts), "[KUMI] - Record index must be in range");
  using type = decltype(kumi::_::tuple_element<I, kumi::record<Ts...>>);
};

template<typename... Ts>
struct std::tuple_size<kumi::record<Ts...>> : std::integral_constant<std::size_t, sizeof...(Ts)>
{
};

//======================================================================================================================
// Adaptation of unit to the tuple protocol
//======================================================================================================================
template<> struct std::tuple_size<kumi::unit> : std::integral_constant<std::size_t, 0>
{
};

template<std::size_t I> struct std::tuple_element<I, kumi::unit>
{
};

#if !defined(__ANDROID__)
//======================================================================================================================
// Common Reference support
//======================================================================================================================
template<typename... Ts, typename... Us, template<class> class TQual, template<class> class UQual>
requires(sizeof...(Ts) == sizeof...(Us))
struct std::basic_common_reference<kumi::tuple<Ts...>, kumi::tuple<Us...>, TQual, UQual>
{
  using type = kumi::tuple<std::common_reference_t<TQual<Ts>, UQual<Us>>...>;
};
#endif

#endif
