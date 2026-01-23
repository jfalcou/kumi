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
        constexpr std::size_t half = N / 2;

        struct
        {
          std::size_t count = {}, remainder = {}, idx1[half], idx2[half];
        } that{};

        that.remainder = N % 2;

        [&]<std::size_t... I>(std::index_sequence<I...>) {
          ((that.idx1[that.count] = 2 * I, that.idx2[that.count++] = 2 * I + 1), ...);
        }(std::make_index_sequence<half>{});

        return that;
      }
    };

    template<std::size_t N> inline constexpr reducer_t<N> reducer{};
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Performs a tree-like reduction of all elements of a product type.
  //!
  //! @note For associative operations, this produces the same result as a left or right fold,
  //!       but have different intermediate evaluation order.
  //!
  //! @param m   Monoid callable function to apply
  //! @param t   Product type to reduce
  //! @return    The result of reducing `t` by recursively combining elements in a tree structure
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<monoid M, product_type T> struct reduce;
  //!
  //!   template<monoid M, product_type T>
  //!   using reduce_t = typename reduce<M,T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::reduce
  //!
  //! ## Example
  //! @include doc/reduce.cpp
  //================================================================================================
  template<monoid M, product_type T> [[nodiscard]] KUMI_ABI constexpr auto reduce(M&& m, T&& t)
  {
    if constexpr (record_type<T>) return reduce(KUMI_FWD(m), values_of(KUMI_FWD(t)));
    else if constexpr (sized_product_type<T, 0>) return m.identity;
    else if constexpr (sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
    else
    {
      constexpr auto pos = _::reducer<size_v<T>>();

      auto process = [&]<std::size_t I>(index_t<I>) {
        if constexpr (I < pos.count) return KUMI_FWD(m)(get<pos.idx1[I]>(KUMI_FWD(t)), get<pos.idx2[I]>(KUMI_FWD(t)));
        else return get<size_v<T> - 1>(KUMI_FWD(t));
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return reduce(KUMI_FWD(m), tuple{process(index<I>)...});
      }(std::make_index_sequence<pos.count + pos.remainder>{});
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Performs a tree-like reduction of all elements of a product type.
  //!
  //! @note For associative operations, this produces the same result as a left or right fold,
  //!       but have different intermediate evaluation order.
  //!
  //! @param m    Monoid callable function to apply
  //! @param t    Product type to reduce
  //! @param init Optional initial value of the reduction.
  //! @return     The result of reducing `t` by recursively combining elements in a tree structure.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<monoid M, product_type T, typename Value> struct reduce;
  //!
  //!   template<monoid M, product_type T, typename Value>
  //!   using reduce_t = typename reduce<M,T,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::reduce
  //!
  //! ## Example
  //! @include doc/reduce.cpp
  //================================================================================================
  template<monoid M, product_type T, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto reduce(M&& m, T&& t, Value init)
  {
    if constexpr (sized_product_type<T, 0>) return init;
    else return KUMI_FWD(m)(init, reduce(KUMI_FWD(m), KUMI_FWD(t)));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Performs a tree-like reduction of all elements of a product type. The given map
  //!        function is applied before excution the reduction to each element of the input.
  //!
  //! @note For associative operations, this produces the same result as a left or right fold
  //!       preceeded by map, but have different intermediate evaluation order.
  //!
  //! @param f   Mapping function to apply
  //! @param m   Monoid callable function to apply
  //! @param t   Product type to reduce
  //! @return    The result of reducing `t` by recursively combining elements in a tree structure
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<monoid M, product_type T> struct map_reduce;
  //!
  //!   template<monoid M, product_type T>
  //!   using map_reduce_t = typename map_reduce<M,T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::map_reduce
  //!
  //! ## Example
  //! @include doc/map_reduce.cpp
  //================================================================================================
  template<product_type T, monoid M, typename Function>
  [[nodiscard]] KUMI_ABI constexpr auto map_reduce(Function f, M&& m, T&& t)
  {
    if constexpr (record_type<T>) return map_reduce(f, KUMI_FWD(m), values_of(KUMI_FWD(t)));
    else if constexpr (sized_product_type<T, 0>) return m.identity;
    else if constexpr (sized_product_type<T, 1>) return invoke(f, get<0>(KUMI_FWD(t)));
    else
    {
      constexpr auto pos = _::reducer<size_v<T>>();
      auto process = [&]<std::size_t I>(index_t<I>) {
        if constexpr (I < pos.count)
          return KUMI_FWD(m)(invoke(f, get<pos.idx1[I]>(KUMI_FWD(t))), invoke(f, get<pos.idx2[I]>(KUMI_FWD(t))));
        else return invoke(f, get<size_v<T> - 1>(KUMI_FWD(t)));
      };

      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return reduce(KUMI_FWD(m), tuple{process(index<I>)...});
      }(std::make_index_sequence<pos.count + pos.remainder>{});
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Performs a tree-like reduction of all elements of a product type. The given map
  //!        function is applied before excution the reduction to each element of the input.
  //!
  //! @note For associative operations, this produces the same result as a left or right fold
  //!       preceeded by map, but have different intermediate evaluation order.
  //!
  //! @param f   Mapping function to apply
  //! @param m   Monoid callable function to apply
  //! @param t   Product type to reduce
  //! @param init Optional initial value of the reduction.
  //! @return    The result of reducing `t` by recursively combining elements in a tree structure
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<monoid M, product_type T, typename Value> struct map_reduce;
  //!
  //!   template<monoid M, product_type T, typename Value>
  //!   using map_reduce_t = typename map_reduce<M,T,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::map_reduce
  //!
  //! ## Example
  //! @include doc/map_reduce.cpp
  //================================================================================================
  template<monoid M, product_type T, typename Function, typename Value>
  [[nodiscard]] KUMI_ABI constexpr auto map_reduce(Function f, M&& m, T&& t, Value init)
  {
    if constexpr (sized_product_type<T, 0>) return invoke(f, init);
    else return KUMI_FWD(m)(invoke(f, init), map_reduce(f, KUMI_FWD(m), KUMI_FWD(t)));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the sum of all elements.
  //!
  //! @param t      Product type to operate on
  //! @param init   Optional initial value of the sum
  //! @return       The value of `get<0>(t) + ... + get<N-1>(t) + init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, typename Value> struct sum;
  //!
  //!   template<product_type T, typename Value>
  //!   using sum_t = typename sum<T,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::sum
  //!
  //! ## Example
  //! @include doc/sum.cpp
  //================================================================================================
  template<product_type T, typename Value> [[nodiscard]] KUMI_ABI constexpr auto sum(T&& t, Value init)
  {
    return reduce(function::plus, KUMI_FWD(t), init);
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the sum of all elements.
  //!
  //! @param t      Product type to operate on
  //! @return       The value of `get<0>(t) + ... + get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct sum;
  //!
  //!   template<product_type Te>
  //!   using sum_t = typename sum<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::sum
  //!
  //! ## Example
  //! @include doc/sum.cpp
  //================================================================================================
  template<product_type T> [[nodiscard]] KUMI_ABI constexpr auto sum(T&& t)
  {
    return reduce(function::plus, KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the product of all elements.
  //!
  //! @param t      Product type to operate on
  //! @param init   Initial value of the product
  //! @return The value of `get<0>(t) * ... * get<N-1>(t) * init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, typename Value> struct prod;
  //!
  //!   template<product_type T, typename Value>
  //!   using prod_t = typename prod<T,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::prod
  //!
  //! ## Example
  //! @include doc/prod.cpp
  //================================================================================================
  template<product_type T, typename Value> [[nodiscard]] KUMI_ABI constexpr auto prod(T&& t, Value init)
  {
    return reduce(function::multiplies, KUMI_FWD(t), init);
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the product of all elements.
  //!
  //! @param t      Product type to operate on
  //! @return The value of `get<0>(t) * ... * get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct prod;
  //!
  //!   template<product_type T>
  //!   using prod_t = typename prod<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::prod
  //!
  //! ## Example
  //! @include doc/prod.cpp
  //================================================================================================
  template<product_type T> [[nodiscard]] KUMI_ABI constexpr auto prod(T&& t)
  {
    return reduce(function::multiplies, KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise AND of all elements.
  //!
  //! @param t      Product type to operate on
  //! @param init   Optional initial value of the reduction
  //! @return       The value of `get<0>(t) & ... & get<N-1>(t) & init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, typename Value> struct bit_and;
  //!
  //!   template<product_type T, typename Value>
  //!   using bit_and_t = typename bit_and<T,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_and
  //!
  //! ## Example
  //! @include doc/bit_and.cpp
  //================================================================================================
  template<product_type T, typename Value> [[nodiscard]] KUMI_ABI constexpr auto bit_and(T&& t, Value init)
  {
    return reduce(function::bit_and, KUMI_FWD(t), init);
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise AND of all elements.
  //!
  //! @param t  Product type to operate on.
  //! @return   The value of `get<0>(t) & ... & get<N-1>(t)`.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct bit_and;
  //!
  //!   template<product_type T>
  //!   using bit_and_t = typename bit_and<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_and
  //!
  //! ## Example
  //! @include doc/bit_and.cpp
  //================================================================================================
  template<product_type T> [[nodiscard]] KUMI_ABI constexpr auto bit_and(T&& t)
  {
    return reduce(function::bit_and, KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise OR of all elements.
  //!
  //! @param t      Product type to operate on
  //! @param init   Optional initial value of the reduction
  //! @return       The value of `get<0>(t) | ... | get<N-1>(t) | init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, typename Value> struct bit_or;
  //!
  //!   template<product_type T, typename Value>
  //!   using bit_or_t = typename bit_or<T,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_or
  //!
  //! ## Example
  //! @include doc/bit_or.cpp
  //================================================================================================
  template<product_type T, typename Value> [[nodiscard]] KUMI_ABI constexpr auto bit_or(T&& t, Value init)
  {
    return reduce(function::bit_or, KUMI_FWD(t), init);
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise OR of all elements.
  //!
  //! @param t  Product type to operate on
  //! @return   The value of `get<0>(t) | ... | get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct bit_or;
  //!
  //!   template<product_type T>
  //!   using bit_or_t = typename bit_or<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_or
  //!
  //! ## Example
  //! @include doc/bit_or.cpp
  //================================================================================================
  template<product_type T> [[nodiscard]] KUMI_ABI constexpr auto bit_or(T&& t)
  {
    return reduce(function::bit_or, KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise XOR of all elements.
  //!
  //! @param t      Product type to operate on
  //! @param init   Optional initial value of the reduction
  //! @return       The value of `get<0>(t) ^ ... ^ get<N-1>(t) ^ init`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T, typename Value> struct bit_xor;
  //!
  //!   template<product_type T, typename Value>
  //!   using bit_xor_t = typename bit_xor<T,Value>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_xor
  //!
  //! ## Example
  //! @include doc/bit_xor.cpp
  //================================================================================================
  template<product_type T, typename Value> [[nodiscard]] KUMI_ABI constexpr auto bit_xor(T&& t, Value init)
  {
    return reduce(function::bit_xor, KUMI_FWD(t), init);
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the bitwise XOR of all elements.
  //!
  //! @param t  Product type to operate on
  //! @return   The value of `get<0>(t) ^ ... ^ get<N-1>(t)`
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct bit_xor;
  //!
  //!   template<product_type T>
  //!   using bit_xor_t = typename bit_xor<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::bit_xor
  //!
  //! ## Example
  //! @include doc/bit_xor.cpp
  //================================================================================================
  template<product_type T> [[nodiscard]] KUMI_ABI constexpr auto bit_xor(T&& t)
  {
    return reduce(function::bit_xor, KUMI_FWD(t));
  }

  namespace result
  {
    template<monoid M, product_type T, typename Value = void> struct reduce
    {
      using type = decltype(kumi::reduce(std::declval<M>(), std::declval<T>(), std::declval<Value>()));
    };

    template<monoid M, product_type T> struct reduce<M, T>
    {
      using type = decltype(kumi::reduce(std::declval<M>(), std::declval<T>()));
    };

    template<typename F, monoid M, product_type T, typename Value = void> struct map_reduce
    {
      using type =
        decltype(kumi::map_reduce(std::declval<F>(), std::declval<M>(), std::declval<T>(), std::declval<Value>()));
    };

    template<typename F, monoid M, product_type T> struct map_reduce<F, M, T>
    {
      using type = decltype(kumi::map_reduce(std::declval<F>(), std::declval<M>(), std::declval<T>()));
    };

    template<product_type T, typename Value = void> struct sum
    {
      using type = decltype(kumi::sum(std::declval<T>(), std::declval<Value>()));
    };

    template<product_type T> struct sum<T>
    {
      using type = decltype(kumi::sum(std::declval<T>()));
    };

    template<product_type T, typename Value = void> struct prod
    {
      using type = decltype(kumi::prod(std::declval<T>(), std::declval<Value>()));
    };

    template<product_type T> struct prod<T>
    {
      using type = decltype(kumi::prod(std::declval<T>()));
    };

    template<product_type T, typename Value = void> struct bit_and
    {
      using type = decltype(kumi::bit_and(std::declval<T>(), std::declval<Value>()));
    };

    template<product_type T> struct bit_and<T>
    {
      using type = decltype(kumi::bit_and(std::declval<T>()));
    };

    template<product_type T, typename Value = void> struct bit_or
    {
      using type = decltype(kumi::bit_or(std::declval<T>(), std::declval<Value>()));
    };

    template<product_type T> struct bit_or<T>
    {
      using type = decltype(kumi::bit_or(std::declval<T>()));
    };

    template<product_type T, typename Value = void> struct bit_xor
    {
      using type = decltype(kumi::bit_xor(std::declval<T>(), std::declval<Value>()));
    };

    template<product_type T> struct bit_xor<T>
    {
      using type = decltype(kumi::bit_xor(std::declval<T>()));
    };

    template<monoid M, product_type T, typename Value = void> using reduce_t = typename reduce<M, T, Value>::type;

    template<typename F, monoid M, product_type T, typename Value = void>
    using map_reduce_t = typename map_reduce<F, M, T, Value>::type;

    template<product_type T, typename Value = void> using sum_t = typename sum<T, Value>::type;

    template<product_type T, typename Value = void> using prod_t = typename prod<T, Value>::type;

    template<product_type T, typename Value = void> using bit_and_t = typename bit_and<T, Value>::type;

    template<product_type T, typename Value = void> using bit_or_t = typename bit_or<T, Value>::type;

    template<product_type T, typename Value = void> using bit_xor_t = typename bit_xor<T, Value>::type;

  }
}
