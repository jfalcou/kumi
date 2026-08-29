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
  //======================================================================================================================
  // Compile-time dispatch cases for some algorithm implementations.
  //======================================================================================================================
  enum class case_
  {
    normal,
    indexed,
    field
  };

  //====================================================================================================================
  // Helpers for uniqueness checking
  //====================================================================================================================
  template<std::size_t I, typename T> inline auto get_key()
  {
    if constexpr (kumi::_::field<T>) return kumi::_::identifier_of_t<T>{};
    else return std::integral_constant<std::size_t, I>{};
  }

  /// Used to detect duplicate types in a pack by enabling unique conversion overload resolution.
  template<std::size_t I, typename T> struct unique
  {
    operator std::type_identity<T>();
    operator std::integral_constant<std::size_t, I>();

    template<typename U>
    requires(std::same_as<T, U>)
    std::integral_constant<std::size_t, I> operator()(U const&);
  };

  /// Named variant of unique
  template<std::size_t I, kumi::_::field T> struct unique<I, T>
  {
    operator std::type_identity<T>();
    operator kumi::_::identifier_of_t<T>();

    template<typename U>
    requires(std::same_as<kumi::_::type_of_t<T>, U>)
    std::integral_constant<std::size_t, I> operator()(U const&);

    std::integral_constant<std::size_t, I> operator()(kumi::_::identifier_of_t<T> const&);

    template<kumi::_::label U>
    requires(U::value == std::remove_cvref_t<T>::label())
    std::integral_constant<std::size_t, I> operator()(U const&);
  };

  /// Helper used for SFINAE checks.
  inline consteval std::true_type true_fn(...);

  template<typename T, typename... Key>
  inline auto is_set(T, Key...) -> decltype(kumi::_::true_fn(static_cast<Key>(std::declval<T>())...));

  inline std::false_type is_set(...);

  //====================================================================================================================
  // Helper type for types behavior detection, only one type to instantiate for all traits
  //====================================================================================================================
  template<typename Seq, typename... Ts> struct family;

  template<std::size_t... I, typename... Ts> struct family<std::index_sequence<I...>, Ts...> : kumi::_::unique<I, Ts>...
  {
    using kumi::_::unique<I, Ts>::operator()...;
    kumi::_::invalid operator()(...);

    template<typename Ref> using type = decltype(std::declval<family>()(std::declval<Ref>()));
  };

  template<typename... Ts> using make_family = family<std::index_sequence_for<Ts...>, Ts...>;

  //====================================================================================================================
  // Helper variables for properties detection on families
  //====================================================================================================================
  template<typename T> inline constexpr bool is_set_v = false;

  template<std::size_t... I, typename... Ts>
  inline constexpr bool is_set_v<kumi::_::family<std::index_sequence<I...>, Ts...>>{decltype(kumi::_::is_set(
    std::declval<kumi::_::family<std::index_sequence<I...>, Ts...>>(), std::type_identity<Ts>{}...))::value};

  template<typename T> inline constexpr bool is_map_v = false;

  template<std::size_t... I, typename... Ts>
  inline constexpr bool is_map_v<kumi::_::family<std::index_sequence<I...>, Ts...>>{decltype(kumi::_::is_set(
    std::declval<kumi::_::family<std::index_sequence<I...>, Ts...>>(), kumi::_::get_key<I, Ts>()...))::value};

  template<typename T, typename... Ts> inline constexpr bool same_mapping_v = false;

  template<std::size_t... I, typename... Ts, typename... Us>
  inline constexpr bool same_mapping_v<kumi::_::family<std::index_sequence<I...>, Ts...>, Us...>{
    decltype(kumi::_::is_set(std::declval<kumi::_::family<std::index_sequence<I...>, Ts...>>(),
                             kumi::_::get_key<I, Us>()...))::value};

  //====================================================================================================================
  // Helper meta functions to access a field index by Type
  //====================================================================================================================
  template<typename Ref, typename... Fields>
  using index_of_type = typename kumi::_::make_family<Fields...>::template type<Ref>;

  //====================================================================================================================
  // Helper meta functions to access a field index by Value (Tag)
  //====================================================================================================================
  template<typename Ref, typename... Fields>
  using index_of_tag = typename kumi::_::make_family<Fields...>::template type<kumi::_::tag_of_t<Ref>>;

  //====================================================================================================================
  // Helper meta functions to access a field index by Label (Displayed name)
  //====================================================================================================================
  template<typename Ref, typename... Fields>
  using index_of_label = typename kumi::_::make_family<Fields...>::template type<Ref>;

  template<template<typename...> typename Meta, typename Target, typename PT, typename Seq>
  inline constexpr bool can_query = false;

  template<template<typename...> typename Meta, typename Target, typename PT, std::size_t... I>
  inline constexpr bool can_query<Meta, Target, PT, std::index_sequence<I...>> =
    Meta<Target, std::tuple_element_t<I, PT>...>::value != kumi::_::invalid{};
}
