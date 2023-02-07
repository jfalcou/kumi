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
  template<int I, typename T> struct leaf
  {
    T value;
  };

  template<int I, typename T> constexpr T &get_leaf(leaf<I, T> &arg) noexcept
  {
    return arg.value;
  }

  template<int I, typename T> constexpr T &&get_leaf(leaf<I, T> &&arg) noexcept
  {
    return static_cast<T &&>(arg.value);
  }

  template<int I, typename T>
  constexpr T const &&get_leaf(leaf<I, T> const &&arg) noexcept
  {
    return static_cast<T const &&>(arg.value);
  }

  template<int I, typename T> constexpr T const &get_leaf(leaf<I, T> const &arg) noexcept
  {
    return arg.value;
  }

  template<typename ISeq, typename... Ts> struct binder;


  // General N-case
  template<int... Is, typename... Ts>
  struct binder<std::integer_sequence<int,Is...>, Ts...> : leaf<Is, Ts>...
  {
  };

  // Specializable binder type constructor
  template<typename ISeq, typename... Ts>
  struct make_binder
  {
    using type = binder<ISeq,Ts...>;
  };

  template<typename ISeq, typename... Ts>
  using make_binder_t = typename make_binder<ISeq,Ts...>::type;
}

#include <kumi/detail/optimized.hpp>
