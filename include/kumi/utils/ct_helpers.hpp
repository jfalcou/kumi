//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <cstddef>

namespace kumi
{
  //================================================================================================
  //! @ingroup utility
  //! @brief Helper to retrive the index of a type in a product type by it s type
  //!
  //! @note This function does not participate in overload resolution if the product type has
  //!       several instances of the same type.
  //!
  //! @return the index of the element of type U in the product type if it exist
  //================================================================================================
  template<typename U, concepts::product_type T>
  requires(concepts::typed_get_compliant<U, T>)
  consteval auto get_index_of_type()
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return _::get_index_by_type_v<U, element_t<I, T>...>;
    }(std::make_index_sequence<size_v<T>>{});
  }

  //================================================================================================
  //! @ingroup utility
  //! @brief Helper to retrive the index of a type in a product type by it s name
  //!
  //! @note This function does not participate in overload resolution if the product type has
  //!       several instances of the same name or has no name at all.
  //!
  //! @return the index of the element tagged with Name in the product type if it exist
  //================================================================================================
  template<concepts::identifier Name, concepts::product_type T>
  requires(concepts::named_get_compliant<Name, T>)
  consteval auto get_index_of_field()
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>) {
      return _::get_index_by_value_v<Name, element_t<I, T>...>;
    }(std::make_index_sequence<size_v<T>>{});
  }

  //================================================================================================
  //! @ingroup utility
  //! @brief Integral constant type
  //!
  //! Defines a integral constant wrapper used to carry compile-time constant through API
  //================================================================================================
  template<std::size_t N> struct index_t
  {
    /// Value stored by the constant
    static constexpr auto value = N;

    /// Conversion operator to integer
    constexpr inline operator std::size_t() const noexcept { return N; }
  };

  //================================================================================================
  //! @ingroup utility
  //! @brief Inline integral constant value for kumi::index_t
  //================================================================================================
  template<std::size_t N> inline constexpr index_t<N> const index = {};

  //================================================================================================
  //! @namespace literals
  //! @brief KUMI literals namespace
  //================================================================================================
  inline namespace literals
  {
    template<char... c> constexpr auto b10()
    {
      auto value = 0ULL;
      ((value = value * 10 + (c - '0')), ...);
      return value;
    }

    //==============================================================================================
    //! @ingroup utility
    //! @brief Forms a integral constant literal of the desired value.
    //! @return An instance of kumi::index_t for the specified integral value
    //! ## Example:
    //! @include doc/infra/index.cpp
    //==============================================================================================
    template<char... c> constexpr auto operator""_c() noexcept
    {
      return index<b10<c...>()>;
    }

    //==============================================================================================
    //! @ingroup utility
    //! @brief Forms a constant string literal of the desired value.
    //! @return An instance of kumi::name for the specified string
    //==============================================================================================
    template<kumi::str ID> constexpr auto operator""_id() noexcept
    {
      return name<ID>{};
    }
  }

  //================================================================================================
  //! @ingroup utility
  //! @brief Convert a unary template meta-program in a running predicate
  //! @tparam Pred Unary template meta-program to convert.
  //! @return A Callable Object applying Pred to the type of its arguments
  //================================================================================================
  template<template<class> class Pred> [[nodiscard]] constexpr auto predicate() noexcept
  {
    return []<typename T>(T const&) constexpr { return Pred<T>::value; };
  }
}
