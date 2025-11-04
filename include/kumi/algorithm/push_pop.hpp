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
  //! @ingroup generators
  //! @brief Constructs a tuple by adding a value v at the beginning of t
  //!
  //! @param t Base tuple
  //! @param v Value to insert in front of t
  //! @return A tuple composed of v followed by all elements of t in order.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple, typename T> struct push_front;
  //!
  //!   template<product_type Tuple, typename T>
  //!   using push_front_t = typename push_front<Tuples...>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::push_front
  //!
  //! ## Examples:
  //! @include doc/push_front.cpp
  //! @include doc/record/push_front.cpp
  //================================================================================================
  template<product_type Tuple, typename T>
  [[nodiscard]] KUMI_ABI constexpr auto push_front(Tuple && t, T && v)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>)
    {
      return _::builder<Tuple>::make( KUMI_FWD(v), get<I>(KUMI_FWD(t))...);
    }
    (std::make_index_sequence<size_v<Tuple>>());
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Remove the first (if any) element of a kumi::product_type.
  //!
  //! @param t Base tuple
  //! @return A tuple composed of all elements of t except its first. Has no effect on empty t.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct pop_front;
  //!
  //!   template<product_type Tuple>
  //!   using pop_front_t = typename pop_front<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::pop_front
  //!
  //! ## Example
  //! @include doc/pop_front.cpp
  //================================================================================================
  template<product_type Tuple>
  [[nodiscard]] KUMI_ABI constexpr auto pop_front(Tuple && t)
  {
    if constexpr(sized_product_type_or_more<Tuple,1>) return extract(KUMI_FWD(t), index<1>);
    else                                              return _::builder<Tuple>::make();
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Constructs a tuple by adding a value v at the end of t
  //!
  //! @param t Base tuple
  //! @param v Value to insert in front of t
  //! @return A tuple composed of all elements of t in order followed by v.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple, typename T> struct push_back;
  //!
  //!   template<product_type Tuple, typename T>
  //!   using push_back_t = typename push_back<Tuple,T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::push_back
  //!
  //! ## Examples:
  //! @include doc/push_back.cpp
  //! @include doc/record/push_back.cpp
  //================================================================================================
  template<product_type Tuple, typename T>
  [[nodiscard]] KUMI_ABI constexpr auto push_back(Tuple && t, T&& v)
  {
    return [&]<std::size_t... I>(std::index_sequence<I...>)
    {
      return _::builder<Tuple>::make(get<I>(KUMI_FWD(t))..., KUMI_FWD(v));
    }
    (std::make_index_sequence<size_v<Tuple>>());
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Remove the last (if any) element of a kumi::product_type.
  //!
  //! @param t Base tuple
  //! @return A tuple composed of all elements of t except its last. Has no effect on empty t.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct pop_back;
  //!
  //!   template<product_type Tuple>
  //!   using pop_back_t = typename pop_back<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::pop_back
  //!
  //! ## Example
  //! @include doc/pop_back.cpp
  //================================================================================================
  template<product_type Tuple>
  [[nodiscard]] KUMI_ABI constexpr auto pop_back(Tuple && t)
  {
    if constexpr(sized_product_type_or_more<Tuple,1>) return extract(KUMI_FWD(t), index<0>, index<size_v<Tuple>-1>);
    else                                              return _::builder<Tuple>::make();
  }

  namespace result
  {
    template<product_type Tuple, typename T> struct push_front
    {
      using type = decltype( kumi::push_front( std::declval<Tuple>(), std::declval<T>() ) );
    };

    template<product_type Tuple> struct pop_front
    {
      using type = decltype( kumi::pop_front( std::declval<Tuple>() ) );
    };

    template<product_type Tuple, typename T> struct push_back
    {
      using type = decltype( kumi::push_back( std::declval<Tuple>(), std::declval<T>() ) );
    };

    template<product_type Tuple> struct pop_back
    {
      using type = decltype( kumi::pop_back( std::declval<Tuple>() ) );
    };

    template<product_type Tuple, typename T>
    using push_front_t  = typename push_front<Tuple, T>::type;

    template<product_type Tuple>
    using pop_front_t  = typename pop_front<Tuple>::type;

    template<product_type Tuple, typename T>
    using push_back_t  = typename push_back<Tuple, T>::type;

    template<product_type Tuple>
    using pop_back_t  = typename pop_back<Tuple>::type;
  }
}
