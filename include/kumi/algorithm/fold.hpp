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
    @ingroup  reductions
    @brief    Computes the generalized combination of all elements using a tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @param f      Binary callable function to apply
    @param t      Product type to operate on
    @param init   Optional initial value of the fold
    @return       The value of `f( f( f(init, get<0>(t)), ...), get<N-1>(t))`

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Function, product_type T, typename Value> struct fold_left;

      template<typename Function, product_type T, typename Value>
      using fold_left_t = typename fold_left<Function,T,Value>::type;
    }
    @endcode

    Computes the return type of a call to kumi::fold_left

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/fold_left.cpp
    ### Record:
    @include doc/record/algo/fold_left.cpp
  **/
  //====================================================================================================================
  template<typename Function, kumi::concepts::product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto fold_left(Function f, T&& t, Value init)
  {
    if constexpr (kumi::concepts::record_type<T>) return kumi::fold_left(f, kumi::values_of(KUMI_FWD(t)), init);
    else if constexpr (kumi::concepts::empty_product_type<T>) return init;
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (kumi::function::foldable{init} >> ... >> kumi::bind_back(f, get<I>(KUMI_FWD(t))))();
      }(std::make_index_sequence<kumi::size_v<T>>());
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the generalized associative combination of all elements using a tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @param f  Associative binary callable function to apply
    @param t  Product type of size 1 or more to operate on
    @return   The value of `f( f( f(get<0>(t), get<1>(t)), ...), get<N-1>(t))`

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Function, product_type T> struct fold_left;

      template<typename Function, product_type T>
      using fold_left_t = typename fold_left<Function,T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::fold_left

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/fold_left.cpp
    ### Record:
    @include doc/record/algo/fold_left.cpp
  **/
  //====================================================================================================================
  template<typename Function, kumi::concepts::non_empty_product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto fold_left(Function f, T&& t)
  {
    if constexpr (kumi::concepts::record_type<T>) return fold_left(f, kumi::values_of(KUMI_FWD(t)));
    else if constexpr (kumi::concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (kumi::function::foldable{get<0>(KUMI_FWD(t))} >> ... >> kumi::bind_back(f, get<I + 1>(KUMI_FWD(t))))();
      }(std::make_index_sequence<kumi::size_v<T> - 1>{});
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the generalized combination of all elements using a non-tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @param f      Binary callable function to apply
    @param t      Product type to operate on
    @param init   Optional initial value of the fold
    @return       The value of `f(get<0>(t), f(... , f(get<N-1>(t), init))`

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Function, product_type T, typename Value> struct fold_right;

      template<typename Function, product_type T, typename Value>
      using fold_right_t = typename fold_right<Function,T,Value>::type;
    }
    @endcode

    Computes the return type of a call to kumi::fold_right

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/fold_right.cpp
    ### Record:
    @include doc/record/algo/fold_right.cpp
  **/
  //====================================================================================================================
  template<typename Function, kumi::concepts::product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto fold_right(Function f, T&& t, Value init)
  {
    if constexpr (kumi::concepts::record_type<T>) return kumi::fold_right(f, kumi::values_of(KUMI_FWD(t)), init);
    else if constexpr (kumi::concepts::empty_product_type<T>) return init;
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (kumi::bind_front(f, get<I>(KUMI_FWD(t))) << ... << kumi::function::foldable{init})();
      }(std::make_index_sequence<kumi::size_v<T>>());
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the generalized associative combinationof all elements using a non-tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @param f  Associative binary callable function to apply
    @param t  Product type of size 1 or more to operate on
    @return   The value of `f(get<0>(t), f(... , f(get<N-2>(t), get<N-1>(t)))`

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Function, product_type T> struct fold_right;

      template<typename Function, product_type T>
      using fold_right_t = typename fold_right<Function,T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::fold_right

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/fold_right.cpp
    ### Record:
    @include doc/record/algo/fold_right.cpp
  **/
  //====================================================================================================================
  template<typename Function, kumi::concepts::non_empty_product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto fold_right(Function f, T&& t)
  {
    if constexpr (kumi::concepts::record_type<T>) return kumi::fold_right(f, kumi::values_of(KUMI_FWD(t)));
    else if constexpr (kumi::concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (kumi::bind_front(f, get<I + 1>(KUMI_FWD(t))) << ... << kumi::function::foldable{get<0>(KUMI_FWD(t))})();
      }(std::make_index_sequence<kumi::size_v<T> - 1>());
  }

  namespace result
  {
    template<typename Function, kumi::concepts::product_type T, typename Value = void> struct fold_right
    {
      using type = decltype(kumi::fold_right(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };

    template<typename Function, kumi::concepts::product_type T> struct fold_right<Function, T>
    {
      using type = decltype(kumi::fold_right(std::declval<Function>(), std::declval<T>()));
    };

    template<typename Function, kumi::concepts::product_type T, typename Value = void> struct fold_left
    {
      using type = decltype(kumi::fold_left(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };

    template<typename Function, kumi::concepts::product_type T> struct fold_left<Function, T>
    {
      using type = decltype(kumi::fold_left(std::declval<Function>(), std::declval<T>()));
    };

    template<typename Function, kumi::concepts::product_type T, typename Value = void>
    using fold_right_t = typename kumi::result::fold_right<Function, T, Value>::type;

    template<typename Function, kumi::concepts::product_type T, typename Value = void>
    using fold_left_t = typename kumi::result::fold_left<Function, T, Value>::type;
  }
}
