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
  //! @brief Apply the Callable object f on each tuples' elements
  //!
  //! Applies the given function to all the tuples passed as arguments and stores the result in
  //! another tuple, keeping the original elements order.
  //!
  //! @note Does not participate in overload resolution if tuples' size are not equal or if `f`
  //!       can't be called on each tuple's elements.
  //!
  //! @param f      Callable function to apply
  //! @param t0     Tuple  to operate on
  //! @param others Tuples to operate on
  //! @return The tuple of `f` calls results.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type T, product_type... Ts> struct map;
  //!
  //!   template<typename Function, product_type T, product_type... Ts>
  //!   using map_t = typename map<Function,Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::map
  //!
  //! ## Example
  //! @include doc/map.cpp
  //================================================================================================
  template<product_type Tuple, typename Function, sized_product_type<size_v<Tuple>>... Tuples>
  [[nodiscard]] KUMI_ABI constexpr auto map(Function f, Tuple  &&t0, Tuples &&...others) 
  requires ( compatible_product_types<Tuple, Tuples...> && 
           _::supports_call<Function, Tuple&&, Tuples&&...> )
  {
    if constexpr(sized_product_type<Tuple,0>) return _::builder<Tuple>::make();
    else
    {
      auto const call = [&]<std::size_t N, typename... Ts>(index_t<N>, Ts &&... args)
      {
        return f(get<N>(KUMI_FWD(args))...);
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return _::builder<Tuple>::make(call(index<I>, KUMI_FWD(t0), KUMI_FWD(others)...)...);
      }(std::make_index_sequence<size_v<Tuple>>());
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
  //! @param t0     Tuple  to operate on
  //! @param others Tuples to operate on
  //! @return The tuple of `f` calls results.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type T, product_type... Ts> struct map_index;
  //!
  //!   template<typename Function, product_type T, product_type... Ts>
  //!   using map_index_t = typename map_index<Function,Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::map_index
  //!
  //! ## Example
  //! @include doc/map_index.cpp
  //================================================================================================
  template<product_type Tuple, typename Function, sized_product_type<size_v<Tuple>>... Tuples>
  [[nodiscard]] KUMI_ABI constexpr auto map_index(Function f, Tuple &&t0,Tuples &&...others)
  requires(!record_type<Tuple> && (!record_type<Tuples> && ...))
  {
    if constexpr(sized_product_type<Tuple,0>) return _::builder<Tuple>::make();
    else
    {
      auto const call = [&]<std::size_t N, typename... Ts>(index_t<N> idx, Ts &&... args)
      {
        return f(idx, get<N>(KUMI_FWD(args))...);
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return _::builder<Tuple>::make(call(index<I>, KUMI_FWD(t0), KUMI_FWD(others)...)...);
      }(std::make_index_sequence<size_v<Tuple>>());
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
