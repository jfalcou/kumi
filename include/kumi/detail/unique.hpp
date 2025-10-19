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
  /// Used to detect duplicate types in a pack by enabling unique overload resolution.
  template <std::size_t, typename T> struct unique { operator T(); };
    
  /// Named variant of unique
  template <std::size_t, typename T> struct unique_name{ };

  template <std::size_t I, typename T> 
  requires (requires { T::type::is_field_capture; })
  struct unique_name<I, T> 
  {
    operator T();
  };
    
  /// Helper used for SFINAE checks.
  inline std::true_type true_fn(...);

  /// Wraps a type to allow the unique detection trick to work correctly. 
  template<typename T> struct box { using type = T; };
}
