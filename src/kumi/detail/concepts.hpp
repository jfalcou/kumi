//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/utils/traits.hpp>
#include <cstddef>
#include <utility>

namespace kumi::detail
{
  //==============================================================================================
  // Helper concepts for tuple detection
  //==============================================================================================
  // Concept specifying a type is non-empty standard tuple-like type.
  template<typename T> concept non_empty_tuple = requires( T const &t )
  {
    typename std::tuple_element<0,std::remove_cvref_t<T>>::type;
    typename std::tuple_size<std::remove_cvref_t<T>>::type;
  };

  // Concept specifying a type is an empty standard tuple-like type.
  template<typename T> concept empty_tuple = (std::tuple_size<std::remove_cvref_t<T>>::value == 0);

  //==============================================================================================
  // Helper concepts for construction checks
  //==============================================================================================
  template<typename From, typename To> struct is_piecewise_constructible;
  template<typename From, typename To> struct is_piecewise_convertible;

  template<template<class...> class Box, typename... From, typename... To>
  struct is_piecewise_convertible<Box<From...>, Box<To...>>
  {
    static constexpr bool value = (... && std::convertible_to<From, To>);
  };

  template<template<class...> class Box, typename... From, typename... To>
  struct is_piecewise_constructible<Box<From...>, Box<To...>>
  {
    static constexpr bool value = (... && std::is_constructible_v<To, From>);
  };

  template<typename From, typename To>
  concept piecewise_convertible = detail::is_piecewise_convertible<From, To>::value;

  template<typename From, typename To>
  concept piecewise_constructible = detail::is_piecewise_constructible<From, To>::value;

  template<typename T, typename... Args> concept implicit_constructible = requires(Args... args)
  {
    T {args...};
  };

  //================================================================================================
  // Concept machinery to make our algorithms SFINAE friendly
  //================================================================================================
  template<typename F, size_t I, typename... Tuples>
  concept applicable_i = std::is_invocable_v<F, member_t<I,Tuples>...>;

  template<typename F, typename Indices, typename... Tuples> struct is_applicable;

  template<typename F, size_t... Is, typename... Tuples>
  struct is_applicable<F, std::index_sequence<Is...>, Tuples...>
      : std::bool_constant<(applicable_i<F, Is, Tuples...> && ...)>
  {
  };

  template<typename F, typename... Tuples>
  concept applicable = detail::
      is_applicable<F, std::make_index_sequence<(size<Tuples>::value, ...)>, Tuples...>::value;

  // Helper for checking if two tuples can == each others
  template<typename T, typename U>
  concept comparable = requires(T t, U u)
  {
    { t == u };
  };
}
