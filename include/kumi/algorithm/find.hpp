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
    template<typename Pred, typename T, std::size_t... I>
    constexpr auto locate_(kumi::_::adl_tag_t, Pred p, T&& t, std::index_sequence<I...>)
    {
      bool checks[] = {kumi::invoke(p, get<I>(KUMI_FWD(t)))...};
      for (std::size_t i = 0; i < kumi::size_v<T>; ++i)
        if (checks[i]) return i;
      return kumi::size_v<T>;
    }
  }

  struct locate_t
  {
    template<typename Pred, kumi::concepts::product_type T>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(T&& t, Pred p) const noexcept
    {
      if constexpr (kumi::concepts::empty_product_type<T>) return 0;
      else if constexpr (kumi::concepts::record_type<T>) return (*this)(kumi::values_of(KUMI_FWD(t)), p);
      else return locate_(kumi::_::adl_tag, p, KUMI_FWD(t), std::make_index_sequence<kumi::size_v<T>>{});
    }
  };

  //====================================================================================================================
  /**
    @ingroup queries

    @var locate
    @brief Callable object Returning the index of a value which type satisfies a given predicate

    On record types, this function operates as if the elements are ordered. The considered order is the order of
    declaration.

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr
    @qualifier noexcept

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/find.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type T, typename Predicate>
      constexpr auto find(T && t, Predicate p) noexcept;
    @endcode

    @subgroupheader{Parameters}

      - `t`: Product Type to process
      - `p`: Unary predicate. p must return a value convertible to `bool` for every element of t.

    @subgroupheader{Return value}

      - The integral index of the element inside `t` that matches the predicate, size_v<T> otherwise.

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/locate.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/locate.cpp}
  **/
  //====================================================================================================================
  inline constexpr locate_t locate{};
}
