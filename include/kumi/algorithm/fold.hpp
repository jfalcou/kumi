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
  //! @param t      Tuple to operate on
  //! @param init   Initial value of the sum
  //! @return   The value of `f( f( f(init, get<0>(t)), ...), get<N-1>(t))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple, typename Value> struct fold_left;
  //!
  //!   template<typename Function, product_type Tuple, typename Value>
  //!   using fold_left_t = typename fold_left_t<Function,Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::fold_left
  //!
  //! ## Example
  //! @include doc/fold_left.cpp
  //================================================================================================
  template<typename Function, product_type Tuple, typename Value>
  [[nodiscard]] constexpr auto fold_left(Function f, Tuple&& t, Value init)
  {
    if constexpr(sized_product_type<Tuple,0>) return init;
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return (_::foldable {f, get<I>(KUMI_FWD(t))} >> ... >> _::foldable {f, init}).value;
      }
      (std::make_index_sequence<size<Tuple>::value>());
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the generalized associative sum of all elements using a tail recursive call.
  //!
  //! @param f      Associative binary callable function to apply
  //! @param t      Tuple of size 1 or more to operate on
  //! @return   The value of `f( f( f(get<0>(t), get<1>(t)), ...), get<N-1>(t))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple> struct fold_left;
  //!
  //!   template<typename Function, product_type Tuple>
  //!   using fold_left_t = typename fold_left_t<Function,Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::fold_left
  //!
  //! ## Example
  //! @include doc/fold_left.cpp
  //================================================================================================
  template<typename Function, sized_product_type_or_more<1> Tuple>
  [[nodiscard]] constexpr auto fold_left(Function f, Tuple&& t)
  {
    if constexpr(sized_product_type<Tuple,1>) return get<0>(t);
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
  //! @param t      Tuple to operate on
  //! @param init   Initial value of the sum
  //! @return   The value of `f(get<0>(t), f(... , f(get<N-1>(t), init))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple, typename Value> struct fold_right;
  //!
  //!   template<typename Function, product_type Tuple, typename Value>
  //!   using fold_right_t = typename fold_right_t<Function,Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::fold_right
  //!
  //! ## Example
  //! @include doc/fold_right.cpp
  //================================================================================================
  template<typename Function, product_type Tuple, typename Value>
  [[nodiscard]] constexpr auto fold_right(Function f, Tuple&& t, Value init)
  {
    if constexpr(size<Tuple>::value ==0) return init;
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return (_::foldable {f, init} << ... << _::foldable {f, get<I>(KUMI_FWD(t))}).value;
      }
      (std::make_index_sequence<size<Tuple>::value>());
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the generalized associative sum of all elements using a non-tail recursive call.
  //!
  //! @param f      Associative binary callable function to apply
  //! @param t      Tuple of size 1 or more to operate on
  //! @return   The value of `f(get<0>(t), f(... , f(get<N-2>(t), get<N-1>(t)))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple> struct fold_right;
  //!
  //!   template<typename Function, product_type Tuple>
  //!   using fold_right_t = typename fold_right_t<Function,Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::fold_right
  //!
  //! ## Example
  //! @include doc/fold_right.cpp
  //================================================================================================
  template<typename Function, sized_product_type_or_more<1> Tuple>
  [[nodiscard]] constexpr auto fold_right(Function f, Tuple&& t)
  {
    if constexpr(sized_product_type<Tuple,1>) return get<0>(t);
    else
    {
      auto&&[head, tails] = split(KUMI_FWD(t), index<size_v<Tuple>-2>);
      return fold_left(f, head, kumi::apply(f,tails));
    }
  }

  namespace result
  {
    template<typename Function, product_type Tuple, typename Value = void>
    struct fold_right
    {
      using type = decltype ( kumi::fold_right( std::declval<Function>()
                                              , std::declval<Tuple>()
                                              , std::declval<Value>()
                                              )
                            );
    };

    template<typename Function, product_type Tuple>
    struct fold_right<Function,Tuple>
    {
      using type = decltype ( kumi::fold_right( std::declval<Function>()
                                              , std::declval<Tuple>()
                                              )
                            );
    };

    template<typename Function, product_type Tuple, typename Value = void>
    struct fold_left
    {
      using type = decltype ( kumi::fold_left ( std::declval<Function>()
                                              , std::declval<Tuple>()
                                              , std::declval<Value>()
                                              )
                            );
    };

    template<typename Function, product_type Tuple>
    struct fold_left<Function,Tuple>
    {
      using type = decltype ( kumi::fold_left ( std::declval<Function>()
                                              , std::declval<Tuple>()
                                              )
                            );
    };

    template<typename Function, product_type Tuple, typename Value = void>
    using fold_right_t = typename fold_right<Function,Tuple,Value>::type;

    template<typename Function, product_type Tuple, typename Value = void>
    using fold_left_t = typename fold_left<Function,Tuple,Value>::type;
  }
}

