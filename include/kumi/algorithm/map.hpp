//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/detail/builder.hpp>

namespace kumi
{
  //================================================================================================
  //! @ingroup transforms
  //! @brief Apply the Callable object f on each product types' elements
  //!
  //! Applies the given function to all the product types passed as arguments and stores the result in
  //! another product type, keeping the original elements order.
  //!
  //! @note Does not participate in overload resolution if product types' size are not equal or if `f`
  //!       can't be called on each product type's elements.
  //!
  //! @param f      Callable function to apply
  //! @param t0     Product Type  to operate on
  //! @param others Product Type to operate on
  //! @return The product type of `f` calls results.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type T, product_type... Ts> struct map;
  //!
  //!   template<typename Function, product_type T, product_type... Ts>
  //!   using map_t = typename map<Function,T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::map
  //!
  //! ## Example
  //! @include doc/map.cpp
  //================================================================================================
  template<product_type T, typename Function, sized_product_type<size_v<T>>... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto map(Function f, T  &&t0, Ts &&...others) 
  requires ( compatible_product_types<T, Ts...> && 
           _::supports_call<Function, T&&, Ts&&...> )
  {
    if constexpr(sized_product_type<T,0>) return _::builder<T>::make();
    else
    {
      auto const call = [&]<std::size_t N, typename... Us>(index_t<N>, Us &&... args)
      {
        return f(get<N>(KUMI_FWD(args))...);
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return _::builder<T>::make(call(index<I>, KUMI_FWD(t0), KUMI_FWD(others)...)...);
      }(std::make_index_sequence<size_v<T>>());
    }
  }

  namespace result
  {
    template<typename Function, product_type T, sized_product_type<size<T>::value>... Ts>
    struct map
    {
      using type = decltype ( kumi::map ( std::declval<Function>()
                                        , std::declval<T>()
                                        , std::declval<Ts>()...
                                        )
                            );
    };

    template<typename Function, product_type T, sized_product_type<size<T>::value>... Ts>
    using map_t = typename map<Function,T,Ts...>::type;
  }

  //================================================================================================
  //! @ingroup transforms
  //! @brief Apply the Callable object f on each tuples' elements and their indexes
  //!
  //! Applies the given function to all the tuples passed as arguments along with their indexes  and
  //! stores the result in another tuple, keeping the original elements order.
  //!
  //! @note Does not participate in overload resolution if tuples' size are not equal or if `f`
  //!       can't be called on each tuple's elements and their indexes.
  //!
  //! @param f      Callable function to apply
  //! @param t0     T  to operate on
  //! @param others Ts to operate on
  //! @return The tuple of `f` calls results.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type T, product_type... Ts> struct map_index;
  //!
  //!   template<typename Function, product_type T, product_type... Ts>
  //!   using map_index_t = typename map_index<Function,T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::map_index
  //!
  //! ## Example
  //! @include doc/map_index.cpp
  //================================================================================================
  template<product_type T, typename Function, sized_product_type<size_v<T>>... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto map_index(Function f, T &&t0,Ts &&...others)
  requires(!record_type<T> && (!record_type<Ts> && ...))
  {
    if constexpr(sized_product_type<T,0>) return _::builder<T>::make();
    else
    {
      auto const call = [&]<std::size_t N, typename... Us>(index_t<N> idx, Us &&... args)
      {
        return f(idx, get<N>(KUMI_FWD(args))...);
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return _::builder<T>::make(call(index<I>, KUMI_FWD(t0), KUMI_FWD(others)...)...);
      }(std::make_index_sequence<size_v<T>>());
    }
  }

  namespace result
  {
    template<typename Function, product_type T, sized_product_type<size<T>::value>... Ts>
    struct map_index
    {
      using type = decltype ( kumi::map_index ( std::declval<Function>()
                                              , std::declval<T>()
                                              , std::declval<Ts>()...
                                              )
                            );
    };

    template<typename Function, product_type T, sized_product_type<size<T>::value>... Ts>
    using map_index_t = typename map_index<Function,T,Ts...>::type;
  }
}
