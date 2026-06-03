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
    @ingroup  queries
    @brief    Checks if a unary predicate p returns true for every element of t.
    @param  t Product Type to process.
    @param  p Unary predicate.
    @return   The evaluation of `p(get<0>(t)) && ... && p(get<N-1>(t))` where `N` is the size of `t`.

    On a record type, the function operates on the underlying elements of the fields.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/all_of.cpp
    ### Record:
    @include doc/record/algo/all_of.cpp
  **/
  //====================================================================================================================
  struct all_of_t
  {
    template<typename Pred, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Pred p) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return true;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)), p);
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return kumi::invoke(p, get<0>(KUMI_FWD(t)));
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return (kumi::invoke(p, get<I>(KUMI_FWD(t))) && ...);
        }(std::make_index_sequence<kumi::size_v<T>>{});
    }

    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return true;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)));
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return !!get<0>(KUMI_FWD(t));
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return (get<I>(KUMI_FWD(t)) && ...);
        }(std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup  queries
    @brief    Computes the reduction of a product type over the `&&` operator.
    @param  t Product type to process.
    @return   The evaluation of `get<0>(t) && ... && get<N-1>(t)` where `N` is the size of `t`.

    On a record type, the function operates on the underlying elements of the fields.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/all_of.cpp
    ### Record:
    @include doc/record/algo/all_of.cpp
  **/
  //====================================================================================================================

  //====================================================================================================================
  /**
    @ingroup  queries
    @brief    Checks if a unary predicate p returns true for any element of t.
    @param  t Product Type to process.
    @param  p Unary predicate.
    @return   The evaluation of `p(get<0>(t)) || ... || p(get<N-1>(t))` where `N` is the size of `t`.

    On a record type, the function operates on the underlying elements of the fields.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/any_of.cpp
    ### Record:
    @include doc/record/algo/any_of.cpp
  **/
  //====================================================================================================================
  struct any_of_t
  {
    template<typename Pred, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Pred p) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return true;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)), p);
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return kumi::invoke(p, get<0>(KUMI_FWD(t)));
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return (kumi::invoke(p, get<I>(KUMI_FWD(t))) || ...);
        }(std::make_index_sequence<kumi::size_v<T>>{});
    }

    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return false;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)));
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return !!get<0>(KUMI_FWD(t));
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return (get<I>(KUMI_FWD(t)) || ...);
        }(std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup  queries
    @brief    Computes the reduction of a product type over the `||` operator.
    @param  t Product type to process.
    @return   The evaluation of `get<0>(t) || ... || get<N-1>(t)` where `N` is the size of `t`.

    On a record type, the function operates on the underlying elements of the fields.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/any_of.cpp
    ### Record:
    @include doc/record/algo/any_of.cpp
  **/
  //====================================================================================================================

  //====================================================================================================================
  /**
    @ingroup  queries
    @brief    Checks if a unary predicate p does not returns true for any element in t.
    @param  t Product Type to process.
    @param  p Unary predicate.
    @return   The evaluation of `!any_of(t,p)`.

    On a record type, the function operates on the underlying elements of the fields.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/none_of.cpp
    ### Record:
    @include doc/record/algo/none_of.cpp
  **/
  //====================================================================================================================
  struct none_of_t : private kumi::any_of_t
  {
    template<typename Pred, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr bool operator()(T&& t, Pred p) const noexcept
    {
      return !kumi::any_of_t::operator()(KUMI_FWD(t), p);
    }

    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr bool operator()(T&& t) const noexcept
    {
      return !kumi::any_of_t::operator()(KUMI_FWD(t));
    }
  };

  //====================================================================================================================
  /**
    @ingroup queries
    @brief    Checks if no elements of a product type are true.
    @param  t Product type to process.
    @return   The evaluation of `!none_of(t)`.

    On a record type, the function operates on the underlying elements of the fields.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/none_of.cpp
    ### Record:
    @include doc/record/algo/none_of.cpp
  **/
  //====================================================================================================================

  //====================================================================================================================
  /**
    @ingroup  queries
    @brief    Counts the number of elements of t satisfying predicates p.
    @param  t Product Type to process
    @param  p Unary predicate. p must return a value convertible to `bool` for every element of t.
    @return   Number of elements satisfying the condition.

    On a record type, the function operates on the underlying elements of the fields.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/count_if.cpp
    ### Record:
    @include doc/record/algo/count_if.cpp
  **/
  //====================================================================================================================
  struct count_if_t
  {
    template<typename Pred, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr std::size_t operator()(T&& t, Pred p) const noexcept
    {
      constexpr std::size_t o = 1ULL;
      constexpr std::size_t z = 0ULL;
      if constexpr (kumi::concepts::empty_product_type<T>) return z;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(values_of(KUMI_FWD(t)), p);
      else
        return [&]<std::size_t... I>(std::index_sequence<I...>) {
          return ((kumi::invoke(p, get<I>(KUMI_FWD(t))) ? o : z) + ... + z);
        }(std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup  queries
    @brief    Counts the number of elements of t not equivalent to false.
    @param  t Product Type to process
    @return   Number of elements not equivalent to `false`.

    On a record type, the function operates on the underlying elements of the fields.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/count.cpp
    ### Record:
    @include doc/record/algo/count.cpp
  **/
  //====================================================================================================================
  struct count_t : private kumi::count_if_t
  {
    template<kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr std::size_t operator()(T&& t) const noexcept
    {
      return kumi::count_if_t::operator()(KUMI_FWD(t), [](auto const& m) { return static_cast<bool>(m); });
    }
  };

  inline constexpr all_of_t all_of{};
  inline constexpr any_of_t any_of{};
  inline constexpr none_of_t none_of{};
  inline constexpr count_if_t count_if{};
  inline constexpr count_t count{};
}
