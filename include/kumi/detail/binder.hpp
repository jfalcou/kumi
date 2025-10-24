//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <cstddef>
#include <utility>

#include <kumi/detail/field_capture.hpp>

namespace kumi::_
{
  //====================================================================================================================
  // Tuple leaf binder tricks
  //====================================================================================================================
  template<int I, typename T> struct leaf
  {
    T value;
  };

  // Optimized leaf binder for record
  template<int I, kumi::str Name, typename T> struct leaf<I, field_capture<Name, T>>
  {
      field_capture<Name, T> value;
  };

  // Used for get_leaf<index>(binder) resolution
  template<int I, typename T>
  KUMI_ABI constexpr T       &  get_leaf(leaf<I, T>       & a) noexcept { return a.value; }
  template<int I, typename T>
  KUMI_ABI constexpr T       && get_leaf(leaf<I, T>       &&a) noexcept { return static_cast<T&&>(a.value); }
  template<int I, typename T>
  KUMI_ABI constexpr T const && get_leaf(leaf<I, T> const &&a) noexcept { return static_cast<T const &&>(a.value); }
  template<int I, typename T>
  KUMI_ABI constexpr T const &  get_leaf(leaf<I, T> const & a) noexcept { return a.value; }

  // Used for get_leaf<type>(binder) resolution
  template< typename T, int I>
  KUMI_ABI constexpr T       &  get_leaf(leaf<I, T>       & a) noexcept { return a.value; }
  template< typename T, int I>
  KUMI_ABI constexpr T       && get_leaf(leaf<I, T>       &&a) noexcept { return static_cast<T&&>(a.value); }
  template< typename T, int I>
  KUMI_ABI constexpr T const && get_leaf(leaf<I, T> const &&a) noexcept { return static_cast<T const &&>(a.value); }
  template< typename T, int I>
  KUMI_ABI constexpr T const &  get_leaf(leaf<I, T> const & a) noexcept { return a.value; }

  // Used for get_leaf<name>(binder) resolution
  template<kumi::str Name, int I, typename T>
  KUMI_ABI constexpr T&         get_leaf(leaf<I, field_capture<Name, T>>       & a) noexcept { return a.value.value; }
  template<kumi::str Name, int I, typename T>
  KUMI_ABI constexpr T&&        get_leaf(leaf<I, field_capture<Name, T>>       &&a) noexcept { return static_cast<T&&>(a.value.value); }
  template<kumi::str Name, int I, typename T>
  KUMI_ABI constexpr T const&&  get_leaf(leaf<I, field_capture<Name, T>> const &&a) noexcept { return static_cast<T const &&>(a.value.value); }
  template<kumi::str Name, int I, typename T>
  KUMI_ABI constexpr T const &  get_leaf(leaf<I, field_capture<Name, T>> const & a) noexcept { return a.value.value; }

  template<typename ISeq, typename... Ts> struct binder;

  // General N-case
  template<int... Is, typename... Ts>
  struct binder<std::integer_sequence<int,Is...>, Ts...> : leaf<Is, Ts>...
  {
    static constexpr bool is_homogeneous = false;
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
