//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi
{
  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Retrieves the front of a product type

    @param t  Base product type
    @return   A reference to the first element of the product type `t`.

    @note This function does not take part in overload resolution if t is an empty product type.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T> struct front;

      template<product_type T>
      using front_t = typename front<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::front

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/back-front.cpp
    ### Record:
    @include doc/record/algo/back-front.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::non_empty_product_type T> [[nodiscard]] KUMI_ABI constexpr decltype(auto) front(T&& t)
  {
    if constexpr (kumi::concepts::record_type<T>) return kumi::front(kumi::values_of(KUMI_FWD(t)));
    else return get<0>(KUMI_FWD(t));
  }

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Retrieves the back of a product type

    @param t  Base product type
    @return   A reference to the last element of the product type `t`

    @note This function does not take part in overload resolution if t is an empty product type.

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type T> struct back;

      template<product_type T>
      using back_t = typename back<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::back

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/back-front.cpp
    ### Record:
    @include doc/record/algo/back-front.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::non_empty_product_type T> [[nodiscard]] KUMI_ABI constexpr decltype(auto) back(T&& t)
  {
    if constexpr (kumi::concepts::record_type<T>) return kumi::back(values_of(KUMI_FWD(t)));
    else return get<kumi::size_v<T> - 1>(KUMI_FWD(t));
  }

  namespace result
  {
    template<kumi::concepts::product_type T> struct front : kumi::stored_member<0, T>
    {
    };

    template<kumi::concepts::product_type T> struct back : kumi::stored_member<kumi::size_v<T> - 1, T>
    {
    };

    template<kumi::concepts::product_type T> using front_t = typename front<T>::type;
    template<kumi::concepts::product_type T> using back_t = typename back<T>::type;
  }
}
