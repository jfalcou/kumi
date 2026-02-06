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
  namespace _
  {
    template<template<typename> typename Pred, concepts::product_type T> struct selector_t
    {
      KUMI_ABI constexpr auto operator()() const noexcept
      {
        struct
        {
          std::size_t count = {}, cut = {}, t[1 + size_v<T>];
        } that{};

        auto locate = [&]<std::size_t... I>(std::index_sequence<I...>) {
          ((Pred<raw_element_t<I, T>>::value ? (that.t[that.count++] = I) : I), ...);
          that.cut = that.count;
          ((!Pred<raw_element_t<I, T>>::value ? (that.t[that.count++] = I) : I), ...);
        };

        locate(std::make_index_sequence<size_v<T>>{});
        return that;
      }
    };

    template<template<typename> typename Pred, concepts::product_type T>
    inline constexpr selector_t<Pred, T> selector{};
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief  Partition a product type over a predicate
  //! @tparam Pred Compile-time predicate
  //! @param  t Product type to process
  //! @return A tuple containing the product type of all values which types satisfies `Pred`
  //!         and the product type of all values which types does not satisfy `Pred`.
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
  //! ## Examples:
  //! @include doc/tuple/algo/partition.cpp
  //! @include doc/tuple/algo/partition.cpp
  //================================================================================================
  template<template<typename> typename Pred, concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto partition(T&& t) noexcept
  {
    constexpr auto pos = _::selector<Pred, T>();

    auto select = [&]<typename O, std::size_t... I>(O, std::index_sequence<I...>) {
      using type = builder_make_t<T, element_t<pos.t[O::value + I], T>...>;
      return type{get<pos.t[O::value + I]>(KUMI_FWD(t))...};
    };

    return kumi::tuple{select(kumi::index<0>, std::make_index_sequence<pos.cut>{}),
                       select(kumi::index<pos.cut>, std::make_index_sequence<size_v<T> - pos.cut>{})};
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief  Filters a product type over a predicate
  //! @tparam Pred Compile-time predicate
  //! @param  t Product type to process
  //! @return A Product type containing all values which types satisfies `Pred`.
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
  //! @include doc/tuple/algo/filter.cpp
  //! @include doc/tuple/algo/filter.cpp
  //================================================================================================
  template<template<typename> typename Pred, concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto filter(T&& t) noexcept
  {
    constexpr auto pos = _::selector<Pred, T>();
    if constexpr (concepts::sized_product_type<T, 0>) return builder<T>::make();
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using type = builder_make_t<T, element_t<pos.t[I], T>...>;
        return type{get<pos.t[I]>(KUMI_FWD(t))...};
      }(std::make_index_sequence<pos.cut>{});
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief  Filters a product type over a predicate
  //! @tparam Pred Compile-time predicate
  //! @param  t Product type to process
  //! @return A product type containing all values which types does not satisfy `Pred`.
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
  //! @include doc/tuple/algo/filter_not.cpp
  //! @include doc/tuple/algo/filter_not.cpp
  //================================================================================================
  template<template<typename> typename Pred, concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto filter_not(T&& t) noexcept
  {
    constexpr auto pos = _::selector<Pred, T>();
    if constexpr (concepts::sized_product_type<T, 0>) return builder<T>::make();
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        using type = builder_make_t<T, element_t<pos.t[pos.cut + I], T>...>;
        return type{get<pos.t[pos.cut + I]>(KUMI_FWD(t))...};
      }(std::make_index_sequence<size_v<T> - pos.cut>{});
  }

  namespace result
  {
    template<template<typename> typename Pred, kumi::concepts::product_type T> struct partition
    {
      using type = decltype(kumi::partition<Pred>(std::declval<T>()));
    };

    template<template<typename> typename Pred, kumi::concepts::product_type T> struct filter
    {
      using type = decltype(kumi::filter<Pred>(std::declval<T>()));
    };

    template<template<typename> typename Pred, kumi::concepts::product_type T> struct filter_not
    {
      using type = decltype(kumi::filter_not<Pred>(std::declval<T>()));
    };

    template<template<typename> typename Pred, kumi::concepts::product_type T>
    using partition_t = typename partition<Pred, T>::type;

    template<template<typename> typename Pred, kumi::concepts::product_type T>
    using filter_t = typename filter<Pred, T>::type;

    template<template<typename> typename Pred, kumi::concepts::product_type T>
    using filter_not_t = typename filter_not<Pred, T>::type;
  }
}
