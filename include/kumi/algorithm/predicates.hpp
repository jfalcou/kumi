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
  //! @ingroup queries
  //! @brief  Checks if unary predicate p returns true for all elements in the value t.
  //! @param  ts Value to process.
  //! @param  p Unary predicate.
  //! @return The evaluation of `p(get<0>(ts)) && ... && p(get<N-1>(ts))` where `N` is the size of `ts`.
  //! ## Example:
  //! @include doc/all_of.cpp
  //================================================================================================
  template<typename Pred, product_type T> [[nodiscard]] KUMI_ABI constexpr auto all_of(T&& ts, Pred p) noexcept
  {
    if constexpr (record_type<T>) return all_of(values_of(KUMI_FWD(ts)), p);
    else if constexpr (sized_product_type<T, 0>) return true;
    else if constexpr (sized_product_type<T, 1>) return p(get<0>(KUMI_FWD(ts)));
    else return kumi::apply([&](auto&&... m) { return (p(m) && ...); }, KUMI_FWD(ts));
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Computes the reduction of a tuple over the `&&` operator.
  //! @param  ts Value to process.
  //! @return The evaluation of `get<0>(ts) && ... && get<N-1>(ts)` where `N` is the size of `ts`.
  //! ## Example:
  //! @include doc/all_of.cpp
  //================================================================================================
  template<product_type T> [[nodiscard]] KUMI_ABI constexpr auto all_of(T&& ts) noexcept
  {
    if constexpr (record_type<T>) return all_of(values_of(KUMI_FWD(ts)));
    else if constexpr (sized_product_type<T, 0>) return true;
    else if constexpr (sized_product_type<T, 1>) return !!get<0>(KUMI_FWD(ts));
    else return kumi::apply([&](auto&&... m) { return (m && ...); }, KUMI_FWD(ts));
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Checks if unary predicate p returns true for any elements in the value t.
  //! @param  ts Value to process.
  //! @param  p Unary predicate.
  //! @return The evaluation of `p(get<0>(ts)) || ... || p(get<N-1>(ts))` where `N` is the size of `ts`.
  //! ## Example:
  //! @include doc/all_of.cpp
  //================================================================================================
  template<typename Pred, product_type T> [[nodiscard]] KUMI_ABI constexpr auto any_of(T&& ts, Pred p) noexcept
  {
    if constexpr (record_type<T>) return any_of(values_of(KUMI_FWD(ts)), p);
    else if constexpr (sized_product_type<T, 0>) return true;
    else if constexpr (sized_product_type<T, 1>) return p(get<0>(KUMI_FWD(ts)));
    else return kumi::apply([&](auto&&... m) { return (p(m) || ...); }, KUMI_FWD(ts));
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Computes the reduction of a tuple over the `||` operator.
  //! @param  ts Value to process.
  //! @return The evaluation of `get<0>(ts) || ... || get<N-1>(ts)` where `N` is the size of `ts`.
  //! ## Example:
  //! @include doc/all_of.cpp
  //================================================================================================
  template<product_type T> [[nodiscard]] KUMI_ABI constexpr auto any_of(T&& ts) noexcept
  {
    if constexpr (record_type<T>) return any_of(values_of(KUMI_FWD(ts)));
    else if constexpr (sized_product_type<T, 0>) return false;
    else if constexpr (sized_product_type<T, 1>) return !!get<0>(KUMI_FWD(ts));
    else return kumi::apply([&](auto&&... m) { return (m || ...); }, KUMI_FWD(ts));
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Checks if unary predicate p returns true for no elements in the value t.
  //! @param  ts Value to process.
  //! @param  p Unary predicate.
  //! @return The evaluation of `!any_of(ts,p)`.
  //! ## Example:
  //! @include doc/none_of.cpp
  //================================================================================================
  template<typename Pred, product_type Tuple> [[nodiscard]] KUMI_ABI constexpr bool none_of(Tuple&& ts, Pred p) noexcept
  {
    return !any_of(KUMI_FWD(ts), p);
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Checks no elements of a tuple are true.
  //! @param  ts Value to process.
  //! @return The evaluation of `!any_of(ts)`.
  //! ## Example:
  //! @include doc/none_of.cpp
  //================================================================================================
  template<product_type Tuple> [[nodiscard]] KUMI_ABI constexpr bool none_of(Tuple&& ts) noexcept
  {
    return !any_of(KUMI_FWD(ts));
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Counts the number of elements of t satisfying predicates p.
  //! @param  ts Value to process
  //! @param  p Unary predicate. p must return a value convertible to `bool` for every element of t.
  //! @return Number of elements satisfying the condition.
  //! ## Example:
  //! @include doc/count_if.cpp
  //================================================================================================
  template<typename Pred, product_type T> [[nodiscard]] KUMI_ABI constexpr std::size_t count_if(T&& ts, Pred p) noexcept
  {
    constexpr std::size_t o = 1ULL;
    constexpr std::size_t z = 0ULL;
    if constexpr (sized_product_type<T, 0>) return z;
    else return kumi::apply([&](auto&&... m) { return ((p(m) ? o : z) + ... + z); }, KUMI_FWD(ts));
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Counts the number of elements of t not equivalent to false.
  //! @param  ts Value to process
  //! @return Number of elements not equivalent to `false`.
  //! ## Example:
  //! @include doc/count.cpp
  //================================================================================================
  template<product_type T> [[nodiscard]] KUMI_ABI constexpr std::size_t count(T&& ts) noexcept
  {
    return count_if(KUMI_FWD(ts), [](auto const& m) { return static_cast<bool>(m); });
  }
}
