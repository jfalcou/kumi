//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <cstddef>

//==================================================================================================
// Helpers for uniqueness checking
//==================================================================================================
namespace kumi::_
{
  using invalid = std::integral_constant<std::size_t, static_cast<std::size_t>(-1)>;

  template<typename... Ts> struct type_list
  {
  };

  /// Wraps an NTTP to allow the unique detection trick to work correctly with naming.
  template<auto V> struct value_identity
  {
    static constexpr auto value = V;
  };

  template<std::size_t I, typename T> consteval auto get_value_identity()
  {
    using type = std::remove_cvref_t<T>;
    if constexpr (requires { type::is_field_capture; }) return value_identity<type::name>{};
    else return value_identity<I>{};
  }

  /// Used to detect duplicate types in a pack by enabling unique overload resolution.
  template<std::size_t, typename T> struct unique
  {
    operator std::type_identity<T>();
  };

  /// Named variant of unique
  /// For non field_capture types we generate a unique ID beeing it s position
  template<std::size_t I, typename T> struct unique_name
  {
    operator value_identity<I>();
  };

  /// Named variant of unique
  template<std::size_t I, kumi::str Name, typename T> struct unique_name<I, kumi::field_capture<Name, T>>
  {
    operator value_identity<Name>();
  };

  /// Helper used for SFINAE checks.
  inline consteval std::true_type true_fn(...);
}
