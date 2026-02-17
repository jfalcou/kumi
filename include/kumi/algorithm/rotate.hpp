//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

namespace kumi
{
  //================================================================================================
  //! @ingroup generators
  //! @brief  Rotates the element of a product type R positions to the left, wrapping around when
  //!         getting to the beginning.
  //!
  //! @tparam R Rotation factor
  //! @param t  Product type to rotate.
  //! @return   A product type equivalent to t with elements rotated R positions to the left.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<std::size_t R, product_type T> struct rotate_left;
  //!
  //!   template<std::size_t R, product_type T>
  //!   using rotate_left_t = typename rotate_left<R, T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::rotate_left
  //!
  //! ## Example
  //! @include doc/tuple/algo/rotate_left.cpp
  //! @include doc/tuple/algo/rotate_left.cpp
  //================================================================================================
  template<std::size_t R, concepts::product_type T> constexpr auto rotate_left(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return KUMI_FWD(t);
    else if constexpr ((R % size_v<T>) == 0) return KUMI_FWD(t);
    else
    {
      constexpr auto idxs = _::rotator<size_v<T>, R % size_v<T>>();
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using type = builder_make_t<T, element_t<idxs.t[I], T>...>;
        return type{get<idxs.t[I]>(KUMI_FWD(t))...};
      }(std::make_index_sequence<size_v<T>>{});
    }
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief  Rotates the element of a product type R positions to the right, wrapping around when
  //!         getting to the end.
  //!
  //! @tparam R Rotation factor
  //! @param t  Product type to rotate.
  //! @return   A product type equivalent to t with elements rotated R positions to the right.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<std::size_t R, product_type T> struct rotate_right;
  //!
  //!   template<std::size_t R, product_type T>
  //!   using rotate_right_t = typename rotate_right<R, T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::rotate_right
  //!
  //! ## Example
  //! @include doc/tuple/algo/rotate_right.cpp
  //! @include doc/tuple/algo/rotate_right.cpp
  //================================================================================================
  template<std::size_t R, concepts::product_type T> constexpr auto rotate_right(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return KUMI_FWD(t);
    else if constexpr ((R % size_v<T>) == 0) return KUMI_FWD(t);
    else
    {
      constexpr auto F = R % size_v<T>;
      constexpr auto idxs = _::rotator<size_v<T>, size_v<T> - F>();
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using type = builder_make_t<T, element_t<idxs.t[I], T>...>;
        return type{get<idxs.t[I]>(KUMI_FWD(t))...};
      }(std::make_index_sequence<size_v<T>>{});
    }
  }

  namespace result
  {
    template<std::size_t R, concepts::product_type T> struct rotate_left
    {
      using type = decltype(kumi::rotate_left<R>(std::declval<T>()));
    };

    template<std::size_t R, concepts::product_type T> struct rotate_right
    {
      using type = decltype(kumi::rotate_right<R>(std::declval<T>()));
    };

    template<std::size_t R, concepts::product_type T> using rotate_left_t = typename rotate_left<R, T>::type;

    template<std::size_t R, concepts::product_type T> using rotate_right_t = typename rotate_right<R, T>::type;
  }
}
