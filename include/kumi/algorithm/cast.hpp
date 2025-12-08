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
  //! @ingroup utility
  //! @brief Converts a product_type<Ts...> to an instance of a product_type<Target...>
  //!
  //! @tparam Target type to generate 
  //! @param  b Product type to convert
  //! @return A Product type containing the values of b where each member is of type Target 
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Target, product_type Base> struct member_cast;
  //!
  //!   template<product_type Target, Product_type Base>
  //!   using member_cast_t = typename member_cast<Target, Base>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::member_cast
  //!
  //! ## Example
  //! @include doc/member_cast.cpp
  //================================================================================================
  template<typename Target, product_type Base>
  [[nodiscard]] KUMI_ABI constexpr auto member_cast(Base && b)
  {
    if constexpr ( sized_product_type<Base,0> ) return b;
    else if constexpr ( record_type<Base> ) return [&]<std::size_t...I>(std::index_sequence<I...>)
    {
        return _::builder<Base>::make(  ( field<name_of(as<element_t<I,Base>>{})> 
                                        = field_cast<Target>(get<I>(KUMI_FWD(b))))... );
    }(std::make_index_sequence<size_v<Base>>{}); 
    else return [&]<std::size_t...I>(std::index_sequence<I...>)
    {
      return _::builder<Base>::make( (static_cast<Target>(get<I>(KUMI_FWD(b))))... );
    }(std::make_index_sequence<size_v<Base>>{}); 
  }

  namespace result
  {    
    template<typename Target, product_type Base> struct member_cast 
    {
      using type = decltype( kumi::member_cast<Target, Base>( std::declval<Base>() ) );
    };

    template<typename Target, product_type Base>
    using member_cast_t = typename member_cast<Target,Base>::type;
  }
}
