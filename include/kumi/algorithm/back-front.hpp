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
  //! @ingroup queries 
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
  //! ## Examples
  //! @include doc/tuple/algo/back-front.cpp
  //! @include doc/record/algo/back-front.cpp
  //================================================================================================
  template<concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) front(T&& t)
  requires(size_v<T> != 0)
  {
    if constexpr (concepts::record_type<T>) return front(values_of(KUMI_FWD(t)));
    else return get<0>(KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup queries 
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
  //! ## Examples
  //! @include doc/tuple/algo/back-front.cpp
  //! @include doc/record/algo/back-front.cpp
  //================================================================================================
  template<concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr decltype(auto) back(T&& t)
  requires(size_v<T> != 0)
  {
    if constexpr (concepts::record_type<T>) return back(values_of(KUMI_FWD(t)));
    else return get<size_v<T> - 1>(KUMI_FWD(t));
  }

  namespace result
  {
    template<concepts::product_type T> struct front : raw_member<0, T>
    {
    };

    template<concepts::product_type T> struct back : raw_member<size_v<T> - 1, T>
    {
    };

    template<concepts::product_type T> using front_t = typename front<T>::type;
    template<concepts::product_type T> using back_t = typename back<T>::type;
  }
}
