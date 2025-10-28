//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <cstddef>
#include <kumi/detail/field_capture.hpp>
#include <kumi/detail/indexes.hpp>

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
  //! @ingroup utility 
  //! @class field_name
  //! @brief Named wrapper used to instantiate a kumi::field_capture.
  //!
  //! kumi::field_name provides a way to instantiate a kumi::field_capture using
  //! a user defined literal prefix.
  //!
  //! @tparam ID a compile time string that is used to name the field.
  //================================================================================================
  template<str ID> struct field_name
  {
    /// Name associated to the field_name
    static constexpr auto name = ID;
    
    /// Conversion operator to kumi::str 
    constexpr inline operator str() const noexcept { return ID; }

    //==============================================================================================
    //! @brief Builds a field_capture from the given value.
    //! @tparam T The type to wrap.
    //! @param  v The value to capture. 
    //! @return A kumi::field_capture containing the value.
    //==============================================================================================
    template<typename T>
    constexpr field_capture<ID, std::unwrap_ref_decay_t<T>> operator=(T v) const
    {
      return { std::move(v) };
    }
  };

  //==============================================================================================
  //! @ingroup utility 
  //! @brief Forms a constant kumi::field_name of the desired ID.
  //! @tparam ID the compile time name to build.
  //==============================================================================================
  template<str ID> inline constexpr auto field = field_name<ID>{};

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
    //! @include doc/index.cpp
    //==============================================================================================
    template<char... c> constexpr auto operator""_c() noexcept { return index<b10<c...>()>; }
    
    //==============================================================================================
    //! @ingroup utility 
    //! @brief Forms a constant string literal of the desired value.
    //! @return An instance of kumi::field_name for the specified string
    //==============================================================================================
    template<kumi::str ID> constexpr auto operator""_f() noexcept { return field<ID>; }
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
