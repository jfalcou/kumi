//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/detail/stdfix.hpp>
#include <kumi/utils/traits.hpp>
#include <cstddef>
#include <utility>

namespace kumi::_
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
  template<typename From, typename To> struct is_piecewise_ordered;

  template<template<class...> class Box, typename... From, typename... To>
  struct is_piecewise_convertible<Box<From...>, Box<To...>>
  {
    static constexpr bool value = (... && kumi::convertible_to<From, To>);
  };

  template<template<class...> class Box, typename... From, typename... To>
  struct is_piecewise_constructible<Box<From...>, Box<To...>>
  {
    static constexpr bool value = (... && std::is_constructible_v<To, From>);
  };

  template<typename From, typename To>
  concept ordered = requires(From const& a, To const& b){ {a < b}; };

  template<template<class...> class Box, typename... From, typename... To>
  struct is_piecewise_ordered<Box<From...>, Box<To...>>
  {
    static constexpr bool value = (... && ordered<From,To> );
  };

  template<typename From, typename To>
  concept piecewise_convertible = _::is_piecewise_convertible<From, To>::value;

  template<typename From, typename To>
  concept piecewise_constructible = _::is_piecewise_constructible<From, To>::value;

  template<typename From, typename To>
  concept piecewise_ordered = _::is_piecewise_ordered<From, To>::value;

  template<typename T, typename... Args> concept implicit_constructible = requires(Args... args)
  {
    T {args...};
  };

  //==============================================================================================
  // Helper concepts for construction checks on records
  //==============================================================================================
  template<typename From, typename To> struct is_fieldwise_constructible;
  template<typename From, typename To> struct is_fieldwise_convertible;
  template<typename From, typename To> struct is_fieldwise_ordered;

  template<typename Ref, typename Field>
  struct check_name
  {
    static consteval Field      get(Ref) requires(Ref::name == Field::name) { return {}; }
    static consteval kumi::unit get(...)                                    { return {}; }
  };

  /// Helper using inheritance to get the corresponding name in an variadic pack if it exist 
  template<typename Ref, typename... Fields>
  struct get_field_by_name : check_name<Ref,Fields>...
  {
    using check_name<Ref,Fields>::get...;
    using type = decltype(get(std::declval<Ref>()));
  };

  template<typename Ref, typename... Fields>
  using get_field_by_name_t = typename get_field_by_name<Ref, Fields...>::type;

  template<template<class...> class Box, typename... From, typename... To>
  struct is_fieldwise_convertible<Box<From...>, Box<To...>>
  {     
    static constexpr bool value = ( []() 
      {
        using F_field = std::remove_cvref_t<From>;
        using T_field = std::remove_cvref_t<get_field_by_name_t<From, To...>>;
        return kumi::convertible_to<unwrap_field_capture_t<F_field>, unwrap_field_capture_t<T_field>>;
      }() && ...);
  };

  template<template<class...> class Box, typename... From, typename... To>
  struct is_fieldwise_constructible<Box<From...>, Box<To...>>
  {
    static constexpr bool value = ( []()
      {
        using F_field = std::remove_cvref_t<From>;
        using T_field = std::remove_cvref_t<get_field_by_name_t<From, To...>>;
        return std::is_constructible_v<unwrap_field_capture_t<F_field>, unwrap_field_capture_t<T_field>>;
      }() && ...);
  };

  template<template<class...>class Box, typename... From, typename... To>
  struct is_fieldwise_ordered<Box<From...>, Box<To...>>
  {
      static constexpr bool value = ( []()
      {
        using F_field = std::remove_cvref_t<From>;
        using T_field = std::remove_cvref_t<get_field_by_name_t<From, To...>>;
        return ordered<unwrap_field_capture_t<F_field>, unwrap_field_capture_t<T_field>>;
      }() && ...);
  };

  template<typename From, typename To>
  concept fieldwise_convertible = is_fieldwise_convertible<From, To>::value;

  template<typename From, typename To>
  concept fieldwise_constructible = is_fieldwise_constructible<From, To>::value;

  template<typename From, typename To>
  concept fieldwise_ordered = is_fieldwise_ordered<From, To>::value;

  //================================================================================================
  // Concept machinery to make our algorithms SFINAE friendly
  //================================================================================================
  template<typename F, size_t I, typename... Tuples>
  concept supports_call_i = std::is_invocable_v<F, raw_member_t<I,Tuples>...>;

  template<typename F, typename Indices, typename... Tuples> struct supports_call_t;

  template<typename F, size_t... Is, typename... Tuples>
  struct supports_call_t<F, std::index_sequence<Is...>, Tuples...>
      : std::bool_constant<(supports_call_i<F, Is, Tuples...> && ...)>
  {
  };

  template<typename F, typename Indices, typename Tuple> struct supports_apply_t;

  template<typename F, size_t... Is, typename Tuple>
  struct supports_apply_t<F, std::index_sequence<Is...>, Tuple>
      : std::is_invocable<F, decltype(get<Is>(std::declval<Tuple &&>()))...>
  {
  };

  template<typename F, size_t... Is, typename Record>
  requires( is_record_type<std::remove_cvref_t<Record>>::value )
  struct supports_apply_t<F, std::index_sequence<Is...>, Record>
      : std::is_invocable<F, std::add_rvalue_reference_t<unwrap_field_capture_t
        <
          std::remove_cvref_t<decltype(get<Is>(std::declval<Record &&>()))>
        >>...>
  {
  };

  template<typename F, typename Indices, typename Tuple> struct supports_nothrow_apply_t;

  template<typename F, size_t... Is, typename Tuple>
  struct supports_nothrow_apply_t<F, std::index_sequence<Is...>, Tuple>
      : std::is_nothrow_invocable<F, decltype(get<Is>(std::declval<Tuple &&>()))...>
  {
  };

  template<typename F, size_t... Is, typename Record>
  requires( is_record_type<std::remove_cvref_t<Record>>::value )
  struct supports_nothrow_apply_t<F, std::index_sequence<Is...>, Record>
      : std::is_nothrow_invocable<F, std::add_rvalue_reference_t<unwrap_field_capture_t
        <
          std::remove_cvref_t<decltype(get<Is>(std::declval<Record &&>()))>
        >>...>
  {
  };

  template<typename F, typename Tuple>
  concept supports_apply = _::
      supports_apply_t<F, std::make_index_sequence<size<Tuple>::value>, Tuple>::value;

  template<typename F, typename Tuple>
  concept supports_nothrow_apply = _::
      supports_nothrow_apply_t<F, std::make_index_sequence<size<Tuple>::value>, Tuple>::value;

  template<typename F, typename... Tuples>
  concept supports_call = _::
      supports_call_t<F, std::make_index_sequence<(size<Tuples>::value, ...)>, Tuples...>::value;

  // Helper for checking if two tuples can == each others
  template<typename T, typename U>
  concept comparable = requires(T t, U u)
  {
    { t == u };
  };
}
