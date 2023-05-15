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

namespace kumi
{
  //================================================================================================
  //! @ingroup traits
  //! @brief Opt-in traits for types behaving like a kumi::product_type
  //!
  //! To be treated like a tuple, an user defined type must supports structured bindings opt-in to
  //! kumi::product_type Semantic.
  //!
  //! This can be done in two ways:
  //!   - exposing an internal `is_product_type` type that evaluates to `void`
  //!   - specializing the `kumi::is_product_type` traits so it exposes a static constant member
  //!     `value` that evaluates to `true`
  //!
  //! ## Example:
  //! @include doc/adapt.cpp
  //==============================================================================================
  template<typename T, typename Enable = void> struct is_product_type : std::false_type {};
  template<typename T> struct is_product_type<T, typename T::is_product_type> : std::true_type {};

  //================================================================================================
  //! @ingroup traits
  //! @brief Computes the number of elements of a kumi::product_type
  //!
  //! @param T kumi::product_type to inspect
  //!
  //! ## Helper value
  //! @code
  //!   template<typename T> inline constexpr auto size_v = size<T>::value;
  //! @endcode
  //================================================================================================
  template<typename T> struct size : std::tuple_size<T>   {};
  template<typename T> struct size<T &>         : size<T> {};
  template<typename T> struct size<T &&>        : size<T> {};
  template<typename T> struct size<T const>     : size<T> {};
  template<typename T> struct size<T const &>   : size<T> {};
  template<typename T> struct size<T const &&>  : size<T> {};

  template<typename T> inline constexpr auto size_v = size<T>::value;
  //================================================================================================
  //! @ingroup traits
  //! @brief Provides indexed access to the types of the elements of a kumi::product_type.
  //!
  //! @tparam I Index of the type to retrieve
  //! @tparam T kumi::product_type to access
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<std::size_t I, typename T> using element_t = typename element<I,T>::type;
  //! }
  //! @endcode
  //================================================================================================
  template<std::size_t I, typename T> struct element              : std::tuple_element<I,T> {};
  template<std::size_t I, typename T> struct element<I,T&>        : element<I,T> {};
  template<std::size_t I, typename T> struct element<I,T&&>       : element<I,T> {};
  template<std::size_t I, typename T> struct element<I,T const&>  : element<I,T> {};
  template<std::size_t I, typename T> struct element<I,T const&&> : element<I,T> {};

  template<std::size_t I, typename T> using  element_t = typename element<I,T>::type;

  //================================================================================================
  //! @ingroup traits
  //! @brief Computes the return type of a call to kumi::get
  //!
  //! @tparam I Index of the type to retrieve
  //! @tparam T kumi::product_type to access
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<std::size_t I, typename T> using member_t = typename member<I,T>::type;
  //! }
  //! @endcode
  //================================================================================================
  template<std::size_t I, typename T> struct member
  {
    using type = decltype( get<I>(std::declval<T&>()));
  };

  template<std::size_t I, typename T> using  member_t = typename member<I,T>::type;

  // Forward declaration
  template<typename... Ts> struct tuple;
}

