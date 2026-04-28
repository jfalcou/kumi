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
    @brief    Computes the maximum value all elements of `t`.
    @param t  Product Type to inspect
    @return   The maximum value of all elements of `t`

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T> struct max;

      template<typename T>
      using max_t = typename max<T>::type;
    }
    @endcode

    Computes the type returned by a call to kumi::max.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/max.cpp
    ### Record:
    @include doc/record/algo/max.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto max(T&& t) noexcept
  {
    if constexpr (kumi::concepts::record_type<T>) return kumi::max(kumi::values_of(KUMI_FWD(t)));
    else if constexpr (kumi::concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
    else
    {
      auto const f = [](auto cur, auto u) { return cur > u ? cur : u; };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (kumi::function::foldable{get<0>(KUMI_FWD(t))} >> ... >> kumi::bind_back(f, get<I + 1>(KUMI_FWD(t))))();
      }(std::make_index_sequence<kumi::size_v<T> - 1>{});
    }
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the maximum value of applications of `f` to all elements of `t`.
    @param t  Product Type to inspect
    @param f  Unary Callable object
    @return   The maximum value of `f` over all elements of `t`

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T, typename F> struct max;

      template<typename T, typename F>
      using max_t = typename max<T, F>::type;
    }
    @endcode

    Computes the type returned by a call to kumi::max.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/max.cpp
    ### Record:
    @include doc/record/algo/max.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::product_type T, typename F> [[nodiscard]] KUMI_ABI constexpr auto max(T&& t, F f) noexcept
  {
    if constexpr (kumi::concepts::record_type<T>) return kumi::max(kumi::values_of(KUMI_FWD(t)), f);
    else if constexpr (kumi::concepts::sized_product_type<T, 1>) return invoke(f, get<0>(KUMI_FWD(t)));
    else
    {
      auto const c = [f](auto cur, auto const& u) { return cur > invoke(f, u) ? cur : invoke(f, u); };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (function::foldable{invoke(f, get<0>(KUMI_FWD(t)))} >> ... >> bind_back(c, get<I + 1>(KUMI_FWD(t))))();
      }(std::make_index_sequence<kumi::size_v<T> - 1>{});
    }
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the maximum value of applications of `f` to all elements of kumi::flatten_all(t).
    @param t  Product Type to inspect
    @param f  Unary Callable object
    @return   The maximum value of `f` over all elements of a flattened version of `t`

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T, typename F> struct max_flat;

      template<typename T, typename F>
      using max_flat_t = typename max_flat<T, F>::type;
    }
    @endcode

    Computes the type returned by a call to kumi::max_flat.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/max_flat.cpp
    ### Record:
    @include doc/record/algo/max_flat.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::product_type T, typename F>
  [[nodiscard]] KUMI_ABI constexpr auto max_flat(T&& t, F f) noexcept
  {
    if constexpr (kumi::concepts::empty_product_type<T>) return 0;
    else if constexpr (kumi::concepts::record_type<T>) return kumi::max_flat(kumi::values_of(KUMI_FWD(t)), f);
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return kumi::max(kumi::make_tuple([&]<typename V>(V&& v) {
          if constexpr (kumi::concepts::product_type<V>) return kumi::max_flat(KUMI_FWD(v), f);
          else return kumi::invoke(f, v);
        }(get<I>(KUMI_FWD(t)))...));
      }(std::make_index_sequence<kumi::size_v<T>>{});
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the minimum value all elements of `t`.
    @param t  Product Type to inspect
    @return   The minimum value of all elements of `t`

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T> struct min;

      template<typename T>
      using min_t = typename min<T>::type;
    }
    @endcode

    Computes the type returned by a call to kumi::min.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/min.cpp
    ### Record:
    @include doc/record/algo/min.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto min(T&& t) noexcept
  {
    if constexpr (kumi::concepts::record_type<T>) return kumi::min(kumi::values_of(KUMI_FWD(t)));
    else if constexpr (kumi::concepts::sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
    else
    {
      auto const f = [](auto cur, auto u) { return cur < u ? cur : u; };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (kumi::function::foldable{get<0>(KUMI_FWD(t))} >> ... >> kumi::bind_back(f, get<I + 1>(KUMI_FWD(t))))();
      }(std::make_index_sequence<kumi::size_v<T> - 1>{});
    }
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the minimum value of applications of `f` to all elements of `t`.
    @param t  Product Type to inspect
    @param f  Unary Callable object
    @return   The minimum value of `f` over all elements of `t`

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T, typename F> struct min;

      template<typename T, typename F>
      using min_t = typename min<T, F>::type;
    }
    @endcode

    Computes the type returned by a call to kumi::min.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/min.cpp
    ### Record:
    @include doc/record/algo/min.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::product_type T, typename F> [[nodiscard]] KUMI_ABI constexpr auto min(T&& t, F f) noexcept
  {
    if constexpr (kumi::concepts::record_type<T>) return kumi::min(kumi::values_of(KUMI_FWD(t)), f);
    else if constexpr (kumi::concepts::sized_product_type<T, 1>) return kumi::invoke(f, get<0>(KUMI_FWD(t)));
    else
    {
      auto const c = [f](auto cur, auto const& u) { return cur < invoke(f, u) ? cur : invoke(f, u); };
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return (function::foldable{kumi::invoke(f, get<0>(KUMI_FWD(t)))} >> ... >>
                kumi::bind_back(c, get<I + 1>(KUMI_FWD(t))))();
      }(std::make_index_sequence<kumi::size_v<T> - 1>{});
    }
  }

  //====================================================================================================================
  /**
    @ingroup  reductions
    @brief    Computes the minimum value of applications of `f` to all elements of kumi::flatten_all(t).
    @param t  Product Type to inspect
    @param f  Unary Callable object
    @return   The minimum value of `f` over all elements of a flattened version of `t`

    ## Helper type
    @code
    namespace kumi
    {
      template<typename T, typename F> struct min_flat;

      template<typename T, typename F>
      using min_flat_t = typename min_flat<T, F>::type;
    }
    @endcode

    Computes the type returned by a call to kumi::min_flat.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/min_flat.cpp
    ### Record:
    @include doc/record/algo/min_flat.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::product_type T, typename F>
  [[nodiscard]] KUMI_ABI constexpr auto min_flat(T&& t, F f) noexcept
  {
    if constexpr (kumi::concepts::empty_product_type<T>) return 0;
    else if constexpr (kumi::concepts::record_type<T>) return kumi::min_flat(kumi::values_of(KUMI_FWD(t)), f);
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return kumi::min(kumi::make_tuple([&]<typename V>(V&& v) {
          if constexpr (kumi::concepts::product_type<V>) return kumi::min_flat(KUMI_FWD(v), f);
          else return kumi::invoke(f, v);
        }(get<I>(KUMI_FWD(t)))...));
      }(std::make_index_sequence<kumi::size_v<T>>{});
  }

  namespace result
  {

    template<typename T, typename F = void> struct max
    {
      using type = decltype(kumi::max(std::declval<T>(), std::declval<F>()));
    };

    template<typename T> struct max<T, void>
    {
      using type = decltype(kumi::max(std::declval<T>()));
    };

    template<typename T, typename F> struct max_flat
    {
      using type = decltype(kumi::max_flat(std::declval<T>(), std::declval<F>()));
    };

    template<typename T, typename F = void> struct min
    {
      using type = decltype(kumi::min(std::declval<T>(), std::declval<F>()));
    };

    template<typename T> struct min<T, void>
    {
      using type = decltype(kumi::min(std::declval<T>()));
    };

    template<typename T, typename F> struct min_flat
    {
      using type = decltype(kumi::min_flat(std::declval<T>(), std::declval<F>()));
    };

    template<typename T, typename F = void> using max_t = typename kumi::result::max<T, F>::type;
    template<typename T, typename F> using max_flat_t = typename kumi::result::max_flat<T, F>::type;

    template<typename T, typename F = void> using min_t = typename kumi::result::min<T, F>::type;
    template<typename T, typename F> using min_flat_t = typename kumi::result::min_flat<T, F>::type;
  }
}
