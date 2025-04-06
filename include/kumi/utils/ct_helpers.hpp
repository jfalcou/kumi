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
  //! @brief Integral constant type
  //!
  //! Defines a integral constant wrapper used to carry compile-time constant through API
  //================================================================================================
  template<std::size_t N> struct index_t
  {
    /// Value stored by the constant
    static constexpr auto value = N;

    /// Conversion operator to integer
    constexpr inline      operator std::size_t() const noexcept { return N; }
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
  namespace literals
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
    //! @include doc/index.cpp
    //==============================================================================================
    template<char... c> constexpr auto operator""_c() noexcept { return index<b10<c...>()>; }
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
