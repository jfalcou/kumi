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

//==================================================================================================
// Helpers for uniqueness checking
//==================================================================================================
namespace kumi::_
{
  /// Wraps an NTTP to allow the unique detection trick to work correctly with naming.
  template<auto NTTP> struct value_as
  {
    using type = decltype(NTTP);
    static constexpr auto value = NTTP;
  };

  template<std::size_t I, typename T> consteval auto make_value_as()
  {
    if constexpr (requires { std::remove_cvref_t<T>::is_field_capture; }) return value_as<name_of(as<T>{})>{};
    else return value_as<I>{};
  }

  /// Used to detect duplicate types in a pack by enabling unique overload resolution.
  template<std::size_t, typename T> struct unique
  {
    operator T();
  };

  /// Named variant of unique
  /// For non field_capture types we generate a unique ID beeing it s position
  template<std::size_t I, typename T> struct unique_name
  {
    operator value_as<I>();
  };

  /// Named variant of unique
  template<std::size_t I, kumi::str Name, typename T> struct unique_name<I, kumi::field_capture<Name, T>>
  {
    operator value_as<Name>();
  };

  /// Helper used for SFINAE checks.
  inline std::true_type true_fn(...);
}
