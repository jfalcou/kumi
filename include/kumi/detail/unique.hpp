//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <cstddef>

//====================================================================================================================
// Helpers for uniqueness checking
//====================================================================================================================
namespace kumi::_
{
  template <std::size_t, typename T> struct unique { operator T(); };
  

  template <std::size_t, typename T> struct unique_name{ };

  template <std::size_t I, typename T> 
  requires (requires { T::type::is_field_capture; })
  struct unique_name<I, T> 
  {
    operator T();
  };
     
  inline std::true_type true_fn(...);
}
