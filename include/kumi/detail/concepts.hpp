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

  template<typename T, typename... Args>
  concept implicit_constructible = requires(Args... args) { T{args...}; };

  template<auto N> void str_based(kumi::str<N> const&);

  template<typename T>
  concept str_like = requires(T const& t) { kumi::_::str_based(t); };

  // To be displayed an identifier need to be constructible via T{}, and either expose a constexpr to_str() or
  // nothing, in which case the typer will be used (see typename.hpp). The name that is displayed is called the label.
  template<typename T>
  concept valid_label =
    kumi::_::implicit_constructible<T> &&
    (!requires { to_str(T{}); } ||
    requires
    {
      { std::bool_constant<(to_str(T{}), true)>{} } -> std::same_as<std::true_type>;
      { to_str(T{}) } -> kumi::_::str_like;
    });

  //====================================================================================================================
  // Helper concepts for custom label
  //====================================================================================================================
  template<typename T>
  concept label = requires(T&& t) {
    typename std::remove_cvref_t<T>::type;
    { std::remove_cvref_t<T>::value } -> kumi::_::str_like;
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

  //====================================================================================================================
  // Helper concepts for tuple property detection
  //====================================================================================================================
  template<typename T> inline constexpr bool has_tuple_size = requires { std::tuple_size<T>::value; };

  template<typename T> inline constexpr bool has_value_type = requires { typename T::value_type; };

  template<typename T, typename Seq> inline constexpr bool has_tuple_element = false;

  template<typename T, std::size_t... I>
  inline constexpr bool has_tuple_element<T, std::index_sequence<I...>> =
    (requires { typename std::tuple_element<I, T>::type; } && ...);

  template<typename T, typename V, typename Seq> inline constexpr bool has_homogeneous_tuple_element = false;

  template<typename T, typename V, std::size_t... I>
  inline constexpr bool has_homogeneous_tuple_element<T, V, std::index_sequence<I...>> =
    ((requires { typename std::tuple_element<I, T>::type; } && std::same_as<std::tuple_element_t<I, T>, V>) && ...);

  //==================================================================================================================
  // Helper concepts for detection of semantic on types
  //==================================================================================================================
  // Concept specifying a type is a standard tuple-like type.
  template<typename T>
  concept tuple_like =
    kumi::_::has_tuple_size<T> && kumi::_::has_tuple_element<T, std::make_index_sequence<std::tuple_size<T>::value>>;

  template<typename T>
  concept array_like =
    has_tuple_size<T> && has_value_type<T> &&
    has_homogeneous_tuple_element<T, typename T::value_type, std::make_index_sequence<std::tuple_size<T>::value>>;

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
  // Helper concepts for construction checks on records
  //====================================================================================================================
  template<typename... Ts> struct set : Ts...
  {
    using Ts::operator()...;
    consteval void operator()(...);
  };
}
