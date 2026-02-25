//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

//==================================================================================================
// Helpers for uniqueness checking
//==================================================================================================
namespace kumi::_
{
  template<std::size_t I, typename T> consteval auto get_key()
  {
    using type = std::remove_cvref_t<T>;
    if constexpr (_::field<T>) return typename type::identifier_type{};
    else return std::integral_constant<std::size_t, I>{};
  }

  /// Used to detect duplicate types in a pack by enabling unique overload resolution.
  template<std::size_t, typename T> struct unique
  {
    operator std::type_identity<T>();
  };

  /// Named variant of unique
  template<std::size_t I, typename T> struct unique_name
  {
    operator std::integral_constant<std::size_t, I>();
  };

  /// Named variant of unique
  template<std::size_t I, _::field T> struct unique_name<I, T>
  {
    operator typename std::remove_cvref_t<T>::identifier_type();
  };

  /// Helper used for SFINAE checks.
  inline consteval std::true_type true_fn(...);
}
