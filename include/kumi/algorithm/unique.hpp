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
    template<typename T, typename Set, std::size_t... I>
    KUMI_HIDDEN_ABI consteval auto all_unique_inner_(Set&&, std::index_sequence<I...>) noexcept
    {
      return kumi::function::uniquer(
        std::bool_constant<(Set{}(std::type_identity<kumi::stored_element_t<I, T>>{}) == I)>{}...);
    }

    template<typename T, std::size_t... I>
    KUMI_HIDDEN_ABI consteval auto all_unique_(kumi::_::adl_tag_t, std::index_sequence<I...>) noexcept
    {
      using idx = std::index_sequence<I...>;
      using type = kumi::_::make_multiset_t<idx, kumi::stored_element_t<I, T>...>;

      return all_unique_inner_<T>(type{}, idx{});
    }

    template<typename T, std::size_t... I>
    KUMI_HIDDEN_ABI consteval auto unique_(kumi::_::adl_tag_t, std::index_sequence<I...>) noexcept
    {
      return kumi::function::uniqued(
        std::bool_constant<!std::is_same_v<kumi::stored_element_t<I, T>, kumi::stored_element_t<I + 1, T>>>{}...);
    }
  }

  struct unique_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return KUMI_FWD(t);
      else if constexpr (kumi::concepts::sized_product_type<T, 1>) return KUMI_FWD(t);
      else
      {
        constexpr auto proj = unique_<T>(kumi::_::adl_tag, std::make_index_sequence<kumi::size_v<T> - 1>{});
        return kumi::_::builder(KUMI_FWD(t), proj);
      }
    }
  };

  struct all_unique_t
  {
    template<kumi::concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t) const
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return t;
      else
      {
        constexpr auto proj = all_unique_<T>(kumi::_::adl_tag, std::make_index_sequence<kumi::size_v<T>>{});
        return kumi::_::builder(KUMI_FWD(t), proj);
      }
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_generators

    @var unique
    @brief Callable object returning a product type with consecutive duplicate types removed (pairwise uniqueness).

    On record types, this function operates on the underlying values, not on the fields themselves.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

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

      - A product type containing elements of `t` with consecutive duplicates removed.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/unique.hpp unique_t

    Computes the return type of a call to kumi::unique

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/unique.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/unique.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr unique_t unique{};

  //====================================================================================================================
  /**
    @ingroup kumi_generators

    @var all_unique
    @brief Callable object returning a product type containing the values of the first occurence of each type in `t`.

    On record types, this function operates on the underlying values, not on the fields themselves.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

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

      - A product type built by keeping the first occurrence of every distinct element type in `t`.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/unique.hpp all_unique_t

    Computes the return type of a call to kumi::all_unique

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/all_unique.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/all_unique.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr all_unique_t all_unique{};

  namespace result
  {
    //! [unique_t]
    template<kumi::concepts::product_type T> using unique_t = decltype(kumi::unique(std::declval<T>()));

    template<kumi::concepts::product_type T> struct unique
    {
      using type = kumi::result::unique_t<T>;
    };

    //! [unique_t]

    //! [all_unique_t]
    template<kumi::concepts::product_type T> using all_unique_t = decltype(kumi::all_unique(std::declval<T>()));

    template<kumi::concepts::product_type T> struct all_unique
    {
      using type = kumi::result::all_unique_t<T>;
    };

    //! [all_unique_t]
  }
}
