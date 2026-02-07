//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <concepts>
#include <cstddef>
#include <utility>

namespace kumi::_
{
  template<typename... Ts> struct type_list
  {
  };

  using invalid = std::integral_constant<std::size_t, static_cast<std::size_t>(-1)>;

  //====================================================================================================================
  //! @ingroup utility
  //! @brief Type indicating a identifier was not found in a given kumi::product_type
  //====================================================================================================================
  struct unknown_identifier
  {
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os,
                                                         unknown_identifier const&) noexcept
    {
      return os << "kumi::unkown_name";
    }
  };

  template<typename From, typename To>
  concept ordered = requires(From const& a, To const& b) {
    { a < b };
  };

  // Helper for checking if two tuples can == each others
  template<typename T, typename U>
  concept comparable = requires(T t, U u) {
    { t == u };
  };

  template<typename T, typename... Args>
  concept implicit_constructible = requires(Args... args) { T{args...}; };

  template<typename O>
  concept field = requires(O const& o) {
    typename std::remove_cvref_t<O>::type;
    typename std::remove_cvref_t<O>::identifier_type;
    { o(typename std::remove_cvref_t<O>::identifier_type{}) };
    { std::remove_cvref_t<O>::name() };
  };

  template<field T> struct key_of
  {
    using type = typename std::remove_cvref_t<T>::identifier_type;
  };

  template<field T> struct type_of
  {
    using type = typename std::remove_cvref_t<T>::type;
  };

  template<field T> using key_of_t = typename key_of<std::remove_cvref_t<T>>::type;
  template<field T> using type_of_t = typename type_of<std::remove_cvref_t<T>>::type;

  //==============================================================================================
  // Helper concepts for construction checks
  //==============================================================================================
  template<typename From, typename To> struct is_piecewise_constructible : std::false_type
  {
  };

  template<typename From, typename To> struct is_piecewise_convertible : std::false_type
  {
  };

  template<typename From, typename To> struct is_piecewise_ordered : std::false_type
  {
  };

  template<typename From, typename To> struct is_piecewise_comparable : std::false_type
  {
  };

  template<template<class...> class Box, typename... From, typename... To>
  requires(sizeof...(From) == sizeof...(To))
  struct is_piecewise_convertible<Box<From...>, Box<To...>>
  {
    static constexpr bool value = (... && kumi::convertible_to<From, To>);
  };

  template<template<class...> class Box, typename... From, typename... To>
  requires(sizeof...(From) == sizeof...(To))
  struct is_piecewise_constructible<Box<From...>, Box<To...>>
  {
    static constexpr bool value = (... && std::is_constructible_v<To, From>);
  };

  template<template<class...> class Box, typename... From, typename... To>
  requires(sizeof...(From) == sizeof...(To))
  struct is_piecewise_ordered<Box<From...>, Box<To...>>
  {
    static constexpr bool value = (... && ordered<From, To>);
  };

  template<template<class...> class Box, typename... Ts, typename... Us>
  requires(sizeof...(Ts) == sizeof...(Us))
  struct is_piecewise_comparable<Box<Ts...>, Box<Us...>>
  {
    static constexpr bool value = (... && _::comparable<Ts, Us>);
  };

  template<typename From, typename To>
  concept piecewise_convertible = is_piecewise_convertible<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::value;

  template<typename From, typename To>
  concept piecewise_constructible =
    is_piecewise_constructible<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::value;

  template<typename From, typename To>
  concept piecewise_ordered = is_piecewise_ordered<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::value;

  template<typename From, typename To>
  concept piecewise_comparable = is_piecewise_comparable<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::value;

  //==============================================================================================
  // Helper concepts for construction checks on records
  //==============================================================================================
  template<typename Field> struct check_value
  {
    static consteval std::false_type get(...);
  };

  template<field F> struct check_value<F>
  {
    template<field T>
    requires(std::is_same_v<key_of_t<F>, key_of_t<T>>)
    static consteval type_of_t<F> get(T);
  };

  template<typename... Ts> struct sort : std::true_type
  {
  };

  template<template<class...> class Box, typename... Ts, typename... Us>
  requires(sizeof...(Ts) == sizeof...(Us))
  struct sort<Box<Ts...>, Box<Us...>> : check_value<Ts>...
  {
    using check_value<Ts>::get...;
    using t_list = type_list<decltype(get(std::declval<Us>()))...>;
    using u_list = type_list<decltype(get(std::declval<Us>()))...>;

    using is_fieldwise_constructible = is_piecewise_constructible<t_list, u_list>;
    using is_fieldwise_convertible = is_piecewise_convertible<t_list, u_list>;
    using is_fieldwise_comparable = is_piecewise_comparable<t_list, u_list>;
  };

  template<typename From, typename To>
  concept fieldwise_convertible =
    sort<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::is_fieldwise_convertible::value;

  template<typename From, typename To>
  concept fieldwise_constructible =
    sort<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::is_fieldwise_constructible::value;

  template<typename From, typename To>
  concept fieldwise_comparable =
    sort<std::remove_cvref_t<From>, std::remove_cvref_t<To>>::is_fieldwise_comparable::value;

  //==============================================================================================
  // Helper meta functions to access a field type by type
  //==============================================================================================
  template<typename Ref, typename Field> struct check_type
  {
    static consteval Field get(Ref)
    requires std::is_same_v<Field, Ref>;
    static consteval std::false_type get(...);
  };

  template<std::size_t I, typename Ref, typename Field> struct get_index
  {
    using constant = std::integral_constant<std::size_t, I>;

    static consteval constant get(Ref)
    requires std::is_same_v<Ref, Field>;
    static consteval invalid get(...);
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
    using type = decltype(get(std::declval<Ref>()));
    static constexpr auto value = decltype(get(std::declval<Ref>()))::value;
  };

  template<typename Ref, typename... Fields>
  using get_field_by_type_t = typename get_field_by_type<Ref, Fields...>::type;

  template<typename Ref, typename... Fields>
  inline constexpr auto get_index_by_type_v =
    get_index_by_type<Ref, std::index_sequence_for<Fields...>, Fields...>::value;

  template<typename Ref, typename... Fields>
  concept can_get_field_by_type = !std::is_same_v<get_field_by_type_t<Ref, Fields...>, std::false_type>;

  //==============================================================================================
  // Helper meta functions to access a field type by name
  //==============================================================================================
  template<std::size_t I, typename Ref, typename Field> struct check_field
  {
    static consteval std::false_type get(...);
    static consteval invalid get_index(...);
  };

  template<std::size_t I, typename Ref, field Field>
  requires(std::is_same_v<Ref, key_of_t<Field>>)
  struct check_field<I, Ref, Field>
  {
    using constant = std::integral_constant<std::size_t, I>;
    static consteval Field get(Ref);
    static consteval constant get_index(Ref);
  };

  template<typename Ref, typename Seq, typename... Fields> struct get_field_by_value;

  /// Helper using inheritance to get the corresponding name in an variadic pack if it exist
  /// The index is used in order to enable mixed named/unnamed packs to work
  template<typename Ref, std::size_t... I, typename... Fields>
  struct get_field_by_value<Ref, std::index_sequence<I...>, Fields...> : check_field<I, Ref, Fields>...
  {
    using check_field<I, Ref, Fields>::get...;
    using check_field<I, Ref, Fields>::get_index...;

    using type = decltype(get(std::declval<Ref>()));
    static constexpr auto value = decltype(get_index(std::declval<Ref>()))::value;
  };

  template<typename Ref, typename... Fields>
  using get_field_by_value_t = typename get_field_by_value<Ref, std::index_sequence_for<Fields...>, Fields...>::type;

  template<typename Ref, typename... Fields>
  inline constexpr auto get_index_by_value_v =
    get_field_by_value<Ref, std::index_sequence_for<Fields...>, Fields...>::value;

  template<typename Ref, typename... Fields>
  concept can_get_field_by_value = !std::is_same_v<get_field_by_value_t<Ref, Fields...>, std::false_type>;

  // MSVC workaround for get<>
  // MSVC doesnt SFINAE properly based on NTTP types before requires evaluation
  // so we need this weird mechanism for it to pick the correct version.
  template<typename Name, typename... Ts> KUMI_ABI constexpr auto contains_field()
  {
    if constexpr (!std::integral<std::remove_cvref_t<Name>>)
      return can_get_field_by_value<std::remove_cvref_t<Name>, Ts...>;
    else return false;
  };
}
