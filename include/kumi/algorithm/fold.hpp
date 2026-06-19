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
    template<typename F, typename T, typename V, std::size_t... I>
    KUMI_ABI constexpr auto fold_left_(kumi::_::adl_tag_t, F f, T&& t, V v, std::index_sequence<I...>)
    {
      return (kumi::function::foldable{v} >> ... >> kumi::bind_back(f, get<I>(KUMI_FWD(t))))();
    }

    template<typename F, typename T, typename V, std::size_t... I>
    KUMI_ABI constexpr auto fold_right_(kumi::_::adl_tag_t, F f, T&& t, V v, std::index_sequence<I...>)
    {
      return (kumi::bind_front(f, get<I>(KUMI_FWD(t))) << ... << kumi::function::foldable{v})();
    }
  }

  struct fold_left_t
  {
    template<typename Function, kumi::concepts::product_type T, typename Value>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Function f, T&& t, Value init) const
    {
      if constexpr (kumi::concepts::record_type<T>) return (*this)(f, kumi::values_of(KUMI_FWD(t)), init);
      else if constexpr (kumi::concepts::empty_product_type<T>) return init;
      else return fold_left_(kumi::_::adl_tag, f, KUMI_FWD(t), init, std::make_index_sequence<kumi::size_v<T>>{});
    }

    template<typename Function, kumi::concepts::non_empty_product_type T>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Function f, T&& t) const
    {
      if constexpr (kumi::concepts::record_type<T>) return (*this)(f, kumi::values_of(KUMI_FWD(t)));
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
      else
        return fold_left_(kumi::_::adl_tag, f, KUMI_FWD(t), get<0>(KUMI_FWD(t)),
                          kumi::function::shifter(std::integral_constant<std::size_t, 1>{},
                                                  std::make_index_sequence<kumi::size_v<T> - 1>{}));
    }
  };

  struct fold_right_t
  {
    template<typename Function, kumi::concepts::product_type T, typename Value>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Function f, T&& t, Value init) const
    {
      if constexpr (kumi::concepts::record_type<T>) return (*this)(f, kumi::values_of(KUMI_FWD(t)), init);
      else if constexpr (kumi::concepts::empty_product_type<T>) return init;
      else return fold_right_(kumi::_::adl_tag, f, KUMI_FWD(t), init, std::make_index_sequence<kumi::size_v<T>>{});
    }

    template<typename Function, kumi::concepts::non_empty_product_type T>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Function f, T&& t) const
    {
      if constexpr (kumi::concepts::record_type<T>) return (*this)(f, kumi::values_of(KUMI_FWD(t)));
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
      else
        return fold_right_(kumi::_::adl_tag, f, KUMI_FWD(t), get<0>(KUMI_FWD(t)),
                           kumi::function::shifter(std::integral_constant<std::size_t, 1>{},
                                                   std::make_index_sequence<kumi::size_v<T> - 1>{}));
    }
  };

  //====================================================================================================================
  /**
    @ingroup reductions

    @var fold_left
    @brief Callable object computing the generalized combination of all elements using a tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/fold.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, product_type T, typename Value>
      constexpr auto fold_left(Function && f, T && t, Value init);
    @endcode

    @code
      template<typename Function, product_type T>
      constexpr auto fold_left(Function && f, T && t);
    @endcode

    @subgroupheader{Parameters}

      - `f`: Binary callable function to apply
      - `t`: Product type to operate on
      - `v`: Optional initial value of the fold, first element is used otherwise

    @subgroupheader{Return value}

      - The resulting value of the application of the function `f( f( f(init, get<0>(t)), ...), get<N-1>(t))`

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/fold.hpp fold_left_t

    Computes the return type of a call to kumi::fold_left

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/fold_left.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/fold_left.cpp}
  **/
  //====================================================================================================================
  inline constexpr fold_left_t fold_left{};

  //====================================================================================================================
  /**
    @ingroup reductions

    @var fold_right
    @brief Callable object computing the generalized combination of all elements using a non-tail recursive call.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/fold.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<typename Function, product_type T, typename Value>
      constexpr auto fold_right(Function && f, T && t, Value init);
    @endcode

    @code
      template<typename Function, product_type T>
      constexpr auto fold_right(Function && f, T && t);
    @endcode

    @subgroupheader{Parameters}

      - `f`: Binary callable function to apply
      - `t`: Product type to operate on
      - `v`: Optional initial value of the fold, last element is used otherwise

    @subgroupheader{Return value}

      - The resulting value of the application of the function `f(get<0>(t), f(... , f(get<N-1>(t), init))`

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/fold.hpp fold_right_t

    Computes the return type of a call to kumi::fold_right

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/fold_right.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/fold_right.cpp}
  **/
  //====================================================================================================================
  inline constexpr fold_right_t fold_right{};

  namespace result
  {
    //! [fold_left_t]
    template<typename Function, kumi::concepts::product_type T, typename Value = void> struct fold_left
    {
      using type = decltype(kumi::fold_left(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };

    template<typename Function, kumi::concepts::product_type T> struct fold_left<Function, T>
    {
      using type = decltype(kumi::fold_left(std::declval<Function>(), std::declval<T>()));
    };

    template<typename Function, kumi::concepts::product_type T, typename Value = void>
    using fold_left_t = typename kumi::result::fold_left<Function, T, Value>::type;

    //! [fold_left_t]

    //! [fold_right_t]
    template<typename Function, kumi::concepts::product_type T, typename Value = void> struct fold_right
    {
      using type = decltype(kumi::fold_right(std::declval<Function>(), std::declval<T>(), std::declval<Value>()));
    };

    template<typename Function, kumi::concepts::product_type T> struct fold_right<Function, T>
    {
      using type = decltype(kumi::fold_right(std::declval<Function>(), std::declval<T>()));
    };

    template<typename Function, kumi::concepts::product_type T, typename Value = void>
    using fold_right_t = typename kumi::result::fold_right<Function, T, Value>::type;
    //! [fold_right_t]
  }
}
