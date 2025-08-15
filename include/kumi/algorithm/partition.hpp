//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/detail/builder.hpp>

namespace kumi
{
  namespace _
  {
    template<template<typename> typename Pred, product_type T> struct selector_t
    {
      KUMI_ABI constexpr auto operator()() const noexcept 
      {
        struct { std::size_t count = {}, cut = {}, t[1+kumi::size<T>::value]; } that{};

        auto locate = [&]<std::size_t... I>(std::index_sequence<I...>)
        {
          (( Pred<kumi::raw_element_t<I,T>>::value ? (that.t[that.count++] = I) : I),...);
          that.cut = that.count;
          ((!Pred<kumi::raw_element_t<I,T>>::value ? (that.t[that.count++] = I) : I),...);
        };

        locate(std::make_index_sequence<kumi::size<T>::value>{});
        return that;
      }
    };

    template<template<typename> typename Pred, product_type T>
    inline constexpr selector_t<Pred, T> selector{};
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief  Partition a tuple over a predicate
  //! @tparam Pred Compile-time predicate
  //! @param  tup Tuple to process
  //! @return A tuple containing the tuple of all values which types satisfies `Pred` and the
  //!         the tuple of all values which types does not satisfy `Pred`.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<template<typename> typename Pred, kumi::product_type T> struct partition;
  //!
  //!   template<template<typename> typename Pred, kumi::product_type T>
  //!   using partition_t = typename partition<Pred, T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::partition.
  //!
  //! ## Example:
  //! @include doc/partition.cpp
  //================================================================================================
  template<template<typename> typename Pred, kumi::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto partition(T&& tup) noexcept
  {
    constexpr auto pos = kumi::_::selector<Pred, T>();

    auto select = [&]<typename O, std::size_t... I>(O, std::index_sequence<I...>)
    {
      using rts = std::remove_cvref_t<T>;
      using type = _::builder_make_t<rts, std::tuple_element_t< pos.t[O::value+I], rts>...>;
      return type{get<pos.t[O::value+I]>(KUMI_FWD(tup))...};
    };

    return kumi::tuple{ 
      select(kumi::index<0>      , std::make_index_sequence<pos.cut>{}),
      select(kumi::index<pos.cut>, std::make_index_sequence<kumi::size_v<T> - pos.cut>{})};
  }
    
  //================================================================================================
  //! @ingroup generators
  //! @brief  Filters a tuple over a predicate
  //! @tparam Pred Compile-time predicate
  //! @param  tup Tuple to process
  //! @return A tuple containing all values which types satisfies `Pred`.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<template<typename> typename Pred, kumi::product_type T> struct filter;
  //!
  //!   template<template<typename> typename Pred, kumi::product_type T>
  //!   using filter_t = typename filter<Pred, T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::filter.
  //!
  //! ## Example:
  //! @include doc/filter.cpp
  //================================================================================================
  template<template<typename> typename Pred, kumi::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto filter(T&& tup) noexcept
  {
    constexpr auto pos = kumi::_::selector<Pred, T>();
    if constexpr ( sized_product_type<T, 0>) return tuple{};
    else return [&]<std::size_t...I>(std::index_sequence<I...>)
    {
        using rts = std::remove_cvref_t<T>;
        using type = _::builder_make_t<rts, std::tuple_element_t<pos.t[I], rts>...>;
        return type{get<pos.t[I]>(KUMI_FWD(tup))...};
    }(std::make_index_sequence<pos.cut>{});
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief  Filters a tuple over a predicate
  //! @tparam Pred Compile-time predicate
  //! @param  tup Tuple to process
  //! @return A tuple containing all values which types does not satisfy `Pred`.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<template<typename> typename Pred, kumi::product_type T> struct filter_not;
  //!
  //!   template<template<typename> typename Pred, kumi::product_type T>
  //!   using filter_not_t = typename filter_not<Pred, T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::filter_not.
  //!
  //! ## Example:
  //! @include doc/filter_not.cpp
  //================================================================================================
  template<template<typename> typename Pred, kumi::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto filter_not(T&& tup) noexcept
  {
    constexpr auto pos = kumi::_::selector<Pred, T>();
    if constexpr ( sized_product_type<T, 0> ) return tuple{};
    else return [&]<std::size_t...I>(std::index_sequence<I...>)
    {
        using rts = std::remove_cvref_t<T>;
        using type = _::builder_make_t<rts, std::tuple_element_t<pos.t[pos.cut+I], rts>...>;
        return type{get<pos.t[pos.cut+I]>(KUMI_FWD(tup))...};
    }(std::make_index_sequence<kumi::size_v<T> - pos.cut>{});
  }

  namespace result
  {
    template<template<typename> typename Pred, kumi::product_type T> struct partition
    {
      using type = decltype( kumi::partition<Pred>( std::declval<T>() ) );
    };
    
    template<template<typename> typename Pred, kumi::product_type T> struct filter 
    {
      using type = decltype( kumi::filter<Pred>( std::declval<T>() ) );
    };
      
    template<template<typename> typename Pred, kumi::product_type T> struct filter_not 
    {
      using type = decltype( kumi::filter_not<Pred>( std::declval<T>() ) );
    };

    template<template<typename> typename Pred, kumi::product_type T>
    using partition_t = typename partition<Pred, T>::type;

    template<template<typename> typename Pred, kumi::product_type T>
    using filter_t = typename filter<Pred, T>::type;

    template<template<typename> typename Pred, kumi::product_type T>
    using filter_not_t = typename filter_not<Pred, T>::type;
  }
}
