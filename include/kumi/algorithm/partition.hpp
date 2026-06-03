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
  struct splitter_t
  {
    template<typename T, std::size_t... I> KUMI_ABI constexpr auto operator()(T&& t, std::index_sequence<I...>) const
    {
      using res_t = kumi::builder_make_t<T, kumi::element_t<I, T>...>;
      return res_t{get<I>(KUMI_FWD(t))...};
    }
  };

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Partition a product type over a predicate
    @tparam   Pred Compile-time predicate
    @param  t Product type to process
    @return   A tuple containing the product type of all values which types satisfies `Pred` in `t`
              and the product type of all values which types does not satisfy `Pred`.

    On a record type, `Pred` is applied directly to the underlying elements of the fields.

    ## Helper type
    @code
    namespace kumi
    {
      template<template<typename> typename Pred, kumi::product_type T> struct partition;

      template<template<typename> typename Pred, kumi::product_type T>
      using partition_t = typename partition<Pred, T>::type;
    }
    @endcode

    Computes the type returned by a call to kumi::partition.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/partition.cpp
    ### Record:
    @include doc/record/algo/partition.cpp
  **/
  //====================================================================================================================
  template<template<typename> typename Pred> struct partition_t : private splitter_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return kumi::tuple{builder<T>::make(), builder<T>::make()};
      else
      {
        constexpr auto pos = []<std::size_t... I>(std::index_sequence<I...>) {
          return kumi::function::selector(std::bool_constant<Pred<kumi::stored_element_t<I, T>>::value>{}...);
        }(std::make_index_sequence<kumi::size_v<T>>{});

        return kumi::tuple{this->splitter_t::operator()(KUMI_FWD(t), get<0>(pos)),
                           this->splitter_t::operator()(KUMI_FWD(t), get<1>(pos))};
      }
    }
  };

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Filters a product type over a predicate
    @tparam   Pred Compile-time predicate
    @param  t Product type to process
    @return A Product type containing all values of `t` which types satisfies `Pred`.

    On a record type, `Pred` is applied directly to the underlying elements of the fields.

    ## Helper type
    @code
    namespace kumi
    {
      template<template<typename> typename Pred, kumi::product_type T> struct filter;

      template<template<typename> typename Pred, kumi::product_type T>
      using filter_t = typename filter<Pred, T>::type;
    }
    @endcode

    Computes the type returned by a call to kumi::filter.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/filter.cpp
    ### Record:
    @include doc/record/algo/filter.cpp
  **/
  //====================================================================================================================
  template<template<typename> typename Pred> struct filter_t : private splitter_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return builder<T>::make();
      else
      {
        constexpr auto pos = []<std::size_t... I>(std::index_sequence<I...>) {
          return kumi::function::selector(std::bool_constant<Pred<kumi::stored_element_t<I, T>>::value>{}...);
        }(std::make_index_sequence<kumi::size_v<T>>{});

        return this->splitter_t::operator()(KUMI_FWD(t), get<0>(pos));
      }
    }
  };

  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Filters a product type over a predicate
    @tparam   Pred Compile-time predicate
    @param  t Product type to process
    @return A product type containing all values of `t` which types does not satisfy `Pred`.

    On a record type, `Pred` is applied directly to the underlying elements of the fields.

    ## Helper type
    @code
    namespace kumi
    {
      template<template<typename> typename Pred, kumi::product_type T> struct filter_not;

      template<template<typename> typename Pred, kumi::product_type T>
      using filter_not_t = typename filter_not<Pred, T>::type;
    }
    @endcode

    Computes the type returned by a call to kumi::filter_not.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/filter_not.cpp
    ### Record:
    @include doc/record/algo/filter_not.cpp
  **/
  //====================================================================================================================
  template<template<typename> typename Pred> struct filter_not_t : private splitter_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return builder<T>::make();
      else
      {
        constexpr auto pos = []<std::size_t... I>(std::index_sequence<I...>) {
          return function::selector(std::bool_constant<Pred<kumi::stored_element_t<I, T>>::value>{}...);
        }(std::make_index_sequence<kumi::size_v<T>>{});

        return this->splitter_t::operator()(KUMI_FWD(t), get<1>(pos));
      }
    }
  };

  template<template<typename> typename Pred> inline constexpr partition_t<Pred> partition{};

  template<template<typename> typename Pred> inline constexpr filter_t<Pred> filter{};

  template<template<typename> typename Pred> inline constexpr filter_not_t<Pred> filter_not{};

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
    using partition_t = typename kumi::result::partition<Pred, T>::type;

    template<template<typename> typename Pred, kumi::concepts::product_type T>
    using filter_t = typename kumi::result::filter<Pred, T>::type;

    template<template<typename> typename Pred, kumi::concepts::product_type T>
    using filter_not_t = typename kumi::result::filter_not<Pred, T>::type;
  }
}
