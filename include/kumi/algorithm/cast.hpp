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
  namespace _
  {
    template<typename T, auto> struct repeat { using type = T; };
    template<typename T, auto I> using repeat_t = typename repeat<T,I>::type;
  }
  //================================================================================================
  //! @ingroup utility
  //! @brief Converts a product_type<Types...> to an instance of a product_type<Ts...>
  //!
  //! @tparam Ts destination types to of each member of the product type 
  //! @param  t Product type to convert
  //! @return A Product type containing the values of t where each member type is the corresponding
  //!         type in the input pack.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename... Ts, product_type T> struct type_cast;
  //!
  //!   template<typename... Ts, product_type T>
  //!   using type_cast_t = typename type_cast<Ts..., T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::type_cast
  //!
  //! ## Example
  //! @include doc/type_cast.cpp
  //================================================================================================
  template<typename... Ts, product_type T>
  requires ( sizeof...(Ts) == size_v<T> )
  [[nodiscard]] KUMI_ABI constexpr auto type_cast(T && t)
  {
    if constexpr ( sized_product_type<T,0> ) return t;
    else if constexpr ( record_type<T> ) return [&]<std::size_t...I>(std::index_sequence<I...>)
    {
      using type = _::builder_make_t<T, result::field_cast_t<Ts, element_t<I,T>>...>;
      return type{ field_cast<Ts>(get<I>(KUMI_FWD(t)))... };
    }(std::make_index_sequence<size_v<T>>{}); 
    else return [&]<std::size_t...I>(std::index_sequence<I...>)
    {
      using type = _::builder_make_t<T, Ts...>;
      return type{ static_cast<Ts>(get<I>(KUMI_FWD(t)))... };
    }(std::make_index_sequence<size_v<T>>{}); 
  }
 
  //================================================================================================
  //! @ingroup utility
  //! @brief Converts a product_type<Ts...> to an instance of a product_type<Target...>
  //!
  //! @tparam Target destination type to assocaite to each member of the product type 
  //! @param  t Product type to convert
  //! @return A Product type containing the values of b where each member is of type Target 
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Target, product_type T> struct member_cast;
  //!
  //!   template<typename Target, Product_type T>
  //!   using member_cast_t = typename member_cast<Target, T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::member_cast
  //!
  //! ## Example
  //! @include doc/member_cast.cpp
  //================================================================================================
  template<typename Target, product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto member_cast(T && t)
  {
    if constexpr ( sized_product_type<T,0> ) return t;
    else if constexpr ( record_type<T> ) return [&]<std::size_t...I>(std::index_sequence<I...>)
    {
      using type = _::builder_make_t<T, result::field_cast_t<Target, element_t<I,T>>...>;
      return type { field_cast<Target>(get<I>(KUMI_FWD(t)))... };  
    }(std::make_index_sequence<size_v<T>>{}); 
    else return [&]<std::size_t...I>(std::index_sequence<I...>)
    {
      using type = _::builder_make_t<T, _::repeat_t<Target,I>...>;
      return type{ static_cast<Target>(get<I>(KUMI_FWD(t)))... };
    }(std::make_index_sequence<size_v<T>>{}); 
  }

  namespace result
  {    
    template<product_type T, typename... Ts> struct type_cast 
    {
      using type = decltype( kumi::type_cast<Ts...>( std::declval<T>() ) );
    };

    template<typename Target, product_type T> struct member_cast 
    {
      using type = decltype( kumi::member_cast<Target, T>( std::declval<T>() ) );
    };

    template<product_type T, typename... Ts>
    using type_cast_t = typename type_cast<T,Ts...>::type;

    template<typename Target, product_type T>
    using member_cast_t = typename member_cast<Target,T>::type;
  }
}
