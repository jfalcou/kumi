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

namespace kumi::_
{
  //====================================================================================================================
  // Tuple leaf binder tricks
  //====================================================================================================================
  template<int N, typename T> struct leaf
  {
    T value;
    using index = std::integral_constant<std::size_t, N>;
    using inner_type = std::type_identity<T>;

    KUMI_ABI constexpr T& operator()(index) & noexcept { return value; }

    KUMI_ABI constexpr T&& operator()(index) && noexcept { return static_cast<T&&>(value); }

    KUMI_ABI constexpr T const&& operator()(index) const&& noexcept { return static_cast<T const&&>(value); }

    KUMI_ABI constexpr T const& operator()(index) const& noexcept { return value; }

    KUMI_ABI constexpr T& operator()(inner_type) & noexcept { return value; }

    KUMI_ABI constexpr T&& operator()(inner_type) && noexcept { return static_cast<T&&>(value); }

    KUMI_ABI constexpr T const&& operator()(inner_type) const&& noexcept { return static_cast<T const&&>(value); }

    KUMI_ABI constexpr T const& operator()(inner_type) const& noexcept { return value; }
  };

  // Empty Base Optimization
  template<int N, typename T>
  requires(std::is_empty_v<T> && (!_::field<T>))
  struct leaf<N, T> : T
  {
    using index = std::integral_constant<std::size_t, N>;
    using inner_type = std::type_identity<T>;

    KUMI_ABI constexpr T& operator()(index) & noexcept { return *this; }

    KUMI_ABI constexpr T&& operator()(index) && noexcept { return static_cast<T&&>(*this); }

    KUMI_ABI constexpr T const&& operator()(index) const&& noexcept { return static_cast<T const&&>(*this); }

    KUMI_ABI constexpr T const& operator()(index) const& noexcept { return *this; }

    KUMI_ABI constexpr T& operator()(inner_type) & noexcept { return *this; }

    KUMI_ABI constexpr T&& operator()(inner_type) && noexcept { return static_cast<T&&>(*this); }

    KUMI_ABI constexpr T const&& operator()(inner_type) const&& noexcept { return static_cast<T const&&>(*this); }

    KUMI_ABI constexpr T const& operator()(inner_type) const& noexcept { return *this; }
  };

  template<int N, _::field T> struct leaf<N, T> : T
  {
    using T::operator();
    using index = std::integral_constant<std::size_t, N>;
    using key = key_of_t<T>;
    using inner_type = type_of_t<T>;

    KUMI_ABI constexpr T& operator()(index) & noexcept { return *this; }

    KUMI_ABI constexpr T&& operator()(index) && noexcept { return static_cast<T&&>(*this); }

    KUMI_ABI constexpr T const&& operator()(index) const&& noexcept { return static_cast<T const&&>(*this); }

    KUMI_ABI constexpr T const& operator()(index) const& noexcept { return *this; }
  };

  template<typename ISeq, typename... Ts> struct binder;

  // General N-case
  template<int... Is, typename... Ts> struct binder<std::integer_sequence<int, Is...>, Ts...> : leaf<Is, Ts>...
  {
    static constexpr bool is_homogeneous = false;
    using leaf<Is, Ts>::operator()...;
  };

  // Specializable binder type constructor
  template<typename ISeq, typename... Ts> struct make_binder
  {
    using type = binder<ISeq, Ts...>;
  };

  template<typename ISeq, typename... Ts> using make_binder_t = typename make_binder<ISeq, Ts...>::type;
}
