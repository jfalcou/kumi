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
    struct minmax_case_t
    {
      template<typename V, typename F, typename C> KUMI_ABI constexpr auto operator()(V&& v, F f, C c) const
      {
        if constexpr (kumi::concepts::product_type<V>) return c(KUMI_FWD(v), f);
        else return kumi::invoke(f, KUMI_FWD(v));
      }
    };

    inline constexpr minmax_case_t minmax_case{};

    template<typename F, typename T, typename V, std::size_t... I>
    KUMI_ABI constexpr auto minmax_(kumi::_::adl_tag_t, F f, T&& t, V v, std::index_sequence<I...>)
    {
      return (kumi::function::foldable{v} >> ... >> kumi::bind_back(f, get<I + 1>(KUMI_FWD(t))))();
    }

    template<typename T, typename V, typename F, typename S, std::size_t... I>
    KUMI_ABI constexpr auto minmax_flat_(
      kumi::_::adl_tag_t, T&& t, V visitor, F f, S self, std::index_sequence<I...>) noexcept
    {
      return kumi::make_tuple(visitor(get<I>(KUMI_FWD(t)), f, self)...);
    }
  }

  struct max_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)));
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
      else
      {
        auto const f = [](auto cur, auto u) { return cur > u ? cur : u; };
        return minmax_(kumi::_::adl_tag, f, KUMI_FWD(t), get<0>(KUMI_FWD(t)),
                       std::make_index_sequence<kumi::size_v<T> - 1>{});
      }
    }

    template<kumi::concepts::product_type T, typename F>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, F f) const noexcept
    {
      if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)), f);
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return invoke(f, get<0>(KUMI_FWD(t)));
      else
      {
        auto const c = [f](auto cur, auto const& u) { return cur > invoke(f, u) ? cur : invoke(f, u); };
        return minmax_(kumi::_::adl_tag, c, KUMI_FWD(t), kumi::invoke(f, get<0>(KUMI_FWD(t))),
                       std::make_index_sequence<kumi::size_v<T> - 1>{});
      }
    }
  };

  struct max_flat_t : private kumi::max_t
  {
    template<kumi::concepts::product_type T, typename F>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, F f) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return 0;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)), f);
      else
        return this->max_t::operator()(minmax_flat_(kumi::_::adl_tag, KUMI_FWD(t), kumi::_::minmax_case, f, (*this),
                                                    std::make_index_sequence<kumi::size_v<T>>{}));
    }
  };

  struct min_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)));
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
      else
      {
        auto const f = [](auto cur, auto u) { return cur < u ? cur : u; };
        return minmax_(kumi::_::adl_tag, f, KUMI_FWD(t), get<0>(KUMI_FWD(t)),
                       std::make_index_sequence<kumi::size_v<T> - 1>{});
      }
    }

    template<kumi::concepts::product_type T, typename F>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, F f) const noexcept
    {
      if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)), f);
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return kumi::invoke(f, get<0>(KUMI_FWD(t)));
      else
      {
        auto const c = [f](auto cur, auto const& u) { return cur < invoke(f, u) ? cur : invoke(f, u); };
        return minmax_(kumi::_::adl_tag, c, KUMI_FWD(t), kumi::invoke(f, get<0>(KUMI_FWD(t))),
                       std::make_index_sequence<kumi::size_v<T> - 1>{});
      }
    }
  };

  struct min_flat_t : private kumi::min_t
  {
    template<kumi::concepts::product_type T, typename F>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, F f) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return 0;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)), f);
      else
        return this->min_t::operator()(minmax_flat_(kumi::_::adl_tag, KUMI_FWD(t), kumi::_::minmax_case, f, (*this),
                                                    std::make_index_sequence<kumi::size_v<T>>{}));
    }
  };

  //====================================================================================================================
  /**
    @ingroup reductions

    @var max
    @brief Callable object computing the maximum value of all elements of `t`.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/minmax.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto max(T && t) noexcept;
    @endcode

    @code
      template<product_type T, typename Function>
      constexpr auto max(T && t, Function f) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to inspect
      - `f`: Unary callable object to be invoked

    @subgroupheader{Return value}

      - The maximum value of all elements of `t`

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/minmax.hpp max_t

    Computes the return type of a call to kumi::max

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/max.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/max.cpp}
  **/
  //====================================================================================================================
  inline constexpr max_t max{};

  //====================================================================================================================
  /**
    @ingroup reductions

    @var min
    @brief Callable object computing the maximum value of applications of `f` to all elements of kumi::flatten_all(t).

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/minmax.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, typename Function>
      constexpr auto max_flat(T && t, Function f) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to inspect
      - `f`: Unary callable object to be invoked

    @subgroupheader{Return value}

      - The minimum value of `f` over all elements of a flattened version of `t`

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/minmax.hpp max_flat_t

    Computes the return type of a call to kumi::max_flat

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/max_flat.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/max_flat.cpp}
  **/
  //====================================================================================================================
  inline constexpr max_flat_t max_flat{};

  //====================================================================================================================
  /**
    @ingroup reductions

    @var min
    @brief Callable object computing the minimum value of all elements of `t`.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/minmax.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto min(T && t) noexcept;
    @endcode

    @code
      template<product_type T, typename Function>
      constexpr auto min(T && t, Function f) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to inspect
      - `f`: Unary callable object to be invoked

    @subgroupheader{Return value}

      - The minimum value of all elements of `t`

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/minmax.hpp min_t

    Computes the return type of a call to kumi::min

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/min.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/min.cpp}
  **/
  //====================================================================================================================
  inline constexpr min_t min{};

  //====================================================================================================================
  /**
    @ingroup reductions

    @var min
    @brief Callable object computing the minimum value of applications of `f` to all elements of kumi::flatten_all(t).

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/minmax.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, typename Function>
      constexpr auto min_flat(T && t, Function f) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to inspect
      - `f`: Unary callable object to be invoked

    @subgroupheader{Return value}

      - The minimum value of `f` over all elements of a flattened version of `t`

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/minmax.hpp min_flat_t

    Computes the return type of a call to kumi::min_flat

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/min_flat.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/min_flat.cpp}
  **/
  //====================================================================================================================
  inline constexpr min_flat_t min_flat{};

  namespace result
  {
    //! [max_t]
    template<typename T, typename F = void> struct max
    {
      using type = decltype(kumi::max(std::declval<T>(), std::declval<F>()));
    };

    template<typename T> struct max<T, void>
    {
      using type = decltype(kumi::max(std::declval<T>()));
    };

    template<typename T, typename F = void> using max_t = typename kumi::result::max<T, F>::type;

    //! [max_t]

    //! [max_flat_t]
    template<typename T, typename F> struct max_flat
    {
      using type = decltype(kumi::max_flat(std::declval<T>(), std::declval<F>()));
    };

    template<typename T, typename F> using max_flat_t = typename kumi::result::max_flat<T, F>::type;

    //! [max_flat_t]

    //! [min_t]
    template<typename T, typename F = void> struct min
    {
      using type = decltype(kumi::min(std::declval<T>(), std::declval<F>()));
    };

    template<typename T> struct min<T, void>
    {
      using type = decltype(kumi::min(std::declval<T>()));
    };

    template<typename T, typename F = void> using min_t = typename kumi::result::min<T, F>::type;

    //! [min_t]

    //! [min_flat_t]
    template<typename T, typename F> struct min_flat
    {
      using type = decltype(kumi::min_flat(std::declval<T>(), std::declval<F>()));
    };

    template<typename T, typename F> using min_flat_t = typename kumi::result::min_flat<T, F>::type;
    //! [min_flat_t]
  }
}
