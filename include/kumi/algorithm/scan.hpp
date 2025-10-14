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
    //==============================================================================================
    // Scan helpers
    //==============================================================================================
    template<typename F, typename T> struct scannable 
    {
      F func;
      T acc;

      template<typename W>
      KUMI_ABI friend constexpr decltype(auto) operator>>(scannable &&x, scannable<F, W> &&y)
      {
        constexpr auto size = kumi::size_v<T>-1;
        return _::scannable{x.func, kumi::push_back(x.acc, x.func(kumi::get<size>(x.acc), y.acc))};
      }

      template<typename W>
      KUMI_ABI friend constexpr decltype(auto) operator<<(scannable &&x, scannable<F, W> &&y)
      {
        return _::scannable {x.func, kumi::push_front(x.acc, x.func(y.acc, kumi::get<0>(x.acc)))};
      }
    };

    template<class F, class T> scannable(const F &, T &&) -> scannable<F, T>;
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the inclusive prefix scan of all elements of a product type using a 
  //!        tail recursive call.
  //!
  //! @note The first stored value is the result of the application of the function to the provided 
  //!       initial value and the first element of the product_type.
  //!
  //! @param f      Binary callable function to apply
  //! @param t      Tuple to operate on
  //! @param init   Initial value of the sum
  //! @return       A tuple of prefix partial accumulations where each element 'I' equals 
  //!               `f( f( f(init, get<0>(t)), ...), get<I-1>(t))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple, typename Value> struct inclusive_scan_left;
  //!
  //!   template<typename Function, product_type Tuple, typename Value>
  //!   using inclusive_scan_left_t = typename inclusive_scan_left_t<Function,Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::inclusive_scan_left
  //!
  //! ## Example
  //! @include doc/inclusive_scan_left.cpp
  //================================================================================================
  template<typename Function, product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto inclusive_scan_left(Function && f, T && t, Value init)
  {
    if constexpr ( record_type<T> ) return inclusive_scan_left(KUMI_FWD(f), KUMI_FWD(t).values, init);
    else if constexpr(sized_product_type<T,0>) return kumi::tuple{};
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return  (_::scannable{f, kumi::tuple{f(init, get<0>(KUMI_FWD(t)))}} 
                  >> ... 
                  >> _::scannable{f, get<I+1>(KUMI_FWD(t))}
                ).acc;
      }
      (std::make_index_sequence<size_v<T>-1>());
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the inclusive prefix scan of all elements of a product type using a 
  //!        tail recursive call.
  //!
  //! @note The first stored value is the result of the application of the monoid to it's identity 
  //!       and the first element of the product_type.
  //!
  //! @param m      Monoid callable function to apply
  //! @param t      Tuple to operate on
  //! @return       A tuple of prefix partial accumulations where each element 'I' equals 
  //!               `m( m( m(init, get<0>(t)), ...), get<I-1>(t))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple> struct inclusive_scan_left;
  //!
  //!   template<typename Function, product_type Tuple>
  //!   using inclusive_scan_left_t = typename inclusive_scan_left_t<Function,Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::inclusive_scan_left
  //!
  //! ## Example
  //! @include doc/inclusive_scan_left.cpp
  //================================================================================================
  template<monoid M, sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto inclusive_scan_left(M && m, T && t)
  {
    if constexpr ( record_type<T> ) return inclusive_scan_left(KUMI_FWD(m), KUMI_FWD(t).values);
    else if constexpr(sized_product_type<T,1>) return KUMI_FWD(t);
    else
    {
      return inclusive_scan_left(m, KUMI_FWD(t), m.identity);
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the exclusive prefix scan of all elements of a product type using a 
  //!        tail recursive call.
  //!
  //! @note The first stored value is the provided initial value.  
  //!
  //! @param f      Binary callable function to apply
  //! @param t      Tuple to operate on
  //! @param init   Initial value of the sum
  //! @return       A tuple of prefix partial accumulations where each element 'I' equals 
  //!               `f( f( f(init, get<0>(t)), ...), get<I-1>(t))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple, typename Value> struct exclusive_scan_left;
  //!
  //!   template<typename Function, product_type Tuple, typename Value>
  //!   using exclusive_scan_left_t = typename exclusive_scan_left_t<Function,Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::exclusive_scan_left
  //!
  //! ## Example
  //! @include doc/exclusive_scan_left.cpp
  //================================================================================================
  template<typename Function, product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto exclusive_scan_left(Function && f, T && t, Value init)
  {
    if constexpr ( record_type<T> ) return exclusive_scan_left(KUMI_FWD(f), KUMI_FWD(t).values, init);
    else if constexpr(sized_product_type<T,0>) return kumi::tuple{init};
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return  (_::scannable{f, kumi::tuple{init}} 
                  >> ... 
                  >> _::scannable{f, get<I>(KUMI_FWD(t))}
                ).acc;
      }
      (std::make_index_sequence<size_v<T>-1>());
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the exclusive prefix scan of all elements of a product type using a 
  //!        tail recursive call.
  //!
  //! @note The first stored value is the identity of the provided monoid.
  //!
  //! @param m      Monoid callable function to apply
  //! @param t      Tuple to operate on
  //! @return       A tuple of prefix partial accumulations where each element 'I' equals 
  //!               `m( m( m(init, get<0>(t)), ...), get<I-1>(t))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple> struct exclusive_scan_left;
  //!
  //!   template<typename Function, product_type Tuple>
  //!   using exclusive_scan_left_t = typename exclusive_scan_left_t<Function,Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::exclusive_scan_left
  //!
  //! ## Example
  //! @include doc/exclusive_scan_left.cpp
  //================================================================================================
  template<monoid M, sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto exclusive_scan_left(M && m, T && t)
  {
    if constexpr ( record_type<T> ) return exclusive_scan_left(KUMI_FWD(m), KUMI_FWD(t).values);
    else if constexpr(sized_product_type<T,1>) return kumi::tuple(m.identity, get<0>(KUMI_FWD(t)));
    else
    {
      return exclusive_scan_left(m, KUMI_FWD(t), m.identity);
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the inclusive suffix scan of all elements of a product type using a 
  //!        non-tail recursive call.
  //!
  //! @note The first stored value is the result of the application of the function to the provided 
  //!       initial value and the last element of the product_type.
  //!
  //! @param f      Binary callable function to apply
  //! @param t      Tuple to operate on
  //! @param init   Initial value of the sum
  //! @return       A tuple of suffix partial accumulations where each element 'I' equals 
  //!               `f(get<0>(t), f(... , f(get<N-1>(t), init))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple, typename Value> struct inclusive_scan_right;
  //!
  //!   template<typename Function, product_type Tuple, typename Value>
  //!   using inclusive_scan_right_t = typename inclusive_scan_right_t<Function,Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::inclusive_scan_right
  //!
  //! ## Example
  //! @include doc/inclusive_scan_right.cpp
  //================================================================================================
  template<typename Function, product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto inclusive_scan_right(Function && f, T && t, Value init)
  {
    if constexpr ( record_type<T> ) return inclusive_scan_right(KUMI_FWD(f), KUMI_FWD(t).values, init);
    else if constexpr( sized_product_type<T,0> ) return kumi::tuple{};
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return  (_::scannable{f, kumi::tuple{f(get<size_v<T>-1>(KUMI_FWD(t)),init)}} 
                  << ... 
                  << _::scannable{ f, get<size_v<T>-2-I>(KUMI_FWD(t)) }
                ).acc;
      }
      (std::make_index_sequence<size_v<T>-1>());
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the inclusive suffix scan of all elements of a product type using a 
  //!        non-tail recursive call.
  //!
  //! @note The first stored value is the result of the application of the monoid to it's identity 
  //!       and the last element of the product_type.
  //!
  //! @param m      Monoid callable function to apply
  //! @param t      Tuple to operate on
  //! @return       A tuple of suffix partial accumulations where each element 'I' equals 
  //!               `m(get<0>(t), m(... , m(get<N-2>(t), get<N-1>(t)))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple> struct inclusive_scan_right;
  //!
  //!   template<typename Function, product_type Tuple>
  //!   using inclusive_scan_right_t = typename inclusive_scan_right_t<Function,Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::inclusive_scan_right
  //!
  //! ## Example
  //! @include doc/inclusive_scan_right.cpp
  //================================================================================================
  template<monoid M, sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto inclusive_scan_right(M && m, T && t)
  {
    if constexpr ( record_type<T> ) return inclusive_scan_right(KUMI_FWD(m), KUMI_FWD(t).values);
    else if constexpr(sized_product_type<T,1>) return KUMI_FWD(t);
    else
    {
      return inclusive_scan_right(m, KUMI_FWD(t), m.identity);
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the exclusive suffix scan of all elements of a product type using a 
  //!        tail recursive call.
  //!
  //! @note The first stored value is the provided initial value.  
  //!
  //! @param f      Binary callable function to apply
  //! @param t      Tuple to operate on
  //! @param init   Initial value of the sum
  //! @return       A tuple of suffix partial accumulations where each element 'I' equals 
  //!               `f( f( f(init, get<0>(t)), ...), get<I-1>(t))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple, typename Value> struct exclusive_scan_right;
  //!
  //!   template<typename Function, product_type Tuple, typename Value>
  //!   using exclusive_scan_right_t = typename exclusive_scan_right_t<Function,Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::exclusive_scan_right
  //!
  //! ## Example
  //! @include doc/exclusive_scan_right.cpp
  //================================================================================================
  template<typename Function, product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto exclusive_scan_right(Function && f, T && t, Value init)
  {
    if constexpr ( record_type<T> ) return exclusive_scan_right(KUMI_FWD(f), KUMI_FWD(t).values, init);
    else if constexpr( sized_product_type<T,0> ) return kumi::tuple{init};
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return  (_::scannable{f, kumi::tuple{init}} 
                  << ... 
                  << _::scannable{ f, get<size_v<T>-1-I>(KUMI_FWD(t)) }
                ).acc;
      }
      (std::make_index_sequence<size_v<T>-1>());
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the exclusive suffix scan of all elements of a product type using a 
  //!        non-tail recursive call.
  //!
  //! @note The first stored value is the identity of the provided monoid.
  //!
  //! @param m      Monoid callable function to apply
  //! @param t      Tuple to operate on
  //! @return       A tuple of prefix partial accumulations where each element 'I' equals 
  //!               `m( m( m(init, get<0>(t)), ...), get<I-1>(t))`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<typename Function, product_type Tuple> struct exclusive_scan_right;
  //!
  //!   template<typename Function, product_type Tuple>
  //!   using exclusive_scan_right_t = typename exclusive_scan_right_t<Function,Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::exclusive_scan_right
  //!
  //! ## Example
  //! @include doc/exclusive_scan_right.cpp
  //================================================================================================
  template<monoid M, sized_product_type_or_more<1> T>
  [[nodiscard]] KUMI_ABI constexpr auto exclusive_scan_right(M && m, T && t)
  {
    if constexpr ( record_type<T> ) return exclusive_scan_right(KUMI_FWD(m), KUMI_FWD(t).values);
    else if constexpr (sized_product_type<T,1>) return kumi::tuple{get<0>(KUMI_FWD(t)), m.identity};
    else
    {
      return kumi::exclusive_scan_right(m, KUMI_FWD(t), m.identity);
    }
  }


  namespace result
  {
    template<typename Function, product_type T, typename Value = void>
    struct inclusive_scan_right
    {
      using type = decltype ( kumi::inclusive_scan_right( std::declval<Function>()
                                              , std::declval<T>()
                                              , std::declval<Value>()
                                              )
                            );
    };

    template<typename Function, product_type T>
    struct inclusive_scan_right<Function,T>
    {
      using type = decltype ( kumi::inclusive_scan_right( std::declval<Function>()
                                              , std::declval<T>()
                                              )
                            );
    };

    template<typename Function, product_type T, typename Value = void>
    struct exclusive_scan_right
    {
      using type = decltype ( kumi::exclusive_scan_right( std::declval<Function>()
                                              , std::declval<T>()
                                              , std::declval<Value>()
                                              )
                            );
    };

    template<typename Function, product_type T>
    struct exclusive_scan_right<Function,T>
    {
      using type = decltype ( kumi::exclusive_scan_right( std::declval<Function>()
                                              , std::declval<T>()
                                              )
                            );
    };

    template<typename Function, product_type T, typename Value = void>
    struct inclusive_scan_left
    {
      using type = decltype ( kumi::inclusive_scan_left ( std::declval<Function>()
                                              , std::declval<T>()
                                              , std::declval<Value>()
                                              )
                            );
    };

    template<typename Function, product_type T>
    struct inclusive_scan_left<Function,T>
    {
      using type = decltype ( kumi::inclusive_scan_left ( std::declval<Function>()
                                              , std::declval<T>()
                                              )
                            );
    };

    template<typename Function, product_type T, typename Value = void>
    struct exclusive_scan_left
    {
      using type = decltype ( kumi::exclusive_scan_left ( std::declval<Function>()
                                              , std::declval<T>()
                                              , std::declval<Value>()
                                              )
                            );
    };

    template<typename Function, product_type T>
    struct exclusive_scan_left<Function,T>
    {
      using type = decltype ( kumi::exclusive_scan_left ( std::declval<Function>()
                                              , std::declval<T>()
                                              )
                            );
    };

    template<typename Function, product_type T, typename Value = void>
    using inclusive_scan_right_t = typename inclusive_scan_right<Function,T,Value>::type;

    template<typename Function, product_type T, typename Value = void>
    using exclusive_scan_right_t = typename exclusive_scan_right<Function,T,Value>::type;

    template<typename Function, product_type T, typename Value = void>
    using inclusive_scan_left_t = typename inclusive_scan_left<Function,T,Value>::type;

    template<typename Function, product_type T, typename Value = void>
    using exclusive_scan_left_t = typename exclusive_scan_left<Function,T,Value>::type;
  }
}

