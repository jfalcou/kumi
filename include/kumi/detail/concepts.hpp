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
  template<auto ID> struct value
  {
    using type = decltype(ID);
  };

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
  concept valid_label = implicit_constructible<T> &&
                        (!requires { to_str(T{}); } || std::same_as<typename value<to_str(T{})>::type, kumi::str>);

  //====================================================================================================================
  // Helper concepts for custom label
  //====================================================================================================================
  template<typename T>
  concept label = requires(T&& t) {
    typename std::remove_cvref_t<T>::type;
    { T::value } -> std::convertible_to<kumi::str>;
  };

  //====================================================================================================================
  // Helper concepts for custom field
  //====================================================================================================================
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

  //====================================================================================================================
  // Helper concepts for custom identifier
  //====================================================================================================================
  template<typename T>
  concept identifier = requires(T const& t) { typename std::remove_cvref_t<T>::type; };

  template<identifier T> struct tag_of
  {
    using type = typename std::remove_cvref_t<T>::type;
  };

  template<identifier T> using tag_of_t = typename tag_of<std::remove_cvref_t<T>>::type;

  //====================================================================================================================
  // Helper concepts for construction checks
  //====================================================================================================================
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
    static constexpr bool value = (... && std::convertible_to<From, To>);
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

  //====================================================================================================================
  // Helper concepts for construction checks on records
  //====================================================================================================================
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
    using t_list = tuple<decltype(get(std::declval<Us>()))...>;
    using u_list = tuple<decltype(get(std::declval<Us>()))...>;

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

  //====================================================================================================================
  // Helper meta functions to access a field type via a meta function
  //====================================================================================================================
  struct find_failed
  {
    static consteval std::false_type get(...);
    static consteval invalid get_index(...);
  };

  template<template<class, class> class Matcher, std::size_t I, typename Ref, typename Field> struct match_node
  {
    static consteval std::false_type get();
    static consteval invalid get_index();
  };

  template<template<class, class> class Matcher, std::size_t I, typename Ref, typename Field>
  requires(Matcher<Ref, Field>::value)
  struct match_node<Matcher, I, Ref, Field>
  {
    using index = std::integral_constant<std::size_t, I>;
    static consteval Field get(Ref);
    static consteval index get_index(Ref);
  };

  template<template<class, class> class Matcher, typename Ref, typename Seq, typename... Fields> struct find_engine;

  template<template<class, class> class Matcher, typename Ref, std::size_t... I, typename... Fields>
  struct find_engine<Matcher, Ref, std::index_sequence<I...>, Fields...> : find_failed,
                                                                           match_node<Matcher, I, Ref, Fields>...
  {
    using find_failed::get;
    using find_failed::get_index;
    using match_node<Matcher, I, Ref, Fields>::get...;
    using match_node<Matcher, I, Ref, Fields>::get_index...;

    using type = decltype(get(std::declval<Ref>()));
    static constexpr auto value = decltype(get_index(std::declval<Ref>()))::value;
  };

  // ===================================================================================================================
  // By Type
  // ===================================================================================================================
  template<typename Ref, typename Field> struct match_by_type : std::is_same<Ref, Field>
  {
  };

  template<typename Ref, typename... Fields>
  using find_by_type_t = find_engine<match_by_type, Ref, std::index_sequence_for<Fields...>, Fields...>;

  template<typename Ref, typename... Fields> using get_field_by_type_t = typename find_by_type_t<Ref, Fields...>::type;

  template<typename Ref, typename... Fields>
  inline constexpr auto get_index_by_type_v = find_by_type_t<Ref, Fields...>::index;

  template<typename Ref, typename... Fields>
  concept can_get_field_by_type = !std::is_same_v<get_field_by_type_t<Ref, Fields...>, std::false_type>;

  // ===================================================================================================================
  // By Value (Tag)
  // ===================================================================================================================
  template<typename Ref, typename Field> struct match_by_tag : std::false_type
  {
  };

  template<identifier Ref, field Field> struct match_by_tag<Ref, Field> : std::is_same<tag_of_t<Ref>, key_of_t<Field>>
  {
  };

  template<typename Ref, typename... Fields>
  using find_by_tag_t = find_engine<match_by_tag, Ref, std::index_sequence_for<Fields...>, Fields...>;

  template<typename Ref, typename... Fields> using get_field_by_value_t = typename find_by_tag_t<Ref, Fields...>::type;

  template<typename Ref, typename... Fields>
  inline constexpr auto get_index_by_value_v = find_by_tag_t<Ref, Fields...>::index;

  template<typename Ref, typename... Fields>
  concept can_get_field_by_value = !std::is_same_v<get_field_by_value_t<Ref, Fields...>, std::false_type>;

  //====================================================================================================================
  // By label (displayed name)
  //====================================================================================================================
  template<typename Ref, typename Field> struct match_by_label : std::false_type
  {
  };

  template<label Ref, field Field> struct match_by_label<Ref, Field> : std::bool_constant<Ref::value == Field::name()>
  {
  };

  template<typename Ref, typename... Fields>
  using find_by_label_t = find_engine<match_by_label, Ref, std::index_sequence_for<Fields...>, Fields...>;

  template<typename Ref, typename... Fields>
  using get_field_by_label_t = typename find_by_label_t<Ref, Fields...>::type;

  template<typename Ref, typename... Fields>
  inline constexpr auto get_index_by_label_v = find_by_label_t<Ref, Fields...>::index;

  template<typename Ref, typename... Fields>
  concept can_get_field_by_label = !std::is_same_v<get_field_by_label_t<Ref, Fields...>, std::false_type>;

}
