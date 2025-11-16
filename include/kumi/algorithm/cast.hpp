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
  //! @brief Converts a kumi::product_type to an instance of an other kumi::product_type
  //!
  //! @tparam Target kumi::product_type to generate 
  //! @param  b kumi::tuple to cast values from
  //! @return A tuple of type Target containing the values of b
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Target, product_type Base> struct product_type_cast;
  //!
  //!   template<product_type Target, Product_type Base>
  //!   using product_type_cast_t = typename product_type_cast<Target, Base>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::product_type_cast
  //!
  //! ## Example
  //! @include doc/product_type_cast.cpp
  //================================================================================================
  template<product_type Target, sized_product_type<size_v<Target>> Base>
  requires( follows_same_semantic<Target, Base> && (!std::same_as<Base, Target>))
  [[nodiscard]] constexpr Target product_type_cast(Base && b)
  {
    if constexpr ( sized_product_type<Base, 0> ) return Target{};
    else if constexpr ( record_type<Base> ) return [&]<std::size_t...I>(std::index_sequence<I...>)
    {
      return Target{ field_cast<element_t<I,Target>>(get<I>(KUMI_FWD(b)))... };
    }(std::make_index_sequence<size_v<Target>>{});
    else return [&]<std::size_t...I>(std::index_sequence<I...>)
    {
      return Target{ static_cast<element_t<I,Target>>(get<I>(KUMI_FWD(b)))... };
    }(std::make_index_sequence<size_v<Target>>{});
  }

  //================================================================================================
  //! @ingroup utility
  //! @brief Converts a kumi::product_type to an instance of an other kumi::product_type
  //!
  //! @tparam Target type to generate 
  //! @param  b kumi::tuple to convert
  //! @return A tuple containing the values of b where each member is of type Target 
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
  [[nodiscard]] constexpr auto member_cast(Base && b)
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
    template<product_type Target, product_type Base> struct product_type_cast
    {
      using type = decltype( kumi::product_type_cast<Target, Base>( std::declval<Base>() ) );
    };
    
    template<typename Target, product_type Base> struct member_cast 
    {
      using type = decltype( kumi::member_cast<Target, Base>( std::declval<Base>() ) );
    };

    template<product_type Target, product_type Base>
    using product_type_cast_t = typename product_type_cast<Target,Base>::type;

    template<typename Target, product_type Base>
    using member_cast_t = typename member_cast<Target,Base>::type;
  }
}
