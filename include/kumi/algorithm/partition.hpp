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
    constexpr auto pos = [&]()
    {
      // MSVC is allergic to empty array
      struct { std::size_t count = {}, cut = {}, t[1+kumi::size<T>::value]; } that{};

      auto locate = [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        (( Pred<kumi::raw_element_t<I,T>>::value ? (that.t[that.count++] = I) : I),...);
        that.cut = that.count;
        ((!Pred<kumi::raw_element_t<I,T>>::value ? (that.t[that.count++] = I) : I),...);
      };

      locate(std::make_index_sequence<kumi::size<T>::value>{});

      return that;
    }();

    auto select = [&]<typename O, std::size_t... I>(O, std::index_sequence<I...>)
    {
      using rts = std::remove_cvref_t<decltype(tup)>;
      using type = _::builder_make_t<rts, std::tuple_element_t< pos.t[O::value+I], rts>...>;
      return type{get<pos.t[O::value+I]>(KUMI_FWD(tup))...};
    };

    return kumi::tuple{ 
      select(kumi::index<0>      , std::make_index_sequence<pos.cut>{}),
      select(kumi::index<pos.cut>, std::make_index_sequence<kumi::size<T>::value - pos.cut>{})};
  }

  namespace result
  {
    template<template<typename> typename Pred, kumi::product_type T> struct partition
    {
      using type = decltype( kumi::partition<Pred>( std::declval<T>() ) );
    };

    template<template<typename> typename Pred, kumi::product_type T>
    using partition_t = typename partition<Pred, T>::type;
  }
}
