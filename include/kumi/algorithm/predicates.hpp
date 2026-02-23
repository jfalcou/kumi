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
  //! @brief  Checks if a unary predicate p returns true for every element of t.
  //! @param  t Product Type to process.
  //! @param  p Unary predicate.
  //! @return The evaluation of `p(get<0>(t)) && ... && p(get<N-1>(t))` where `N` is the size of `t`.
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/all_of.cpp
  //! @include doc/record/algo/all_of.cpp
  //================================================================================================
  template<typename Pred, concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto all_of(T&& t, Pred p) noexcept
  {
    if constexpr (concepts::record_type<T>) return all_of(values_of(KUMI_FWD(t)), p);
    else if constexpr (concepts::sized_product_type<T, 0>) return true;
    else if constexpr (concepts::sized_product_type<T, 1>) return invoke(p, get<0>(KUMI_FWD(t)));
    else return kumi::apply([&](auto&&... m) { return (invoke(p, m) && ...); }, KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Computes the reduction of a product type over the `&&` operator.
  //! @param  t Product type to process.
  //! @return The evaluation of `get<0>(t) && ... && get<N-1>(t)` where `N` is the size of `t`.
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/all_of.cpp
  //! @include doc/record/algo/all_of.cpp
  //================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto all_of(T&& t) noexcept
  {
    if constexpr (concepts::record_type<T>) return all_of(values_of(KUMI_FWD(t)));
    else if constexpr (concepts::sized_product_type<T, 0>) return true;
    else if constexpr (concepts::sized_product_type<T, 1>) return !!get<0>(KUMI_FWD(t));
    else return kumi::apply([&](auto&&... m) { return (m && ...); }, KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Checks if a unary predicate p returns true for any element of t.
  //! @param  t Product Type to process.
  //! @param  p Unary predicate.
  //! @return The evaluation of `p(get<0>(t)) || ... || p(get<N-1>(t))` where `N` is the size of `t`.
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/all_of.cpp
  //! @include doc/record/algo/all_of.cpp
  //================================================================================================
  template<typename Pred, concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto any_of(T&& t, Pred p) noexcept
  {
    if constexpr (concepts::record_type<T>) return any_of(values_of(KUMI_FWD(t)), p);
    else if constexpr (concepts::sized_product_type<T, 0>) return true;
    else if constexpr (concepts::sized_product_type<T, 1>) return invoke(p, get<0>(KUMI_FWD(t)));
    else return kumi::apply([&](auto&&... m) { return (invoke(p, m) || ...); }, KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Computes the reduction of a product type over the `||` operator.
  //! @param  t Product type to process.
  //! @return The evaluation of `get<0>(t) || ... || get<N-1>(t)` where `N` is the size of `t`.
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/all_of.cpp
  //! @include doc/record/algo/all_of.cpp
  //================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto any_of(T&& t) noexcept
  {
    if constexpr (concepts::record_type<T>) return any_of(values_of(KUMI_FWD(t)));
    else if constexpr (concepts::sized_product_type<T, 0>) return false;
    else if constexpr (concepts::sized_product_type<T, 1>) return !!get<0>(KUMI_FWD(t));
    else return kumi::apply([&](auto&&... m) { return (m || ...); }, KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Checks if a unary predicate p does not returns true for any element in t.
  //! @param  t Product Type to process.
  //! @param  p Unary predicate.
  //! @return The evaluation of `!any_of(t,p)`.
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/none_of.cpp
  //! @include doc/record/algo/none_of.cpp
  //================================================================================================
  template<typename Pred, concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr bool none_of(T&& t, Pred p) noexcept
  {
    return !any_of(KUMI_FWD(t), p);
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Checks if no elements of a product type are true.
  //! @param  t Product type to process.
  //! @return The evaluation of `!none_of(t)`.
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/none_of.cpp
  //! @include doc/record/algo/none_of.cpp
  //================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr bool none_of(T&& t) noexcept
  {
    return !any_of(KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Counts the number of elements of t satisfying predicates p.
  //! @param  t Product Type to process
  //! @param  p Unary predicate. p must return a value convertible to `bool` for every element of t.
  //! @return Number of elements satisfying the condition.
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/count_if.cpp
  //! @include doc/record/algo/count_if.cpp
  //================================================================================================
  template<typename Pred, concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr std::size_t count_if(T&& t, Pred p) noexcept
  {
    constexpr std::size_t o = 1ULL;
    constexpr std::size_t z = 0ULL;
    if constexpr (concepts::sized_product_type<T, 0>) return z;
    else return kumi::apply([&](auto&&... m) { return ((invoke(p, m) ? o : z) + ... + z); }, KUMI_FWD(t));
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Counts the number of elements of t not equivalent to false.
  //! @param  t Product Type to process
  //! @return Number of elements not equivalent to `false`.
  //!
  //! ## Example:
  //! @include doc/tuple/algo/count.cpp
  //! @include doc/record/algo/count.cpp
  //================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr std::size_t count(T&& t) noexcept
  {
    return count_if(KUMI_FWD(t), [](auto const& m) { return static_cast<bool>(m); });
  }
}
