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
  //! @param  ts Value to process
  //! @param  p Unary predicate. p must return a value convertible to `bool` for every element of t.
  //! @return `true` if all elements of t satisfy p.
  //! ## Example:
  //! @include doc/all_of.cpp
  //================================================================================================
  template<typename Pred, typename T>
  [[nodiscard]] constexpr bool all_of( T const& ts, Pred p) noexcept
  {
    if constexpr( !product_type<T> ) return p(ts);
    else
    {
      if constexpr(size_v<T> == 0) return true;
      else return kumi::apply( [&](auto const&... m) { return (p(m) && ... && true); }, ts );
    }
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Checks if unary predicate p returns true for at least one element in the value t.
  //! @param  ts Value to process
  //! @param  p Unary predicate. p must return a value convertible to `bool` for every element of t.
  //! @return `true` if at least one of elements of t satisfy p.
  //! ## Example:
  //! @include doc/any_of.cpp
  //================================================================================================
  template<typename Pred, typename T>
  [[nodiscard]] constexpr bool any_of( T const& ts, Pred p) noexcept
  {
    if constexpr( !product_type<T> ) return p(ts);
    else
    {
      if constexpr(size_v<T> == 0) return false;
      else return kumi::apply( [&](auto const&... m) { return (p(m) || ... || false); }, ts );
    }
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Checks if unary predicate p returns true for at no elements in the value t.
  //! @param  ts Value to process
  //! @param  p Unary predicate. p must return a value convertible to `bool` for every element of t.
  //! @return `true` if at no elements of t satisfy p.
  //! ## Example:
  //! @include doc/none_of.cpp
  //================================================================================================
  template<typename Pred, typename Tuple>
  [[nodiscard]] constexpr bool none_of( Tuple const& ts, Pred p) noexcept
  {
    return !any_of(ts,p);
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
  template<typename Pred, typename T>
  [[nodiscard]] constexpr std::size_t count_if( T const& ts, Pred p) noexcept
  {
    if constexpr( !product_type<T> ) return p(ts) ? 1 : 0;
    else
    {
      if constexpr(size_v<T> == 0) return 0;
      else return  kumi::apply( [&](auto const&... m) { return ( (p(m)? 1 : 0)+ ... + 0); }, ts );
    }
  }

  //================================================================================================
  //! @ingroup queries
  //! @brief  Counts the number of elements of t not equivalent to false.
  //! @param  ts Value to process
  //! @return Number of elements not equivalent to `false`.
  //! ## Example:
  //! @include doc/count.cpp
  //================================================================================================
  template<typename T>
  [[nodiscard]] constexpr std::size_t count( T const& ts ) noexcept
  {
    return count_if(ts, [](auto const& m) { return static_cast<bool>(m); } );
  }
}
