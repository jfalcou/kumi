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
  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the maximum value all elements of t.
  //! @param t Tuple to inspect
  //! @return The maximum value of all elements of t
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> struct max;
  //!
  //!   template<typename T>
  //!   using max_t = typename max<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::max.
  //!
  //! ## Example:
  //! @include doc/tuple/algo/max.cpp
  //================================================================================================
  template<product_type T> [[nodiscard]] KUMI_ABI constexpr auto max(T&& t) noexcept
  {
    if constexpr (record_type<T>) return max(values_of(KUMI_FWD(t)));
    else if constexpr (sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
    else
    {
      auto base = get<0>(KUMI_FWD(t));
      return kumi::fold_left([]<typename U>(auto cur, U u) { return cur > u ? cur : u; }, KUMI_FWD(t), base);
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the maximum value of applications of f to all elements of t.
  //! @param t Tuple to inspect
  //! @param f Unary Callable object
  //! @return The maximum value of f over all elements of t
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T, typename F> struct max;
  //!
  //!   template<typename T, typename F>
  //!   using max_t = typename max<T, F>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::max.
  //!
  //! ## Example:
  //! @include doc/tuple/algo/max.cpp
  //================================================================================================
  template<product_type T, typename F> [[nodiscard]] KUMI_ABI constexpr auto max(T&& t, F f) noexcept
  {
    if constexpr (record_type<T>) return max(values_of(KUMI_FWD(t)), f);
    else if constexpr (sized_product_type<T, 1>) return invoke(f, get<0>(KUMI_FWD(t)));
    else
    {
      auto base = f(get<0>(KUMI_FWD(t)));
      return kumi::fold_left([f]<typename U>(auto cur, U const& u) { return cur > invoke(f, u) ? cur : invoke(f, u); },
                             KUMI_FWD(t), base);
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the maximum value of applications of f to all elements of kumi::flatten_all(t).
  //! @param t Tuple to inspect
  //! @param f Unary Callable object
  //! @return The maximum value of f over all elements of a flattened version of t
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T, typename F> struct max_flat;
  //!
  //!   template<typename T, typename F>
  //!   using max_flat_t = typename max_flat<T, F>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::max_flat.
  //!
  //! ## Example:
  //! @include doc/tuple/algo/max_flat.cpp
  //================================================================================================
  template<product_type T, typename F> [[nodiscard]] KUMI_ABI constexpr auto max_flat(T&& t, F f) noexcept
  {
    auto flat_t = kumi::flatten_all(KUMI_FWD(t));
    return max(flat_t, f);
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

    template<typename T, typename F = void> using max_t = typename max<T, F>::type;
    template<typename T, typename F> using max_flat_t = typename max_flat<T, F>::type;
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the minimum value all elements of t.
  //! @param t Tuple to inspect
  //! @return The minimum value of  all elements of t
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T> struct min;
  //!
  //!   template<typename T>
  //!   using min_t = typename min<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::min.
  //!
  //! ## Example:
  //! @include doc/tuple/algo/min.cpp
  //================================================================================================
  template<product_type T> [[nodiscard]] KUMI_ABI constexpr auto min(T&& t) noexcept
  {
    if constexpr (record_type<T>) return min(values_of(KUMI_FWD(t)));
    else if constexpr (sized_product_type<T, 1>) return get<0>(KUMI_FWD(t));
    else
    {
      auto base = get<0>(KUMI_FWD(t));
      return kumi::fold_left([]<typename U>(auto cur, U u) { return cur < u ? cur : u; }, KUMI_FWD(t), base);
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the minimum value of applications of f to all elements of t.
  //! @param t Tuple to inspect
  //! @param f Unary Callable object
  //! @return The minimum value of f over all elements of t
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T, typename F> struct min;
  //!
  //!   template<typename T, typename F>
  //!   using min_t = typename min<T, F>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::min.
  //!
  //! ## Example:
  //! @include doc/tuple/algo/min.cpp
  //================================================================================================
  template<product_type T, typename F> [[nodiscard]] KUMI_ABI constexpr auto min(T&& t, F f) noexcept
  {
    if constexpr (record_type<T>) return min(values_of(KUMI_FWD(t)), f);
    else if constexpr (sized_product_type<T, 1>) return invoke(f, get<0>(KUMI_FWD(t)));
    else
    {
      auto base = f(get<0>(KUMI_FWD(t)));
      return kumi::fold_left([f]<typename U>(auto cur, U const& u) { return cur < invoke(f, u) ? cur : invoke(f, u); },
                             KUMI_FWD(t), base);
    }
  }

  //================================================================================================
  //! @ingroup reductions
  //! @brief Computes the minimum value of applications of f to all elements of kumi::flatten_all(t).
  //! @param t Tuple to inspect
  //! @param f Unary Callable object
  //! @return The minimum value of f over all elements of a flattened version of t
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<typename T, typename F> struct min_flat;
  //!
  //!   template<typename T, typename F>
  //!   using min_flat_t = typename min_flat<T, F>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::min_flat.
  //!
  //! ## Example:
  //! @include doc/tuple/algo/min_flat.cpp
  //================================================================================================
  template<product_type T, typename F> [[nodiscard]] KUMI_ABI constexpr auto min_flat(T&& t, F f) noexcept
  {
    auto flat_t = kumi::flatten_all(KUMI_FWD(t));
    return min(flat_t, f);
  }

  namespace result
  {
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

    template<typename T, typename F = void> using min_t = typename min<T, F>::type;
    template<typename T, typename F> using min_flat_t = typename min_flat<T, F>::type;
  }
}
