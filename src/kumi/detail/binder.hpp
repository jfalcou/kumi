//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <cstddef>
#include <utility>

namespace kumi::detail
{
  //==============================================================================================
  // Tuple leaf binder tricks
  //==============================================================================================
  template<std::size_t I, typename T> struct leaf
  {
    T value;
  };

  template<std::size_t I, typename T> constexpr T &get_leaf(leaf<I, T> &arg) noexcept
  {
    return arg.value;
  }

  template<std::size_t I, typename T> constexpr T &&get_leaf(leaf<I, T> &&arg) noexcept
  {
    return static_cast<T &&>(arg.value);
  }

  template<std::size_t I, typename T>
  constexpr T const &&get_leaf(leaf<I, T> const &&arg) noexcept
  {
    return static_cast<T const &&>(arg.value);
  }

  template<std::size_t I, typename T> constexpr T const &get_leaf(leaf<I, T> const &arg) noexcept
  {
    return arg.value;
  }

  template<typename ISeq, typename... Ts> struct binder;

  template<auto... Is, typename... Ts>
  struct binder<std::index_sequence<Is...>, Ts...> : leaf<Is, Ts>...
  {
  };
}
