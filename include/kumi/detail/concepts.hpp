//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi::_
{
  using invalid = std::integral_constant<std::size_t, static_cast<std::size_t>(-1)>;

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

  // To be displayed an identifier need to be constructible via T{}, and either expose a constexpr to_str() or
  // nothing, in which case the typer will be used (see typename.hpp). The name that is displayed is called the label.
  template<typename T>
  concept valid_label =
    kumi::_::implicit_constructible<T> &&
    (!requires { to_str(T{}); } ||
    requires
    {
      { std::bool_constant<(to_str(T{}), true)>{} } -> std::same_as<std::true_type>;
      { to_str(T{}) } -> std::same_as<kumi::str>;
    });

  //====================================================================================================================
  // Helper concepts for custom label
  //====================================================================================================================
  template<typename T>
  concept label = requires(T&& t) {
    typename std::remove_cvref_t<T>::type;
    { std::remove_cvref_t<T>::value } -> std::convertible_to<kumi::str>;
  };

  //====================================================================================================================
  // Helper concepts for custom field
  //====================================================================================================================
  template<typename O>
  concept field = requires(O&& o) {
    typename std::remove_cvref_t<O>::type;
    typename std::remove_cvref_t<O>::identifier_type;
    typename std::remove_cvref_t<O>::label_type;
    { o(typename std::remove_cvref_t<O>::identifier_type{}) };
    { std::remove_cvref_t<O>::label() };
  };

  // Traits
  template<kumi::_::field T> using identifier_of_t = typename std::remove_cvref_t<T>::identifier_type;

  template<kumi::_::field T> struct identifier_of
  {
    using type = kumi::_::identifier_of_t<T>;
  };

  template<kumi::_::field T> using type_of_t = typename std::remove_cvref_t<T>::type;

  template<kumi::_::field T> struct type_of
  {
    using type = kumi::_::type_of_t<T>;
  };

  template<kumi::_::field T> using label_of_t = typename std::remove_cvref_t<T>::label_type;

  template<kumi::_::field T> struct label_of
  {
    using type = kumi::_::label_of_t<T>;
  };

  //====================================================================================================================
  // Helper concepts for custom identifier
  //====================================================================================================================
  template<typename T>
  concept identifier = requires(T&& t) { typename std::remove_cvref_t<T>::type; };

  template<kumi::_::identifier T> using tag_of_t = typename std::remove_cvref_t<T>::type;

  template<kumi::_::identifier T> struct tag_of
  {
    using type = kumi::_::tag_of_t<T>;
  };

  //==================================================================================================================
  // Helper concepts for tuple detection
  //==================================================================================================================
  // Concept specifying a type is non-empty standard tuple-like type.
  template<typename T>
  concept non_empty_tuple = requires {
    typename std::tuple_element<0, std::remove_cvref_t<T>>::type;
    { std::tuple_size<T>::value };
  };

  // Concept specifying a type is an empty standard tuple-like type.
  template<typename T>
  concept empty_tuple = (std::tuple_size<std::remove_cvref_t<T>>::value == 0);

  // Concept specifying a type is a standard tuple-like type.
  template<typename T>
  concept std_tuple_compatible = kumi::_::empty_tuple<T> || kumi::_::non_empty_tuple<T>;

  //==================================================================================================================
  // Helper concepts for container detection
  //==================================================================================================================
  // Concept specifying a type is standard container-like type.
  template<typename T>
  concept container_like = requires(T const& t) {
    typename T::value_type;
    typename T::size_type;

    { t.size() } -> std::convertible_to<std::size_t>;
    { t.begin() };
    { t.end() };
  };

  /// Concept for container types providing access to a contiguous block of data
  template<typename T>
  concept contiguous_container_like = kumi::_::container_like<T> && requires(T const& t) {
    { t.data() };
  };

  //====================================================================================================================
  // Helper concepts for construction checks
  //====================================================================================================================
  template<typename, typename> inline constexpr bool is_piecewise_convertible_v = false;

  template<template<class...> class Box, typename... From, typename... To>
  requires(sizeof...(From) == sizeof...(To))
  inline constexpr bool is_piecewise_convertible_v<Box<From...>, Box<To...>> = (std::convertible_to<From, To> && ...);

  template<typename From, typename To>
  concept piecewise_convertible =
    kumi::_::is_piecewise_convertible_v<std::remove_cvref_t<From>, std::remove_cvref_t<To>>;

  template<typename, typename> inline constexpr bool is_piecewise_constructible_v = false;

  template<template<class...> class Box, typename... From, typename... To>
  requires(sizeof...(From) == sizeof...(To))
  inline constexpr bool is_piecewise_constructible_v<Box<From...>, Box<To...>> =
    (std::is_constructible_v<To, From> && ...);

  template<typename From, typename To>
  concept piecewise_constructible =
    kumi::_::is_piecewise_constructible_v<std::remove_cvref_t<From>, std::remove_cvref_t<To>>;

  template<typename, typename> inline constexpr bool is_piecewise_ordered_v = false;

  template<template<class...> class Box, typename... From, typename... To>
  requires(sizeof...(From) == sizeof...(To))
  inline constexpr bool is_piecewise_ordered_v<Box<From...>, Box<To...>> = (... && ordered<From, To>);

  template<typename From, typename To>
  concept piecewise_ordered = kumi::_::is_piecewise_ordered_v<std::remove_cvref_t<From>, std::remove_cvref_t<To>>;

  template<typename, typename> inline constexpr bool is_piecewise_comparable_v = false;

  template<template<class...> class Box, typename... From, typename... To>
  requires(sizeof...(From) == sizeof...(To))
  inline constexpr bool is_piecewise_comparable_v<Box<From...>, Box<To...>> = (... && comparable<From, To>);

  template<typename From, typename To>
  concept piecewise_comparable = kumi::_::is_piecewise_comparable_v<std::remove_cvref_t<From>, std::remove_cvref_t<To>>;

  //====================================================================================================================
  // Helper concepts for construction checks on records
  //====================================================================================================================
  template<typename... Ts> struct set : Ts...
  {
    using Ts::operator()...;
    consteval void operator()(...);
  };

  template<typename, typename> inline constexpr bool is_fieldwise_convertible_v = false;

  template<template<class...> class Box, typename... From, typename... To>
  requires(sizeof...(From) == sizeof...(To))
  inline constexpr bool is_fieldwise_convertible_v<Box<From...>, Box<To...>>{(
    std::is_convertible_v<decltype(std::declval<kumi::_::set<From...>>()(std::declval<kumi::_::identifier_of_t<To>>())),
                          kumi::_::type_of_t<To>> &&
    ...)};

  template<typename From, typename To>
  concept fieldwise_convertible =
    kumi::_::is_fieldwise_convertible_v<std::remove_cvref_t<From>, std::remove_cvref_t<To>>;

  template<typename From, typename To> inline constexpr bool is_fieldwise_constructible_v = false;

  template<template<class...> class Box, typename... From, typename... To>
  requires(sizeof...(From) == sizeof...(To))
  inline constexpr bool is_fieldwise_constructible_v<Box<From...>, Box<To...>>{
    (std::is_constructible_v<kumi::_::type_of_t<To>,
                             decltype(std::declval<kumi::_::set<From...>>()(
                               std::declval<kumi::_::identifier_of_t<To>>()))> &&
     ...)};

  template<typename From, typename To>
  concept fieldwise_constructible =
    kumi::_::is_fieldwise_constructible_v<std::remove_cvref_t<From>, std::remove_cvref_t<To>>;

  template<typename, typename> inline constexpr bool is_fieldwise_comparable_v = false;

  template<template<class...> class Box, typename... From, typename... To>
  requires(sizeof...(From) == sizeof...(To))
  inline constexpr bool is_fieldwise_comparable_v<Box<From...>, Box<To...>>{
    (kumi::_::comparable<decltype(std::declval<kumi::_::set<From...>>()(std::declval<kumi::_::identifier_of_t<To>>())),
                         kumi::_::type_of_t<To>> &&
     ...)};

  template<typename From, typename To>
  concept fieldwise_comparable = kumi::_::is_fieldwise_comparable_v<std::remove_cvref_t<From>, std::remove_cvref_t<To>>;
}
