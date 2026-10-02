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
    template<typename T, typename Seq, std::size_t... I>
    constexpr auto cat_(kumi::_::adl_tag_t, T&& t, Seq inner, std::index_sequence<I...>)
    {
      using outer = kumi::function::cat_index_sequence<
        kumi::function::fill_index_sequence<I, kumi::size_v<kumi::element_t<I, T>>>...>;
      return kumi::_::builder(KUMI_FWD(t), inner, outer{});
    }
  }

  struct cat_t
  {
    template<kumi::concepts::product_type... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Ts&&... ts) const
    requires(kumi::concepts::follows_same_semantic<Ts...>)
    {
      if constexpr (sizeof...(Ts) == 0) return kumi::tuple{};
      else
      {
        using inner = kumi::function::cat_index_sequence<kumi::function::indexes_for<Ts>...>;
        using outer = std::make_index_sequence<sizeof...(Ts)>;
        return cat_(kumi::_::adl_tag, kumi::forward_as_tuple(KUMI_FWD(ts)...), inner{}, outer{});
      }
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_generators

    @var cat
    @brief Callable object concatenating multiple product types into a single one

    @note This function does not take part in overload resolution if the input product types do not follow the same
          semantic. @see concepts::follows_same_semantic

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/cat.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type... Ts>
      constexpr decltype(auto) cat(Ts&&... ts);
    @endcode

    @subgroupheader{Parameters}
      - `ts`: Product types to concatenate

    @subgroupheader{Return value}
      - A product type made of all element of all input product types in order.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/cat.hpp cat_t

    Computes the return type of a call to kumi::cat

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/cat.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/cat.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr cat_t cat{};

  namespace result
  {
    //! [cat_t]
    template<concepts::product_type... Ts> using cat_t = decltype(kumi::cat(std::declval<Ts>()...));

    template<kumi::concepts::product_type... Ts> struct cat
    {
      using type = kumi::result::cat_t<Ts...>;
    };

    //! [cat_t]
  }
}
