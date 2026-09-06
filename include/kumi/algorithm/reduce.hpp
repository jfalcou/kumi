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
  namespace _
  {
    template<typename M, typename S, typename T, std::size_t N, std::size_t... F, std::size_t... L>
    KUMI_HIDDEN_ABI constexpr auto reduce_(
      kumi::_::adl_tag_t, M&& m, S s, T&& t, kumi::index_t<N>, std::index_sequence<F...>, std::index_sequence<L...>)
    {
      if constexpr (N == 1)
        return s(KUMI_FWD(m), kumi::tuple{kumi::invoke(KUMI_FWD(m), get<F>(KUMI_FWD(t)), get<L>(KUMI_FWD(t)))...,
                                          get<kumi::size_v<T> - 1>(KUMI_FWD(t))});
      else return s(KUMI_FWD(m), kumi::tuple{kumi::invoke(KUMI_FWD(m), get<F>(KUMI_FWD(t)), get<L>(KUMI_FWD(t)))...});
    }

    template<typename M, typename T, typename F, typename S, std::size_t N, std::size_t... I, std::size_t... J>
    KUMI_HIDDEN_ABI constexpr auto map_reduce_(kumi::_::adl_tag_t,
                                               M&& m,
                                               T&& t,
                                               F f,
                                               S s,
                                               kumi::index_t<N>,
                                               std::index_sequence<I...>,
                                               std::index_sequence<J...>)
    {
      if constexpr (N == 1)
        return s(KUMI_FWD(m), kumi::tuple{kumi::invoke(KUMI_FWD(m), kumi::invoke(f, get<I>(KUMI_FWD(t))),
                                                       kumi::invoke(f, get<J>(KUMI_FWD(t))))...,
                                          kumi::invoke(f, get<kumi::size_v<T> - 1>(KUMI_FWD(t)))});
      else
        return s(KUMI_FWD(m), kumi::tuple{kumi::invoke(KUMI_FWD(m), kumi::invoke(f, get<I>(KUMI_FWD(t))),
                                                       kumi::invoke(f, get<J>(KUMI_FWD(t))))...});
    }
  }

  struct reduce_t
  {
    template<kumi::concepts::monoid M, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(M&& m, T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return m.identity;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(KUMI_FWD(m), kumi::values_of(KUMI_FWD(t)));
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
      else
      {
        constexpr auto sz = kumi::size_v<T>;
        constexpr auto pos = kumi::function::reducer(kumi::index<sz / 2>, kumi::index<sz % 2>);
        return reduce_(kumi::_::adl_tag, KUMI_FWD(m), (*this), KUMI_FWD(t), get<2>(pos), get<0>(pos), get<1>(pos));
      }
    }

    template<kumi::concepts::monoid M, kumi::concepts::product_type T, typename Value>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(M&& m, T&& t, Value init) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return init;
      else return KUMI_FWD(m)(init, (*this)(KUMI_FWD(m), KUMI_FWD(t)));
    }
  };

  struct map_reduce_t
  {
    template<kumi::concepts::product_type T, kumi::concepts::monoid M, typename Function>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Function f, M&& m, T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return m.identity;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(f, KUMI_FWD(m), kumi::values_of(KUMI_FWD(t)));
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return kumi::invoke(f, get<0>(KUMI_FWD(t)));
      else
      {
        constexpr auto sz = kumi::size_v<T>;
        constexpr auto pos = kumi::function::reducer(kumi::index<sz / 2>, kumi::index<sz % 2>);
        return map_reduce_(kumi::_::adl_tag, KUMI_FWD(m), KUMI_FWD(t), f, kumi::reduce_t{}, get<2>(pos), get<0>(pos),
                           get<1>(pos));
      }
    }

    template<kumi::concepts::monoid M, kumi::concepts::product_type T, typename Function, typename Value>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Function f, M&& m, T&& t, Value init) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return kumi::invoke(f, init);
      else return KUMI_FWD(m)(kumi::invoke(f, init), (*this)(f, KUMI_FWD(m), KUMI_FWD(t)));
    }
  };

  struct sum_t : private kumi::reduce_t
  {
    template<kumi::concepts::product_type T, typename Value>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Value init) const
    {
      return this->reduce_t::operator()(kumi::function::plus, KUMI_FWD(t), init);
    }

    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      return this->reduce_t::operator()(kumi::function::plus, KUMI_FWD(t));
    }
  };

  struct prod_t : private kumi::reduce_t
  {
    template<kumi::concepts::product_type T, typename Value>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Value init) const
    {
      return this->reduce_t::operator()(kumi::function::multiplies, KUMI_FWD(t), init);
    }

    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      return this->reduce_t::operator()(kumi::function::multiplies, KUMI_FWD(t));
    }
  };

  struct bit_and_t : private kumi::reduce_t
  {
    template<kumi::concepts::product_type T, typename Value>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Value init) const
    {
      return this->reduce_t::operator()(kumi::function::bit_and, KUMI_FWD(t), init);
    }

    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      return this->reduce_t::operator()(kumi::function::bit_and, KUMI_FWD(t));
    }
  };

  struct bit_or_t : private kumi::reduce_t
  {
    template<kumi::concepts::product_type T, typename Value>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Value init) const
    {
      return this->reduce_t::operator()(kumi::function::bit_or, KUMI_FWD(t), init);
    }

    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      return this->reduce_t::operator()(kumi::function::bit_or, KUMI_FWD(t));
    }
  };

  struct bit_xor_t : private kumi::reduce_t
  {
    template<kumi::concepts::product_type T, typename Value>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Value init) const
    {
      return this->reduce_t::operator()(kumi::function::bit_xor, KUMI_FWD(t), init);
    }

    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      return this->reduce_t::operator()(kumi::function::bit_xor, KUMI_FWD(t));
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_reductions

    @var reduce
    @brief Callable object performing a tree-like reduction of all elements of a product type.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note For associative operations, this produces the same result as a left or right fold,
          but have different intermediate evaluation order.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/reduce.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<monoid M, product_type T>
      constexpr auto reduce(M && m, T && t);
    @endcode

    @code
      template<monoid M, product_type T, typename V>
      constexpr auto reduce(M && m, T && t, V init);
    @endcode

    @subgroupheader{Parameters}

      - `m`: Monoid callable function to apply
      - `t`: Product Type to reduce
      - `init`: Optional initial value of the reduction.

    @subgroupheader{Return value}

      * The result of reducing the elements of `t` by `m`, recursively combining elements in a tree structure.

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<monoid M, product_type T> struct reduce;

      template<monoid M, product_type T>
      using reduce_t = typename reduce<M,T>::type;

      template<monoid M, product_type T, typename Value> struct reduce;

      template<monoid M, product_type T, typename Value>
      using reduce_t = typename reduce<M,T,Value>::type;
    }
    @endcode

    Computes the return type of a call to kumi::reduce

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/reduce.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/reduce.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_ENTRY_POINT reduce_t reduce{};

  //====================================================================================================================
  /**
    @ingroup kumi_reductions

    @var map_reduce
    @brief Callable object performing a tree-like reduction of all elements of a product type. The given map
              function is applied before excution the reduction to each element of the input.


    On record types, this function operates on the underlying values, not on the fields themselves.

    @note For associative operations, this produces the same result as a left or right fold preceeded by map,
          but have different intermediate evaluation order.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/reduce.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, monoid M, product_type T>
      constexpr auto map_reduce(Function f, M && m, T && t);
    @endcode

    @code
      template<typename Function, monoid M, product_type T, typename V>
      constexpr auto reduce(Function f, M && m, T && t, V init);
    @endcode

    @subgroupheader{Parameters}

      - `f`: Mapping function to apply
      - `m`: Monoid callable function to apply
      - `t`: Product Type to reduce
      - `init`: Optional initial value of the reduction.

    @subgroupheader{Return value}

      * The result of reducing the elements of `t` by `m` after beeing processed by `f`,
        recursively combining elements in a tree structure.

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<monoid M, product_type T> struct map_reduce;

      template<monoid M, product_type T>
      using map_reduce_t = typename map_reduce<M,T>::type;

      template<monoid M, product_type T, typename Value> struct map_reduce;

      template<monoid M, product_type T, typename Value>
      using map_reduce_t = typename map_reduce<M,T,Value>::type;
    }
    @endcode

    Computes the return type of a call to kumi::map_reduce

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/map_reduce.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/map_reduce.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_ENTRY_POINT map_reduce_t map_reduce{};

  //====================================================================================================================
  /**
    @ingroup kumi_reductions

    @var sum
    @brief Callable object computing the sum of all elements.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note For associative operations, this produces the same result as a left or right fold,
          but have different intermediate evaluation order.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/reduce.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto sum(T && t);
    @endcode

    @code
      template<product_type T, typename V>
      constexpr auto sum(T && t, V init);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to operate on
      - `init`: Optional initial value of the reduction.

    @subgroupheader{Return value}

      * The result of the computation of `get<0>(t) + ... + get<N-1>(t) + init`

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T, typename Value> struct sum;

      template<product_type T, typename Value>
      using sum_t = typename sum<T,Value>::type;
    }
    @endcode

    Computes the return type of a call to kumi::sum

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/sum.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/sum.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_ENTRY_POINT sum_t sum{};

  //====================================================================================================================
  /**
    @ingroup kumi_reductions

    @var prod
    @brief Callable object computing the product of all elements.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note For associative operations, this produces the same result as a left or right fold,
          but have different intermediate evaluation order.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/reduce.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto prod(T && t);
    @endcode

    @code
      template<product_type T, typename V>
      constexpr auto prod(T && t, V init);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to operate on
      - `init`: Optional initial value of the reduction.

    @subgroupheader{Return value}

      * The result of the computation of `get<0>(t) * ... * get<N-1>(t) * init`

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T, typename Value> struct prod;

      template<product_type T, typename Value>
      using prod_t = typename prod<T,Value>::type;
    }
    @endcode

    Computes the return type of a call to kumi::prod

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/prod.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/prod.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_ENTRY_POINT prod_t prod{};

  //====================================================================================================================
  /**
    @ingroup kumi_reductions

    @var bit_and
    @brief Callable object computing the bitwise AND of all elements.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note For associative operations, this produces the same result as a left or right fold,
          but have different intermediate evaluation order.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/reduce.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto bit_and(T && t);
    @endcode

    @code
      template<product_type T, typename V>
      constexpr auto bit_and(T && t, V init);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to operate on
      - `init`: Optional initial value of the reduction.

    @subgroupheader{Return value}

      * The result of the computation of `get<0>(t) & ... & get<N-1>(t) & init`

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T, typename Value> struct bit_and;

      template<product_type T, typename Value>
      using bit_and_t = typename bit_and<T,Value>::type;
    }
    @endcode

    Computes the return type of a call to kumi::bit_and

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/bit_and.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/bit_and.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_ENTRY_POINT bit_and_t bit_and{};

  //====================================================================================================================
  /**
    @ingroup kumi_reductions

    @var bit_or
    @brief Callable object computing the bitwise OR of all elements.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note For associative operations, this produces the same result as a left or right fold,
          but have different intermediate evaluation order.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/reduce.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto bit_or(T && t);
    @endcode

    @code
      template<product_type T, typename V>
      constexpr auto bit_or(T && t, V init);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to operate on
      - `init`: Optional initial value of the reduction.

    @subgroupheader{Return value}

      * The result of the computation of `get<0>(t) | ... | get<N-1>(t) | init`

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T, typename Value> struct bit_or;

      template<product_type T, typename Value>
      using bit_or_t = typename bit_or<T,Value>::type;
    }
    @endcode

    Computes the return type of a call to kumi::bit_or

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/bit_or.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/bit_or.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_ENTRY_POINT bit_or_t bit_or{};

  //====================================================================================================================
  /**
    @ingroup kumi_reductions

    @var bit_xor
    @brief Callable object computing the bitwise XOR of all elements.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @note For associative operations, this produces the same result as a left or right fold,
          but have different intermediate evaluation order.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/reduce.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto bit_xor(T && t);
    @endcode

    @code
      template<product_type T, typename V>
      constexpr auto bit_xor(T && t, V init);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to operate on
      - `init`: Optional initial value of the reduction.

    @subgroupheader{Return value}

      * The result of the computation of `get<0>(t) ^ ... ^ get<N-1>(t) ^ init`

    @groupheader{Helper type}

    @code
    namespace kumi::result
    {
      template<product_type T, typename Value> struct bit_xor;

      template<product_type T, typename Value>
      using bit_xor_t = typename bit_xor<T,Value>::type;
    }
    @endcode

    Computes the return type of a call to kumi::bit_xor

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/bit_xor.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/bit_xor.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_ENTRY_POINT bit_xor_t bit_xor{};

  namespace result
  {
    //! [reduce_t]
    template<kumi::concepts::monoid M, kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    using reduce_t = decltype(kumi::reduce(std::declval<M>(), std::declval<T>(), std::declval<Value>()...));

    template<kumi::concepts::monoid M, kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    struct reduce
    {
      using type = kumi::result::reduce_t<M, T, Value...>;
    };

    //! [reduce_t]

    //! [map_reduce_t]
    template<typename F, kumi::concepts::monoid M, kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    using map_reduce_t =
      decltype(kumi::map_reduce(std::declval<F>(), std::declval<M>(), std::declval<T>(), std::declval<Value>()...));

    template<typename F, kumi::concepts::monoid M, kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    struct map_reduce
    {
      using type = kumi::result::map_reduce_t<F, M, T, Value...>;
    };

    //! [map_reduce_t]

    //! [sum_t]
    template<kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    using sum_t = decltype(kumi::sum(std::declval<T>(), std::declval<Value>()...));

    template<kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    struct sum
    {
      using type = kumi::result::sum_t<T, Value...>;
    };

    //! [sum_t]

    //! [prod_t]
    template<kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    using prod_t = decltype(kumi::prod(std::declval<T>(), std::declval<Value>()...));

    template<kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    struct prod
    {
      using type = kumi::result::prod_t<T, Value...>;
    };

    //! [prod_t]

    //! [bit_and_t]
    template<kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    using bit_and_t = decltype(kumi::bit_and(std::declval<T>(), std::declval<Value>()...));

    template<kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    struct bit_and
    {
      using type = kumi::result::bit_and_t<T, Value...>;
    };

    //! [bit_and_t]

    //! [bit_or_t]
    template<kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    using bit_or_t = decltype(kumi::bit_or(std::declval<T>(), std::declval<Value>()...));

    template<kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    struct bit_or
    {
      using type = kumi::result::bit_or_t<T, Value...>;
    };

    //! [bit_or_t]

    //! [bit_xor_t]
    template<kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    using bit_xor_t = decltype(kumi::bit_xor(std::declval<T>(), std::declval<Value>()...));

    template<kumi::concepts::product_type T, typename... Value>
    requires((sizeof...(Value) == 0) || (sizeof...(Value) == 1))
    struct bit_xor
    {
      using type = kumi::result::bit_xor_t<T, Value...>;
    };

    //! [bit_xor_t]
  }
}
