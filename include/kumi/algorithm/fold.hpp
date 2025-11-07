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
  //! @ingroup reductions
  //! @brief Computes the generalized sum of all elements using a tail recursive call.
  //!
  //! @param f      Binary callable function to apply
  //! @param t      Product type to operate on
  //! @param init   Initial value of the sum
  //! @return   The value of `f( f( f(init, get<0>(t)), ...), get<N-1>(t))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type T, typename Value> struct fold_left;
  //!
  //!   template<typename Function, product_type T, typename Value>
  //!   using fold_left_t = typename fold_left_t<Function,T,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::fold_left
  //!
  //! ## Examples:
  //! @include doc/fold_left.cpp
  //! @include doc/record/fold_left.cpp
  //================================================================================================
  template<typename Function, product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto fold_left(Function f, T && t, Value init)
  {
    if constexpr ( record_type<T> ) return fold_left(f, values_of(KUMI_FWD(t)), init);
    else if constexpr(sized_product_type<T,0>) return init;
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return (_::foldable {f, init} >> ... >> _::foldable {f, get<I>(KUMI_FWD(t))} ).value;
      }
      (std::make_index_sequence<size_v<T>>());
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the generalized associative sum of all elements using a tail recursive call.
  //!
  //! @param f      Associative binary callable function to apply
  //! @param t      Product type of size 1 or more to operate on
  //! @return   The value of `f( f( f(get<0>(t), get<1>(t)), ...), get<N-1>(t))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type T> struct fold_left;
  //!
  //!   template<typename Function, product_type T>
  //!   using fold_left_t = typename fold_left_t<Function,T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::fold_left
  //!
  //! ## Examples:
  //! @include doc/fold_left.cpp
  //! @include doc/record/fold_left.cpp
  //================================================================================================
  template<typename Function, sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto fold_left(Function f, T&& t)
  {
    if constexpr ( record_type<T> ) return fold_left(f, values_of(KUMI_FWD(t)));
    else if constexpr(sized_product_type<T,1>) return get<0>(KUMI_FWD(t));
    else
    {
      auto&&[heads, tail] = split(KUMI_FWD(t), index<2>);
      return fold_left(f, tail, kumi::apply(f,heads));
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the generalized sum of all elements using a non-tail recursive call.
  //!
  //! @param f      Binary callable function to apply
  //! @param t      Product type to operate on
  //! @param init   Initial value of the sum
  //! @return   The value of `f(get<0>(t), f(... , f(get<N-1>(t), init))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type T, typename Value> struct fold_right;
  //!
  //!   template<typename Function, product_type T, typename Value>
  //!   using fold_right_t = typename fold_right_t<Function,T,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::fold_right
  //!
  //! ## Examples:
  //! @include doc/fold_right.cpp
  //! @include doc/record/fold_right.cpp
  //================================================================================================
  template<typename Function, product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto fold_right(Function f, T&& t, Value init)
  {
    if constexpr ( record_type<T> ) return fold_right(f, values_of(KUMI_FWD(t)), init);
    else if constexpr( sized_product_type<T,0> ) return init;
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return (_::foldable {f, get<I>(KUMI_FWD(t))} << ... << _::foldable {f, init}).value;
      }
      (std::make_index_sequence<size_v<T>>());
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the generalized associative sum of all elements using a non-tail recursive call.
  //!
  //! @param f      Associative binary callable function to apply
  //! @param t      Product type of size 1 or more to operate on
  //! @return   The value of `f(get<0>(t), f(... , f(get<N-2>(t), get<N-1>(t)))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type T> struct fold_right;
  //!
  //!   template<typename Function, product_type T>
  //!   using fold_right_t = typename fold_right_t<Function,T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::fold_right
  //!
  //! ## Examples:
  //! @include doc/fold_right.cpp
  //! @include doc/record/fold_right.cpp
  //================================================================================================
  template<typename Function, sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto fold_right(Function f, T&& t)
  {
    if constexpr ( record_type<T> ) return fold_right(f, values_of(KUMI_FWD(t)));
    else if constexpr(sized_product_type<T,1>) return get<0>(KUMI_FWD(t));
    else
    {
      auto&&[head, tails] = split(KUMI_FWD(t), index<size_v<T>-2>);
      return fold_right(f, head, kumi::apply(f,tails));
    }
  }

  namespace result
  {
    template<typename Function, product_type T, typename Value = void>
    struct fold_right
    {
      using type = decltype ( kumi::fold_right( std::declval<Function>()
                                              , std::declval<T>()
                                              , std::declval<Value>()
                                              )
                            );
    };

    template<typename Function, product_type T>
    struct fold_right<Function,T>
    {
      using type = decltype ( kumi::fold_right( std::declval<Function>()
                                              , std::declval<T>()
                                              )
                            );
    };

    template<typename Function, product_type T, typename Value = void>
    struct fold_left
    {
      using type = decltype ( kumi::fold_left ( std::declval<Function>()
                                              , std::declval<T>()
                                              , std::declval<Value>()
                                              )
                            );
    };

    template<typename Function, product_type T>
    struct fold_left<Function,T>
    {
      using type = decltype ( kumi::fold_left ( std::declval<Function>()
                                              , std::declval<T>()
                                              )
                            );
    };

    template<typename Function, product_type T, typename Value = void>
    using fold_right_t = typename fold_right<Function,T,Value>::type;

    template<typename Function, product_type T, typename Value = void>
    using fold_left_t = typename fold_left<Function,T,Value>::type;
  }
}

