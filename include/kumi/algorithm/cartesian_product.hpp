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
  struct cartesian_product_t : private kumi::function::builder_t
  {
    template<kumi::concepts::product_type... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Ts&&... ts) const
    requires(kumi::concepts::follows_same_semantic<Ts...>)
    {
      if constexpr (sizeof...(Ts) == 0) return kumi::tuple{};
      else
      {
        constexpr auto sq = std::make_index_sequence<(kumi::size_v<Ts> * ...)>{};
        constexpr auto idx = kumi::function::cartesian_producer(sq, kumi::index<kumi::size_v<Ts>>...);
        return this->cartesian_product_(kumi::forward_as_tuple(KUMI_FWD(ts)...), idx, sq);
      }
    }

    template<typename T, typename Seq, std::size_t... I>
    KUMI_ABI constexpr auto cartesian_product_(T&& t, Seq&& s, std::index_sequence<I...>) const
    {
      std::make_index_sequence<kumi::size_v<T>> ids{};
      return kumi::make_tuple((this->builder_t::operator()(KUMI_FWD(t), get<I>(s), ids))...);
    }
  };

  //====================================================================================================================
  /**
    @ingroup generators
    @brief  Callable object returning the Cartesian Product of all elements of its arguments product types

    @var cartesian_product

    @note This function does not take part in overload resolution if the input product types do not follow the same
          semantic. @see concepts::follows_same_semantic

    @qualifier nodiscard inline constexpr

    @groupheader{Header file}
    @code
    #include <kumi/algorithm/cartesian_product.hpp>
    @endcode

    @groupheader{Call Signature}

    @code
      template<product_type... Ts>
      [[nodiscard]] constexpr auto cartesian_product(Ts &&... ts);
    @endcode

    @subgroupheader{Parameters}

      - `ts`: Product Types to process

    @subgroupheader{Return value}

    * A tuple containing all the product types built from all combination of all ts' elements


    @groupheader{Helper type}

    @code
    namespace kumi
    {
      template<product_type... Ts> struct cartesian_product;

      template<product_type... Ts>
      using cartesian_product_t = typename cartesian_product<Ts...>::type;
    }
    @endcode

    Computes the return type of a call to kumi::cartesian_product

    @groupheader{Examples}

    @subgroupheader{Tuple}
    @godbolt{doc/tuple/algo/cartesian_product.cpp}

    @subgroupheader{Record}
    @godbolt{doc/record/algo/cartesian_product.cpp}
  **/
  //====================================================================================================================
  inline constexpr cartesian_product_t cartesian_product{};

  namespace result
  {
    template<typename... Ts> struct cartesian_product
    {
      using type = decltype(kumi::cartesian_product(std::declval<Ts>()...));
    };

    template<typename... Ts> using cartesian_product_t = typename kumi::result::cartesian_product<Ts...>::type;
  }
}
