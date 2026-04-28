//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi
{
  namespace _
  {
    template<char... c> constexpr auto b10()
    {
      auto value = 0ULL;
      ((value = value * 10 + (c - '0')), ...);
      return value;
    }
  }

  //====================================================================================================================
  /**
    @ingroup types
    @class index_t
    @brief Integral constant type

    Defines a integral constant wrapper used to carry compile-time constant through API
  **/
  //====================================================================================================================
  template<std::size_t N> struct index_t
  {
    /// Value stored by the constant
    static constexpr auto value = N;

    /// Conversion operator to integer
    constexpr inline operator std::size_t() const noexcept { return N; }
  };

  //====================================================================================================================
  /**
    @ingroup utility
    @brief Inline integral constant value for kumi::index_t
  **/
  //====================================================================================================================
  template<std::size_t N> inline constexpr kumi::index_t<N> const index = {};

  //====================================================================================================================
  /**
    @ingroup types
    @class label_t
    @brief Literal constant type

    Defines a Literal constant wrapper used to carry compile-time strings through API
  **/
  //====================================================================================================================
  template<kumi::str Label> struct label_t
  {
    using type = str;

    /// Value stored by the constant
    static constexpr kumi::str value = Label;

    /// Conversion operator to kumi::str
    constexpr inline operator kumi::str() const noexcept { return Label; }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, label_t const&) noexcept
    {
      return os << value;
    }
  };

  //====================================================================================================================
  /**
    @ingroup utility
    @brief Inline literal constant value for kumi::label_t
  **/
  //====================================================================================================================
  template<str Label> inline constexpr kumi::label_t<Label> label = {};

  //====================================================================================================================
  /**
    @namespace literals
    @brief KUMI literals namespace
  **/
  //====================================================================================================================
  inline namespace literals
  {
    //==================================================================================================================
    /**
      @ingroup utility
      @brief Forms a integral constant literal of the desired value.
      @return An instance of kumi::index_t for the specified integral value
      ## Example:
      @include doc/infra/index.cpp
    **/
    //==================================================================================================================
    template<char... c> constexpr auto operator""_c() noexcept
    {
      return kumi::index<kumi::_::b10<c...>()>;
    }

    //==================================================================================================================
    /**
      @ingroup utility
      @brief Forms a constant string literal of the desired value.
      @return An instance of kumi::name for the specified string
      ##Example:
      @include doc/infra/name.cpp
    **/
    //==================================================================================================================
    template<kumi::str ID> constexpr auto operator""_id() noexcept
    {
      return kumi::name<ID>{};
    }

    //==================================================================================================================
    /**
      @ingroup utility
      @brief Forms a constant string literal of the desired value.
      @return An instance of kumi::label for the specified string

      @note It differs from the ""_id operator on the type and the overload that it will pick up. An identifier
      and a label are two different parts of a field. Label represents the value that is displayed.

      ##Example:
      @include doc/infra/label.cpp
    **/
    //==================================================================================================================
    template<kumi::str ID> constexpr auto operator""_l() noexcept
    {
      return kumi::label<ID>;
    }
  }

  //====================================================================================================================
  /**
    @ingroup utility
    @brief Convert a unary template meta-program in a running predicate
    @tparam Pred Unary template meta-program to convert.
    @return A Callable Object applying Pred to the type of its arguments
  **/
  //====================================================================================================================
  template<template<class> class Pred> [[nodiscard]] constexpr auto predicate() noexcept
  {
    return []<typename T>(T const&) constexpr { return Pred<T>::value; };
  }

  //====================================================================================================================
  /**
    @ingroup utility
    @brief Helper to retrive the index of a type in a product type by it s type

    @note This function does not participate in overload resolution if the product type has several instances of the
          same type or if it is empty.

    @return the index of the element of type U in the product type if it exist
  **/
  //====================================================================================================================
  template<typename U, kumi::concepts::product_type T>
  KUMI_ABI consteval auto get_index_of_type()
  requires(kumi::concepts::queryable_by_type<U, T>)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return kumi::_::get_index_by_type_v<U, kumi::stored_element_t<I, T>...>;
    }(std::make_index_sequence<kumi::size_v<T>>{});
  }

  //====================================================================================================================
  /**
    @ingroup utility
    @brief Helper to retrive the index of a type in a product type by it s identifier

    @note This function does not participate in overload resolution if the product type has several instances of the
          same identifier or has no identifier at all.

    @return the index of the element whose identifier matches Id in the product type if it exist
  **/
  //====================================================================================================================
  template<kumi::concepts::identifier Id, kumi::concepts::product_type T>
  KUMI_ABI consteval auto get_index_of_field()
  requires(kumi::concepts::queryable_by_identifier<Id, T>)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return kumi::_::get_index_by_value_v<Id, kumi::element_t<I, T>...>;
    }(std::make_index_sequence<kumi::size_v<T>>{});
  }

  //====================================================================================================================
  /**
    @ingroup utility
    @brief Helper to retrive the index of a type in a product type by it s identifier

    @note This function does not participate in overload resolution if the product type has several instances of the
          same identifier or has no identifier at all.

    @return the index of the element whose identifier matches Id in the product type if it exist
  **/
  //====================================================================================================================
  template<kumi::str L, kumi::concepts::product_type T>
  KUMI_ABI consteval auto get_index_of_label()
  requires(kumi::concepts::queryable_by_label<kumi::label_t<L>, T>)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return kumi::_::get_index_by_label_v<kumi::label_t<L>, kumi::element_t<I, T>...>;
    }(std::make_index_sequence<kumi::size_v<T>>{});
  }
}
