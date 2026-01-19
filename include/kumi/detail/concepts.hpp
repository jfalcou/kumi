//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <concepts>
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
  template<typename T>
  concept non_empty_tuple = requires(T const& t) {
    typename std::tuple_element<0, std::remove_cvref_t<T>>::type;
    typename std::tuple_size<std::remove_cvref_t<T>>::type;
  };

  // Concept specifying a type is an empty standard tuple-like type.
  template<typename T>
  concept empty_tuple = (std::tuple_size<std::remove_cvref_t<T>>::value == 0);

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
  concept ordered = requires(From const& a, To const& b) {
    { a < b };
  };

  template<template<class...> class Box, typename... From, typename... To>
  struct is_piecewise_ordered<Box<From...>, Box<To...>>
  {
    static constexpr bool value = (... && ordered<From, To>);
  };

  template<typename From, typename To>
  concept piecewise_convertible =
    _::is_piecewise_convertible<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::value;

  template<typename From, typename To>
  concept piecewise_constructible =
    _::is_piecewise_constructible<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::value;

  template<typename From, typename To>
  concept piecewise_ordered = _::is_piecewise_ordered<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::value;

  template<typename T, typename... Args>
  concept implicit_constructible = requires(Args... args) { T{args...}; };

  //==============================================================================================
  // Helper meta functions to access a field type by type
  //==============================================================================================

  // Simple helper for the get_index to work in check_type & check_name (needs a ::value)
  struct sfinae_unit : kumi::unit
  {
    static constexpr auto value = kumi::none;
  };

  template<typename Ref, typename Field> struct check_type
  {
    static consteval Field get(Ref)
    requires std::is_same_v<Field, Ref>
    {
      return {};
    }

    static consteval kumi::unit get(...) { return {}; }
  };

  template<std::size_t I, typename Ref, typename Field> struct get_index
  {
    using constant = std::integral_constant<std::size_t, I>;

    static consteval constant get(Ref)
    requires std::is_same_v<Ref, Field>
    {
      return {};
    }

    static consteval sfinae_unit get(...) { return {}; }
  };

  /// Helper using inheritance to get the corresponding type in an variadic pack if it exist
  template<typename Ref, typename... Fields> struct get_field_by_type : check_type<Ref, Fields>...
  {
    using check_type<Ref, Fields>::get...;
    using type = decltype(get(std::declval<Ref>()));
  };

  template<typename Ref, typename Seq, typename... Fields> struct get_index_by_type;

  template<typename Ref, std::size_t... I, typename... Fields>
  struct get_index_by_type<Ref, std::index_sequence<I...>, Fields...> : get_index<I, Ref, Fields>...
  {
    using get_index<I, Ref, Fields>::get...;
    static constexpr auto value = decltype(get(std::declval<Ref>()))::value;
  };

  template<typename Ref, typename... Fields>
  using get_field_by_type_t = typename get_field_by_type<Ref, Fields...>::type;

  template<typename Ref, typename... Fields>
  inline constexpr auto get_index_by_type_v =
    get_index_by_type<Ref, std::index_sequence_for<Fields...>, Fields...>::value;

  template<typename Ref, typename... Fields>
  concept can_get_field_by_type = !std::is_same_v<get_field_by_type_t<Ref, Fields...>, kumi::unit>;

  //==============================================================================================
  // Helper meta functions to access a field type by name
  //==============================================================================================
  template<std::size_t I, typename Ref, typename Field> struct check_name
  {
    static consteval Field get(Ref)
    requires(Ref::name == Field::name)
    {
      return {};
    }

    static consteval kumi::unit get(...) { return {}; }

    static consteval std::integral_constant<std::size_t, I> get_index(Ref)
    requires(Ref::name == Field::name)
    {
      return {};
    }

    static consteval sfinae_unit get_index(...) { return {}; }
  };

  template<typename Ref, typename Seq, typename... Fields> struct get_field_by_name;

  /// Helper using inheritance to get the corresponding name in an variadic pack if it exist
  /// The index is used in order to enable mixed named/unnamed packs to work
  template<typename Ref, std::size_t... I, typename... Fields>
  struct get_field_by_name<Ref, std::index_sequence<I...>, Fields...> : check_name<I, Ref, Fields>...
  {
    using check_name<I, Ref, Fields>::get...;
    using check_name<I, Ref, Fields>::get_index...;

    using type = decltype(get(std::declval<Ref>()));
    static constexpr auto value = decltype(get_index(std::declval<Ref>()))::value;
  };

  template<typename Ref, typename... Fields>
  using get_field_by_name_t = typename get_field_by_name<Ref, std::index_sequence_for<Fields...>, Fields...>::type;

  template<typename Ref, typename... Fields>
  inline constexpr auto get_index_by_name_v =
    get_field_by_name<Ref, std::index_sequence_for<Fields...>, Fields...>::value;

  template<typename Ref, typename... Fields>
  concept can_get_field_by_name = !std::is_same_v<get_field_by_name_t<Ref, Fields...>, kumi::unit>;

  //==============================================================================================
  // Helper concepts for construction checks on records
  //==============================================================================================
  template<typename From, typename To> struct is_fieldwise_constructible;
  template<typename From, typename To> struct is_fieldwise_convertible;

  template<template<class...> class Box, typename... From, typename... To>
  struct is_fieldwise_convertible<Box<From...>, Box<To...>>
  {
    static constexpr bool value = ([]() {
      using F_field = std::remove_cvref_t<From>;
      using T_field = std::remove_cvref_t<get_field_by_name_t<From, To...>>;
      return kumi::convertible_to<typename F_field::type, typename T_field::type>;
    }() && ...);
  };

  template<template<class...> class Box, typename... From, typename... To>
  struct is_fieldwise_constructible<Box<From...>, Box<To...>>
  {
    static constexpr bool value = ([]() {
      using F_field = std::remove_cvref_t<From>;
      using T_field = std::remove_cvref_t<get_field_by_name_t<From, To...>>;
      return std::is_constructible_v<typename F_field::type, typename T_field::type>;
    }() && ...);
  };

  template<typename From, typename To>
  concept fieldwise_convertible =
    _::is_fieldwise_convertible<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::value;

  template<typename From, typename To>
  concept fieldwise_constructible =
    _::is_fieldwise_constructible<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::value;

  //================================================================================================
  // Concept machinery to make our algorithms SFINAE friendly
  //================================================================================================
  template<typename F, typename T>
  concept supports_apply = []<std::size_t... N>(std::index_sequence<N...>) {
    return std::invocable<F, raw_member_t<N, T>...>;
  }(std::make_index_sequence<size<T>::value>{});

  template<typename F, typename T>
  concept supports_nothrow_apply = []<std::size_t... N>(std::index_sequence<N...>) {
    return std::is_nothrow_invocable<F, raw_member_t<N, T>...>::value;
  }(std::make_index_sequence<size<T>::value>{});

  template<typename F, typename... Ts>
  concept supports_call = []<std::size_t... I>(std::index_sequence<I...>) {
    return ([]<std::size_t J>(std::integral_constant<std::size_t, J>) {
      return std::invocable<F, raw_member_t<J, Ts>...>;
    }(std::integral_constant<std::size_t, I>{}) &&
            ...);
  }(std::make_index_sequence<(size<Ts>::value, ...)>{});

  template<typename T>
  concept supports_transpose =
    (size<T>::value <= 1) || ([]<std::size_t... N>(std::index_sequence<N...>) {
      return ((kumi::size_v<raw_member_t<0, T>> == kumi::size_v<raw_member_t<N + 1, T>>) && ...);
    }(std::make_index_sequence<size<T>::value - 1>{}));

  // Helper for checking if two tuples can == each others
  template<typename T, typename U>
  concept comparable = requires(T t, U u) {
    { t == u };
  };
}
