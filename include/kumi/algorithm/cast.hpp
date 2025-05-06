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
  //! @param  b kumi::tuple to convert
  //! @return A tuple of type Target containing the values of b
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Target, product_type Base> struct tuple_cast;
  //!
  //!   template<product_type Target, Product_type Base>
  //!   using tuple_cast_t = typename tuple_cast<Target, Base>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::tuple_cast
  //!
  //! ## Example
  //! @include doc/tuple_cast.cpp
  //================================================================================================
  template<product_type Target, product_type Base>
  requires(  _::piecewise_convertible<Base, std::remove_cvref_t<Target>>
          && (size_v<Base> == size_v<Target>)
          && (!std::same_as<Base, Target>)
          )
  [[nodiscard]] constexpr Target tuple_cast(Base const& b)
  {
    return map_index([](auto idx, auto && elem)
      {
        return static_cast<kumi::element_t<idx, Target>>(elem);
      }
      , b
    );
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
  [[nodiscard]] constexpr auto member_cast(Base const& b)
  {
    return map([](auto && elem){ return static_cast<Target>(elem); }, b);
  }

  namespace result
  {
    template<product_type Target, product_type Base> struct tuple_cast
    {
      using type = decltype( kumi::tuple_cast<Target, Base>( std::declval<Base>() ) );
    };
    
    template<typename Target, product_type Base> struct member_cast 
    {
      using type = decltype( kumi::member_cast<Target, Base>( std::declval<Base>() ) );
    };

    template<product_type Target, product_type Base>
    using tuple_cast_t = typename tuple_cast<Target,Base>::type;

    template<typename Target, product_type Base>
    using member_cast_t = typename member_cast<Target,Base>::type;
  }
}
