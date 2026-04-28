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
    @brief    Computes the inclusive prefix scan of all elements of a product type using a tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note The first stored value is the result of the application of the function to the provided
          initial value and the first element of the product_type.

    @param f      Binary callable function to apply
    @param t      Product type to operate on
    @param init   Optional initial value of the scan
    @return       A tuple of prefix partial accumulations where each element 'I' equals
                  `f( f( f(init, get<0>(t)), ...), get<I-1>(t))`

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Function, product_type T, typename Value> struct inclusive_scan_left;

      template<typename Function, product_type T, typename Value>
      using inclusive_scan_left_t = typename inclusive_scan_left<Function,T,Value>::type;
    }
    @endcode

    Computes the return type of a call to kumi::inclusive_scan_left

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/inclusive_scan_left.cpp
    ### Record:
    @include doc/record/algo/inclusive_scan_left.cpp
  **/
  //====================================================================================================================
  template<typename Function, kumi::concepts::product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto inclusive_scan_left(Function f, T&& t, Value init)
  {
    if constexpr (kumi::concepts::record_type<T>)
      return kumi::inclusive_scan_left(f, kumi::values_of(KUMI_FWD(t)), init);
    else if constexpr (kumi::concepts::empty_product_type<T>) return kumi::tuple{};
    else
    {
      auto op = [](auto&&... xs) { return kumi::make_tuple(KUMI_FWD(xs)...); };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (kumi::function::scannable{op, kumi::invoke(f, init, get<0>(KUMI_FWD(t)))} >> ... >>
                kumi::bind_back(f, get<I + 1>(KUMI_FWD(t))))();
      }(std::make_index_sequence<kumi::size_v<T> - 1>{});
    }
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the inclusive prefix scan of all elements of a product type using a tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note The first stored value is the result of the application of the monoid to it's identity
          and the first element of the product_type.

    @param m      Monoid callable function to apply
    @param t      Product type to operate on
    @return       A tuple of prefix partial accumulations where each element 'I' equals
                  `m( m( m(init, get<0>(t)), ...), get<I-1>(t))`

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Function, product_type T> struct inclusive_scan_left;

      template<typename Function, product_type T>
      using inclusive_scan_left_t = typename inclusive_scan_left<Function,T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::inclusive_scan_left

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/inclusive_scan_left.cpp
    ### Record:
    @include doc/record/algo/inclusive_scan_left.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::monoid M, kumi::concepts::sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto inclusive_scan_left(M&& m, T&& t)
  {
    if constexpr (kumi::concepts::record_type<T>)
      return kumi::inclusive_scan_left(KUMI_FWD(m), kumi::values_of(KUMI_FWD(t)));
    else if constexpr (kumi::concepts::sized_product_type<T, 1>) return KUMI_FWD(t);
    else return kumi::inclusive_scan_left(KUMI_FWD(m), KUMI_FWD(t), m.identity);
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the exclusive prefix scan of all elements of a product type using a tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note The first stored value is the provided initial value.

    @param f      Binary callable function to apply
    @param t      Product type to operate on
    @param init   Optional initial value of the scan
    @return       A tuple of prefix partial accumulations where each element 'I' equals
                  `f( f( f(init, get<0>(t)), ...), get<I-1>(t))`

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Function, product_type T, typename Value> struct exclusive_scan_left;

      template<typename Function, product_type T, typename Value>
      using exclusive_scan_left_t = typename exclusive_scan_left<Function,T,Value>::type;
    }
    @endcode

    Computes the return type of a call to kumi::exclusive_scan_left

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/exclusive_scan_left.cpp
    ### Record:
    @include doc/record/algo/exclusive_scan_left.cpp
  **/
  //====================================================================================================================
  template<typename Function, kumi::concepts::product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto exclusive_scan_left(Function f, T&& t, Value init)
  {
    if constexpr (kumi::concepts::record_type<T>)
      return kumi::exclusive_scan_left(f, kumi::values_of(KUMI_FWD(t)), init);
    else if constexpr (kumi::concepts::empty_product_type<T>) return kumi::tuple{init};
    else
    {
      auto op = [](auto&&... xs) { return kumi::make_tuple(KUMI_FWD(xs)...); };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (kumi::function::scannable{op, init} >> ... >> kumi::bind_back(f, get<I>(KUMI_FWD(t))))();
      }(std::make_index_sequence<kumi::size_v<T> - 1>{});
    }
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the exclusive prefix scan of all elements of a product type using a tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note The first stored value is the identity of the provided monoid.

    @param m      Monoid callable function to apply
    @param t      Product type to operate on
    @return       A tuple of prefix partial accumulations where each element 'I' equals
                  `m( m( m(init, get<0>(t)), ...), get<I-1>(t))`

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Function, product_type T> struct exclusive_scan_left;

      template<typename Function, product_type T>
      using exclusive_scan_left_t = typename exclusive_scan_left<Function,T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::exclusive_scan_left

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/exclusive_scan_left.cpp
    ### Record:
    @include doc/record/algo/exclusive_scan_left.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::monoid M, kumi::concepts::sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto exclusive_scan_left(M&& m, T&& t)
  {
    if constexpr (kumi::concepts::record_type<T>)
      return kumi::exclusive_scan_left(KUMI_FWD(m), kumi::values_of(KUMI_FWD(t)));
    else if constexpr (kumi::concepts::sized_product_type<T, 1>) return kumi::tuple(m.identity, get<0>(KUMI_FWD(t)));
    else return kumi::exclusive_scan_left(KUMI_FWD(m), KUMI_FWD(t), m.identity);
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the inclusive suffix scan of all elements of a product type using a non-tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note The first stored value is the result of the application of the function to the provided
          initial value and the last element of the product_type.

    @param f      Binary callable function to apply
    @param t      Product type to operate on
    @param init   Optional initial value of the scan
    @return       A tuple of suffix partial accumulations where each element 'I' equals
                  `f(get<0>(t), f(... , f(get<N-1>(t), init))`

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Function, product_type T, typename Value> struct inclusive_scan_right;

      template<typename Function, product_type T, typename Value>
      using inclusive_scan_right_t = typename inclusive_scan_right<Function,T,Value>::type;
    }
    @endcode

    Computes the return type of a call to kumi::inclusive_scan_right

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/inclusive_scan_right.cpp
    ### Record:
    @include doc/record/algo/inclusive_scan_right.cpp
  **/
  //====================================================================================================================
  template<typename Function, kumi::concepts::product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto inclusive_scan_right(Function f, T&& t, Value init)
  {
    if constexpr (kumi::concepts::record_type<T>)
      return kumi::inclusive_scan_right(KUMI_FWD(f), kumi::values_of(KUMI_FWD(t)), init);
    else if constexpr (kumi::concepts::empty_product_type<T>) return kumi::tuple{};
    else
    {
      auto op = [](auto&&... xs) { return kumi::make_tuple(KUMI_FWD(xs)...); };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (kumi::bind_front(f, get<I>(KUMI_FWD(t)))
                << ...
                << kumi::function::scannable{op, kumi::invoke(f, get<kumi::size_v<T> - 1>(KUMI_FWD(t)), init)})();
      }(std::make_index_sequence<kumi::size_v<T> - 1>{});
    }
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the inclusive suffix scan of all elements of a product type using a non-tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note The first stored value is the result of the application of the monoid to it's identity
          and the last element of the product_type.

    @param m      Monoid callable function to apply
    @param t      Product type to operate on
    @return       A tuple of suffix partial accumulations where each element 'I' equals
                  `m(get<0>(t), m(... , m(get<N-2>(t), get<N-1>(t)))`

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Function, product_type T> struct inclusive_scan_right;

      template<typename Function, product_type T>
      using inclusive_scan_right_t = typename inclusive_scan_right<Function,T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::inclusive_scan_right

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/inclusive_scan_right.cpp
    ### Record:
    @include doc/record/algo/inclusive_scan_right.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::monoid M, kumi::concepts::sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto inclusive_scan_right(M&& m, T&& t)
  {
    if constexpr (kumi::concepts::record_type<T>)
      return kumi::inclusive_scan_right(KUMI_FWD(m), kumi::values_of(KUMI_FWD(t)));
    else if constexpr (kumi::concepts::sized_product_type<T, 1>) return KUMI_FWD(t);
    else return kumi::inclusive_scan_right(KUMI_FWD(m), KUMI_FWD(t), m.identity);
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the exclusive suffix scan of all elements of a product type using a tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note The first stored value is the provided initial value.

    @param f      Binary callable function to apply
    @param t      Product type to operate on
    @param init   Optional initial value of the scan
    @return       A tuple of suffix partial accumulations where each element 'I' equals
                  `f( f( f(init, get<0>(t)), ...), get<I-1>(t))`

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Function, product_type T, typename Value> struct exclusive_scan_right;

      template<typename Function, product_type T, typename Value>
      using exclusive_scan_right_t = typename exclusive_scan_right<Function,T,Value>::type;
    }
    @endcode

    Computes the return type of a call to kumi::exclusive_scan_right

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/exclusive_scan_right.cpp
    ### Record:
    @include doc/record/algo/exclusive_scan_right.cpp
  **/
  //====================================================================================================================
  template<typename Function, kumi::concepts::product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto exclusive_scan_right(Function f, T&& t, Value init)
  {
    if constexpr (kumi::concepts::record_type<T>)
      return kumi::exclusive_scan_right(KUMI_FWD(f), kumi::values_of(KUMI_FWD(t)), init);
    else if constexpr (kumi::concepts::empty_product_type<T>) return kumi::tuple{init};
    else
    {
      auto op = [](auto&&... xs) { return kumi::make_tuple(KUMI_FWD(xs)...); };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (kumi::bind_front(f, get<I + 1>(KUMI_FWD(t))) << ... << kumi::function::scannable{op, init})();
      }(std::make_index_sequence<kumi::size_v<T> - 1>{});
    }
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the exclusive suffix scan of all elements of a product type using a non-tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note The first stored value is the identity of the provided monoid.

    @param m      Monoid callable function to apply
    @param t      Product type to operate on
    @return       A tuple of prefix partial accumulations where each element 'I' equals
                  `m( m( m(init, get<0>(t)), ...), get<I-1>(t))`

    ## Helper type
    @code
    namespace kumi::result
    {
      template<typename Function, product_type T> struct exclusive_scan_right;

      template<typename Function, product_type T>
      using exclusive_scan_right_t = typename exclusive_scan_right<Function,T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::exclusive_scan_right

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/exclusive_scan_right.cpp
    ### Record:
    @include doc/record/algo/exclusive_scan_right.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::monoid M, kumi::concepts::sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto exclusive_scan_right(M&& m, T&& t)
  {
    if constexpr (kumi::concepts::record_type<T>)
      return kumi::exclusive_scan_right(KUMI_FWD(m), kumi::values_of(KUMI_FWD(t)));
    else if constexpr (kumi::concepts::sized_product_type<T, 1>) return kumi::tuple{get<0>(KUMI_FWD(t)), m.identity};
    else return kumi::exclusive_scan_right(KUMI_FWD(m), KUMI_FWD(t), m.identity);
  }

  namespace result
  {
    template<typename Function, kumi::concepts::product_type T, typename Value = void> struct inclusive_scan_right
    {
      using type =
        decltype(kumi::inclusive_scan_right(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };

    template<typename Function, kumi::concepts::product_type T> struct inclusive_scan_right<Function, T>
    {
      using type = decltype(kumi::inclusive_scan_right(std::declval<Function>(), std::declval<T>()));
    };

    template<typename Function, kumi::concepts::product_type T, typename Value = void> struct exclusive_scan_right
    {
      using type =
        decltype(kumi::exclusive_scan_right(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };

    template<typename Function, kumi::concepts::product_type T> struct exclusive_scan_right<Function, T>
    {
      using type = decltype(kumi::exclusive_scan_right(std::declval<Function>(), std::declval<T>()));
    };

    template<typename Function, kumi::concepts::product_type T, typename Value = void> struct inclusive_scan_left
    {
      using type =
        decltype(kumi::inclusive_scan_left(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };

    template<typename Function, kumi::concepts::product_type T> struct inclusive_scan_left<Function, T>
    {
      using type = decltype(kumi::inclusive_scan_left(std::declval<Function>(), std::declval<T>()));
    };

    template<typename Function, kumi::concepts::product_type T, typename Value = void> struct exclusive_scan_left
    {
      using type =
        decltype(kumi::exclusive_scan_left(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };

    template<typename Function, kumi::concepts::product_type T> struct exclusive_scan_left<Function, T>
    {
      using type = decltype(kumi::exclusive_scan_left(std::declval<Function>(), std::declval<T>()));
    };

    template<typename Function, kumi::concepts::product_type T, typename Value = void>
    using inclusive_scan_right_t = typename kumi::result::inclusive_scan_right<Function, T, Value>::type;

    template<typename Function, kumi::concepts::product_type T, typename Value = void>
    using exclusive_scan_right_t = typename kumi::result::exclusive_scan_right<Function, T, Value>::type;

    template<typename Function, kumi::concepts::product_type T, typename Value = void>
    using inclusive_scan_left_t = typename kumi::result::inclusive_scan_left<Function, T, Value>::type;

    template<typename Function, kumi::concepts::product_type T, typename Value = void>
    using exclusive_scan_left_t = typename kumi::result::exclusive_scan_left<Function, T, Value>::type;
  }
}
