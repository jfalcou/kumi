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
    @brief    Converts a product_type<Ts...> to an instance of a product_type<Target...>

    @tparam Target destination type to associate to each member of the product type `t`
    @param  t Product type to convert
    @return A Product type containing the values of `t` where each member is of type Target

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Target, product_type T> struct member_cast;

      template<typename Target, Product_type T>
      using member_cast_t = typename member_cast<Target, T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::member_cast

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/member_cast.cpp
    ### Record:
    @include doc/record/algo/member_cast.cpp
  **/
  //====================================================================================================================
  template<typename Target, kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto member_cast(T&& t)
  {
    if constexpr (kumi::concepts::empty_product_type<T>) return t;
    else if constexpr (kumi::concepts::record_type<T>)
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using type = builder_make_t<T, kumi::result::field_cast_t<Target, kumi::element_t<I, T>>...>;
        return type{kumi::field_cast<Target>(get<I>(KUMI_FWD(t)))...};
      }(std::make_index_sequence<kumi::size_v<T>>{});
    else
    {
      using type = kumi::_::as_homogeneous_t<Target, kumi::size_v<T>>;
      return static_cast<type>(KUMI_FWD(t));
    }
  }

  namespace result
  {
    template<typename Target, kumi::concepts::product_type T> struct member_cast
    {
      using type = decltype(kumi::member_cast<Target, T>(std::declval<T>()));
    };

    template<typename Target, kumi::concepts::product_type T>
    using member_cast_t = typename kumi::result::member_cast<Target, T>::type;
  }
}
