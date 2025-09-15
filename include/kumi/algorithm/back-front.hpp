//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/detail/abi.hpp>

namespace kumi
{
  //================================================================================================
  //! @ingroup utility
  //! @brief Retrieves the front of a product type
  //!
  //! @param t Base product type
  //! @return A reference to the first element of the product type `t`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct front;
  //!
  //!   template<product_type T>
  //!   using front_t = typename front<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::front
  //!
  //! ## Example
  //! @include doc/back-front.cpp
  //================================================================================================
  template<product_type T>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) front(T && t) requires( size_v<T> != 0)
  {
    return get<0>(KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup utility
  //! @brief Retrieves the back of a product type
  //!
  //! @param t Base product type
  //! @return A reference to the last element of the product type `t`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct back;
  //!
  //!   template<product_type T>
  //!   using back_t = typename back<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::back
  //!
  //! ## Example
  //! @include doc/back-front.cpp
  //================================================================================================
  template<product_type T>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) back(T && t) requires( size_v<T> != 0)
  {
    return get<size_v<T>-1>(KUMI_FWD(t));
  }

  namespace result
  {
    template<product_type T> struct front : member<0,T> {};
    template<product_type T> struct back  : member<size_v<T>-1,T> {};

    template<product_type T> using front_t = typename front<T>::type;
    template<product_type T> using back_t  = typename back<T>::type;
  }
}
