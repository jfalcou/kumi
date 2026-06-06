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
  struct unique_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return KUMI_FWD(t);
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return KUMI_FWD(t);
      else
      {
        constexpr auto proj = kumi::function::uniqued(as<T>{});
        return (*this)(KUMI_FWD(t), proj);
      }
    }

    template<typename T, std::size_t... I>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, std::index_sequence<I...>) const
    {
      using res_t = kumi::builder_make_t<T, kumi::element_t<I, T>...>;
      return res_t{get<I>(KUMI_FWD(t))...};
    }
  };

  struct all_unique_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return t;
      else
      {
        constexpr auto proj = [&]<std::size_t... I>(std::index_sequence<I...>) {
          return kumi::function::uniquer(std::type_identity<kumi::stored_element_t<I, T>>{}...);
        }(std::make_index_sequence<kumi::size_v<T>>{});

        return (*this)(KUMI_FWD(t), proj);
      }
    }

    template<typename T, std::size_t... I>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, std::index_sequence<I...>) const
    {
      using res_t = kumi::builder_make_t<T, kumi::element_t<I, T>...>;
      return res_t{get<I>(KUMI_FWD(t))...};
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators

    @var unique
    @brief Callable object returning a product type with consecutive duplicate types removed (pairwise uniqueness).

    On record types, this function operates on the underlying values, not on the fields themselves.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/unique.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto unique(T && t);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to process

    @subgroupheader{Return value}

      * A product type containing elements of `t` with consecutive duplicates removed.

    @groupheader{Helper type}

    @code
    namespace kumi
    {
      template<product_type T> struct unique;

      template<product_type T>
      using unique_t = typename unique<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::unique

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/unique.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/unique.cpp}
  **/
  //====================================================================================================================
  inline constexpr unique_t unique{};

  //====================================================================================================================
  /**
    @ingroup generators

    @var all_unique
    @brief Callable object returning a product type containing the values of the first occurence of each type in `t`.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/unique.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T>
      constexpr auto all_unique(T && t);
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to process

    @subgroupheader{Return value}

      * A product type built by keeping the first occurrence of every distinct element type in `t`.

    @groupheader{Helper type}

    @code
    namespace kumi
    {
      template<product_type T> struct all_unique;

      template<product_type T>
      using all_unique_t = typename all_unique<T>::type;
    }
    @endcode

    Computes the return type of a call to kumi::all_unique

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/all_unique.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/all_unique.cpp}
  **/
  //====================================================================================================================
  inline constexpr all_unique_t all_unique{};

  namespace result
  {
    template<kumi::concepts::product_type T> struct unique
    {
      using type = decltype(kumi::unique(std::declval<T>()));
    };

    template<kumi::concepts::product_type T> struct all_unique
    {
      using type = decltype(kumi::all_unique(std::declval<T>()));
    };

    template<kumi::concepts::product_type T> using unique_t = typename kumi::result::unique<T>::type;

    template<kumi::concepts::product_type T> using all_unique_t = typename kumi::result::all_unique<T>::type;
  }
}
