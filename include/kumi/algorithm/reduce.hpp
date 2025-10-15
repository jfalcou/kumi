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
    template<std::size_t N> struct reducer_t
    {
      constexpr auto operator()() const noexcept
      {
        constexpr std::size_t half = N/2;
        struct { std::size_t count = {}, remainder = {}, idx1[half], idx2[half]; } that{};
        that.remainder = N % 2;
          
        [&]<std::size_t...I>(std::index_sequence<I...>)
        {
          ((that.idx1[that.count] = 2*I, that.idx2[that.count++] = 2*I+1),...);
        }(std::make_index_sequence<half>{});
        
        return that;
      }
    };

    template<std::size_t N>
    inline constexpr reducer_t<N> reducer{};  
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Performs a tree-like reduction of all elements of a product type.
  //!
  //! @note For associative operations, this produces the same result as a left or right fold,
  //!       but may have different intermediate evaluation order.
  //!
  //! @param m   Monoid callable function to apply
  //! @param t   Tuple to reduce
  //! @return    The result of reducing `t` by recursively combining elements in a tree structure
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<monoid M, product_type Tuple> struct reduce;
  //!
  //!   template<monoid M, product_type Tuple>
  //!   using reduce_t = typename reduce_t<M,Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::reduce
  //! ## Example
  //! @include doc/reduce.cpp
  //================================================================================================
  template<monoid M, product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto reduce( M && m, T && t ) 
  {
    if constexpr ( record_type<T> ) return reduce(KUMI_FWD(m), KUMI_FWD(t).values()) ;
    else if constexpr ( sized_product_type<T, 0> )  return m.identity;
    else if constexpr ( sized_product_type<T, 1> )  return get<0>(KUMI_FWD(t));
    else 
    {
      constexpr auto pos = _::reducer<size_v<T>>();
      
      auto process = [&]<std::size_t I>(index_t<I>)
      {
        if constexpr ( I < pos.count ) return KUMI_FWD(m)(get<pos.idx1[I]>(KUMI_FWD(t)), 
                                                          get<pos.idx2[I]>(KUMI_FWD(t)));
        else return get<size_v<T>-1>(KUMI_FWD(t));
      };

      return [&]<std::size_t...I>(std::index_sequence<I...>)
      {
        return reduce(KUMI_FWD(m), kumi::tuple{process(index<I>)...});
      }(std::make_index_sequence<pos.count + pos.remainder>{});
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Performs a tree-like reduction of all elements of a product type. The given map 
  //!        function is applied before excution the reduction to each element of the input.
  //!
  //! @note For associative operations, this produces the same result as a left or right fold 
  //!       preceeded by map, but may have different intermediate evaluation order.
  //!
  //! @param f   Mapping function to apply
  //! @param m   Monoid callable function to apply
  //! @param t   Tuple to reduce
  //! @return    The result of reducing `t` by recursively combining elements in a tree structure
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<monoid M, product_type Tuple> struct map_reduce;
  //!
  //!   template<monoid M, product_type Tuple>
  //!   using map_reduce_t = typename map_reduce_t<M,Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::map_reduce
  //! ## Example
  //! @include doc/map_reduce.cpp
  //================================================================================================
  template<product_type T, monoid M, typename Function>
  [[nodiscard]] KUMI_ABI constexpr auto map_reduce( Function && f, M && m, T && t ) 
  {
    if constexpr ( record_type<T> ) return map_reduce(KUMI_FWD(f), KUMI_FWD(m), KUMI_FWD(t).values());
    else if constexpr ( sized_product_type<T, 0> )  return m.identity;
    else if constexpr ( sized_product_type<T, 1> )  return KUMI_FWD(f)(get<0>(KUMI_FWD(t)));
    else 
    {
      constexpr auto pos = _::reducer<size_v<T>>();
      auto process = [&]<std::size_t I>(index_t<I>)
      {
        if constexpr ( I < pos.count )
            return KUMI_FWD(m)(KUMI_FWD(f)(get<pos.idx1[I]>(KUMI_FWD(t))),                                         
                               KUMI_FWD(f)(get<pos.idx2[I]>(KUMI_FWD(t))));
        else return KUMI_FWD(f)(get<size_v<T>-1>(KUMI_FWD(t)));
      };

      return [&]<std::size_t...I>(std::index_sequence<I...>)
      {
        return map_reduce(KUMI_FWD(f), KUMI_FWD(m), kumi::tuple{process(index<I>)...});
      }(std::make_index_sequence<pos.count + pos.remainder>{});
    }
  }
  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the sum of all elements.
  //!
  //! @param t      Tuple to operate on.
  //! @param init   Optional initial value of the sum.
  //! @return       The value of `get<0>(t) + ... + get<N-1>(t) + init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple, typename Value> struct sum;
  //!
  //!   template<product_type Tuple, typename Value>
  //!   using sum_t = typename sum_t<Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::sum
  //================================================================================================
  template<product_type Tuple, typename Value>
  [[deprecated("Use folds/reduce/scan with the corresponding monoid")]]
  [[nodiscard]] KUMI_ABI constexpr auto sum(Tuple&& t, Value init)
  {
    if constexpr( sized_product_type<Tuple,0>) return init;
    else return kumi::apply( [init](auto &&... m) { return (m + ... + init); }, KUMI_FWD(t) );
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the sum of all elements.
  //!
  //! @param t      Tuple to operate on.
  //! @return       The value of `get<0>(t) + ... + get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct sum;
  //!
  //!   template<product_type Tuple>
  //!   using sum_t = typename sum_t<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::sum
  //================================================================================================
  template<product_type Tuple>
  [[deprecated("Use folds/reduce/scan with the corresponding monoid")]]
  [[nodiscard]] KUMI_ABI constexpr auto sum(Tuple&& t)
  {
    auto&& [head,tail] = kumi::split(KUMI_FWD(t), index<1>);
    return sum(tail, get<0>(head));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the product of all elements.
  //!
  //! @param t      Tuple to operate on
  //! @param init   Initial value of the product
  //! @return The value of `get<0>(t) * ... * get<N-1>(t) * init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple, typename Value> struct prod;
  //!
  //!   template<product_type Tuple, typename Value>
  //!   using prod_t = typename prod_t<Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::prod
  //================================================================================================
  template<product_type Tuple, typename Value>
  [[deprecated("Use folds/reduce/scan with the corresponding monoid")]]
  [[nodiscard]] KUMI_ABI constexpr auto prod(Tuple&& t, Value init)
  {
    if constexpr(sized_product_type<Tuple,0>) return init;
    else return kumi::apply( [init](auto &&... m) { return (m * ... * init); }, KUMI_FWD(t) );
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the product of all elements.
  //!
  //! @param t      Tuple to operate on
  //! @return The value of `get<0>(t) * ... * get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct prod;
  //!
  //!   template<product_type Tuple>
  //!   using prod_t = typename prod_t<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::prod
  //================================================================================================
  template<product_type Tuple>
  [[deprecated("Use folds/reduce/scan with the corresponding monoid")]]
  [[nodiscard]] KUMI_ABI constexpr auto prod(Tuple&& t)
  {
    auto&& [head,tail] = split(KUMI_FWD(t), index<1>);
    return prod(tail, get<0>(head));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise AND of all elements.
  //!
  //! @param t      Tuple to operate on
  //! @param init   Initial value of the product
  //! @return The value of `get<0>(t) & ... & get<N-1>(t) & init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple, typename Value> struct bit_and;
  //!
  //!   template<product_type Tuple, typename Value>
  //!   using prod_t = typename bit_and_t<Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_and
  //================================================================================================
  template<product_type Tuple, typename Value>
  [[deprecated("Use folds/reduce/scan with the corresponding monoid")]]
  [[nodiscard]] KUMI_ABI constexpr auto bit_and(Tuple&& t, Value init)
  {
    if constexpr(sized_product_type<Tuple,0>) return init;
    else return kumi::apply( [init](auto &&... m) { return (m & ... & init); }, KUMI_FWD(t) );
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise AND of all elements.
  //!
  //! @param t      Tuple to operate on
  //! @return The value of `get<0>(t) & ... & get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct bit_and;
  //!
  //!   template<product_type Tuple>
  //!   using prod_t = typename bit_and_t<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_and
  //================================================================================================
  template<product_type Tuple>
  [[deprecated("Use folds/reduce/scan with the corresponding monoid")]]
  [[nodiscard]] KUMI_ABI constexpr auto bit_and(Tuple&& t)
  {
    auto&& [head,tail] = split(KUMI_FWD(t), index<1>);
    return bit_and(tail, get<0>(head));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise OR of all elements.
  //!
  //! @param t      Tuple to operate on
  //! @param init   Initial value of the product
  //! @return The value of `get<0>(t) | ... | get<N-1>(t) & init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple, typename Value> struct bit_or;
  //!
  //!   template<product_type Tuple, typename Value>
  //!   using prod_t = typename bit_or_t<Tuple,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_or
  //================================================================================================
  template<product_type Tuple, typename Value>
  [[deprecated("Use folds/reduce/scan with the corresponding monoid")]]
  [[nodiscard]] KUMI_ABI constexpr auto bit_or(Tuple&& t, Value init)
  {
    if constexpr(sized_product_type<Tuple,0>) return init;
    else return kumi::apply( [init](auto &&... m) { return (m | ... | init); }, KUMI_FWD(t) );
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise OR of all elements.
  //!
  //! @param t      Tuple to operate on
  //! @return The value of `get<0>(t) | ... | get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct bit_or;
  //!
  //!   template<product_type Tuple>
  //!   using prod_t = typename bit_or_t<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_or
  //================================================================================================
  template<product_type Tuple>
  [[deprecated("Use folds/reduce/scan with the corresponding monoid")]]
  [[nodiscard]] KUMI_ABI constexpr auto bit_or(Tuple&& t)
  {
    auto&& [head,tail] = split(KUMI_FWD(t), index<1>);
    return bit_or(tail, get<0>(head));
  }

  namespace result
  {
    template<monoid M, product_type T>
    struct reduce
    {
      using type = decltype(kumi::reduce(std::declval<M>(), std::declval<T>()));
    };

    template<typename F, monoid M, product_type T>
    struct map_reduce
    {
      using type = decltype(kumi::map_reduce( std::declval<F>()
                                            , std::declval<M>()
                                            , std::declval<T>()
                                            ));
    };

    template<monoid M, product_type T>
    using reduce_t = typename reduce<M,T>::type;

    template<typename F, monoid M, product_type T>
    using map_reduce_t = typename map_reduce<F,M,T>::type;

    template<product_type Tuple, typename Value = void>
    struct sum
    {
      using type = decltype(kumi::sum(std::declval<Tuple>(), std::declval<Value>()));
    };

    template<product_type Tuple> struct sum<Tuple>
    {
      using type = decltype(kumi::sum(std::declval<Tuple>()));
    };

    template<product_type Tuple, typename Value = void>
    struct prod
    {
      using type = decltype(kumi::prod(std::declval<Tuple>(), std::declval<Value>()));
    };

    template<product_type Tuple>
    struct prod<Tuple>
    {
      using type = decltype(kumi::prod(std::declval<Tuple>()));
    };

    template<product_type Tuple, typename Value = void>
    struct bit_and
    {
      using type = decltype(kumi::bit_and(std::declval<Tuple>(), std::declval<Value>()));
    };

    template<product_type Tuple>
    struct bit_and<Tuple>
    {
      using type = decltype(kumi::bit_and(std::declval<Tuple>()));
    };

    template<product_type Tuple, typename Value = void>
    struct bit_or
    {
      using type = decltype(kumi::bit_or(std::declval<Tuple>(), std::declval<Value>()));
    };

    template<product_type Tuple>
    struct bit_or<Tuple>
    {
      using type = decltype(kumi::bit_or(std::declval<Tuple>()));
    };

    template<product_type Tuple, typename Value = void>
    using sum_t = typename sum<Tuple,Value>::type;

    template<product_type Tuple, typename Value = void>
    using prod_t = typename prod<Tuple,Value>::type;

    template<product_type Tuple, typename Value = void>
    using bit_and_t = typename bit_and<Tuple,Value>::type;

    template<product_type Tuple, typename Value = void>
    using bit_or_t = typename bit_or<Tuple,Value>::type;
  }
}
