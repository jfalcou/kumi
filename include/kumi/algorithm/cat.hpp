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
  struct cat_t
  {
    template<kumi::concepts::product_type... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Ts&&... ts) const
    requires(kumi::concepts::follows_same_semantic<Ts...>)
    {
      if constexpr (sizeof...(Ts) == 0) return kumi::tuple{};
      else
      {
        constexpr auto pos = kumi::function::concatenater(std::index_sequence<kumi::size_v<Ts>...>{});
        return kumi::function::builder(kumi::forward_as_tuple(KUMI_FWD(ts)...), get<1>(pos), get<0>(pos));
      }
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators

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
      constexpr decltype(auto) cat(Ts... && t);
    @endcode

    @subgroupheader{Parameters}
      - `ts`: Product types to concatenate

    @subgroupheader{Return value}
      - A product type made of all element of all input product types in order.

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/cat.hpp cat_t

    Computes the return type of a call to kumi::cat

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/cat.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/cat.cpp}
  **/
  //====================================================================================================================
  inline constexpr cat_t cat{};

  namespace result
  {
    //! [cat_t]
    template<kumi::concepts::product_type... Ts> struct cat
    {
      using type = decltype(kumi::cat(std::declval<Ts>()...));
    };

    template<concepts::product_type... Ts> using cat_t = typename kumi::result::cat<Ts...>::type;
    //! [cat_t]
  }
}
