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
  namespace _
  {
    template<typename T, template<typename> typename Pred, std::size_t... I>
    KUMI_HIDDEN_ABI consteval auto select_(kumi::_::adl_tag_t, std::index_sequence<I...>) noexcept
    {
      return kumi::function::selector(std::bool_constant<Pred<kumi::stored_element_t<I, T>>::value>{}...);
    }
  }

  template<template<typename> typename Pred> struct partition_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return kumi::tuple{builder<T>::make(), builder<T>::make()};
      else
      {
        constexpr auto pos = select_<T, Pred>(kumi::_::adl_tag, std::make_index_sequence<kumi::size_v<T>>{});
        return kumi::tuple{kumi::_::builder(KUMI_FWD(t), get<0>(pos)), kumi::_::builder(KUMI_FWD(t), get<1>(pos))};
      }
    }
  };

  template<template<typename> typename Pred> struct filter_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return builder<T>::make();
      else
      {
        constexpr auto pos = select_<T, Pred>(kumi::_::adl_tag, std::make_index_sequence<kumi::size_v<T>>{});
        return kumi::_::builder(KUMI_FWD(t), get<0>(pos));
      }
    }
  };

  template<template<typename> typename Pred> struct filter_not_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return builder<T>::make();
      else
      {
        constexpr auto pos = select_<T, Pred>(kumi::_::adl_tag, std::make_index_sequence<kumi::size_v<T>>{});
        return kumi::_::builder(KUMI_FWD(t), get<1>(pos));
      }
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators

    @var partition
    @brief Callable object partitionning a product type over a predicate

    On a record type, `Pred` is applied directly to the underlying elements of the fields.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/partition.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto partition<Pred>(T && t) noexcept;
    @endcode

    @subgroupheader{Template Parameters}

      - `Pred`:  Compile-time predicate

    @subgroupheader{Parameters}

      - `t`: Product Type to process

    @subgroupheader{Return value}

      - A tuple containing the product type of all values which types satisfies `Pred` in `t`
              and the product type of all values which types does not satisfy `Pred`.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/partition.hpp partition_t

    Computes the return type of a call to kumi::partition

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/partition.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/partition.cpp}

    @tab_end
  **/
  //====================================================================================================================
  template<template<typename> typename Pred> inline constexpr partition_t<Pred> partition{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var filter
    @brief Callable object filtering a product type over a predicate

    On a record type, `Pred` is applied directly to the underlying elements of the fields.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/partition.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto filter<Pred>(T && t) noexcept;
    @endcode

    @subgroupheader{Template Parameters}

      - `Pred`:  Compile-time predicate

    @subgroupheader{Parameters}

      - `t`: Product Type to process

    @subgroupheader{Return value}

      - A Product type containing all values of `t` which types satisfies `Pred`.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/partition.hpp filter_t

    Computes the return type of a call to kumi::filter

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/filter.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/filter.cpp}

    @tab_end
  **/
  //====================================================================================================================
  template<template<typename> typename Pred> inline constexpr filter_t<Pred> filter{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var filter_not
    @brief Callable object filtering a product type over a predicate

    On a record type, `Pred` is applied directly to the underlying elements of the fields.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/partition.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto filter_not<Pred>(T && t) noexcept;
    @endcode

    @subgroupheader{Template Parameters}

      - `Pred`:  Compile-time predicate

    @subgroupheader{Parameters}

      - `t`: Product Type to process

    @subgroupheader{Return value}

      - A Product type containing all values of `t` which types does not satisfy `Pred`.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/partition.hpp filter_not_t

    Computes the return type of a call to kumi::filter_not

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/filter_not.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/filter_not.cpp}

    @tab_end
  **/
  //====================================================================================================================
  template<template<typename> typename Pred> inline constexpr filter_not_t<Pred> filter_not{};

  namespace result
  {
    //! [partition_t]
    template<template<typename> typename Pred, kumi::concepts::product_type T> struct partition
    {
      using type = decltype(kumi::partition<Pred>(std::declval<T>()));
    };

    template<template<typename> typename Pred, kumi::concepts::product_type T>
    using partition_t = typename kumi::result::partition<Pred, T>::type;

    //! [partition_t]

    //! [filter_t]
    template<template<typename> typename Pred, kumi::concepts::product_type T> struct filter
    {
      using type = decltype(kumi::filter<Pred>(std::declval<T>()));
    };

    template<template<typename> typename Pred, kumi::concepts::product_type T>
    using filter_t = typename kumi::result::filter<Pred, T>::type;

    //! [filter_t]

    //! [filter_not_t]
    template<template<typename> typename Pred, kumi::concepts::product_type T> struct filter_not
    {
      using type = decltype(kumi::filter_not<Pred>(std::declval<T>()));
    };

    template<template<typename> typename Pred, kumi::concepts::product_type T>
    using filter_not_t = typename kumi::result::filter_not<Pred, T>::type;
    //! [filter_not_t]
  }
}
