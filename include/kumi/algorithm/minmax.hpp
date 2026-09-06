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
      template<typename V, typename F, typename C> KUMI_HIDDEN_ABI constexpr auto operator()(V&& v, F f, C c) const
      {
        if constexpr (kumi::concepts::product_type<V>) return c(KUMI_FWD(v), f);
        else return kumi::invoke(f, KUMI_FWD(v));
      }
    };

    KUMI_ENTRY_POINT minmax_case_t minmax_case{};

    template<typename F, typename T, typename V, std::size_t... I>
    KUMI_HIDDEN_ABI constexpr auto minmax_(kumi::_::adl_tag_t, F f, T&& t, V v, std::index_sequence<I...>)
    {
      return (kumi::function::foldable{v} >> ... >> kumi::bind_back(f, get<I + 1>(KUMI_FWD(t))))();
    }

    template<typename M, typename F, typename T, typename V, std::size_t... I>
    KUMI_HIDDEN_ABI constexpr auto map_minmax_(kumi::_::adl_tag_t, M m, F f, T&& t, V v, std::index_sequence<I...>)
    {
      return (kumi::function::foldable{kumi::invoke(m, v)} >> ... >>
              kumi::bind_back(f, kumi::invoke(m, get<I + 1>(KUMI_FWD(t)))))();
    }

    template<typename T, typename V, typename F, typename S, std::size_t... I>
    KUMI_HIDDEN_ABI constexpr auto minmax_flat_(
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
        return minmax_(kumi::_::adl_tag, kumi::function::max, KUMI_FWD(t), get<0>(KUMI_FWD(t)),
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
        return map_minmax_(kumi::_::adl_tag, f, kumi::function::max, KUMI_FWD(t), get<0>(KUMI_FWD(t)),
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
        return minmax_(kumi::_::adl_tag, kumi::function::min, KUMI_FWD(t), get<0>(KUMI_FWD(t)),
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
        return map_minmax_(kumi::_::adl_tag, f, kumi::function::min, KUMI_FWD(t), get<0>(KUMI_FWD(t)),
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
    @ingroup kumi_reductions

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

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/max.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/max.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_ENTRY_POINT max_t max{};

  //====================================================================================================================
  /**
    @ingroup kumi_reductions

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

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/max_flat.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/max_flat.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_ENTRY_POINT max_flat_t max_flat{};

  //====================================================================================================================
  /**
    @ingroup kumi_reductions

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

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/min.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/min.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_ENTRY_POINT min_t min{};

  //====================================================================================================================
  /**
    @ingroup kumi_reductions

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

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/min_flat.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/min_flat.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_ENTRY_POINT min_flat_t min_flat{};

  namespace result
  {
    //! [max_t]
    template<typename T, typename... F>
    requires((sizeof...(F) == 0) || (sizeof...(F) == 1))
    using max_t = decltype(kumi::max(std::declval<T>(), std::declval<F>()...));

    template<typename T, typename... F>
    requires((sizeof...(F) == 0) || (sizeof...(F) == 1))
    struct max
    {
      using type = kumi::result::max_t<T, F...>;
    };

    //! [max_t]

    //! [max_flat_t]
    //
    template<typename T, typename F> using max_flat_t = decltype(kumi::max_flat(std::declval<T>(), std::declval<F>()));

    template<typename T, typename F> struct max_flat
    {
      using type = kumi::result::max_flat_t<T, F>;
    };

    //! [max_flat_t]

    //! [min_t]
    template<typename T, typename... F>
    requires((sizeof...(F) == 0) || (sizeof...(F) == 1))
    using min_t = decltype(kumi::min(std::declval<T>(), std::declval<F>()...));

    template<typename T, typename... F>
    requires((sizeof...(F) == 0) || (sizeof...(F) == 1))
    struct min
    {
      using type = kumi::result::min_t<T, F...>;
    };

    //! [min_t]

    //! [min_flat_t]
    template<typename T, typename F> using min_flat_t = decltype(kumi::min_flat(std::declval<T>(), std::declval<F>()));

    template<typename T, typename F> struct min_flat
    {
      using type = kumi::result::min_flat_t<T, F>;
    };

    //! [min_flat_t]
  }
}
