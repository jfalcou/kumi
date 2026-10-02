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
    template<std::size_t K, typename T, std::size_t... I, std::size_t... J, std::size_t... S>
    KUMI_HIDDEN_ABI constexpr auto cartesian_element_(
      kumi::_::adl_tag_t, T&& t, std::index_sequence<I...>, std::index_sequence<J...> j, std::index_sequence<S...>)
    {
      return kumi::_::builder(KUMI_FWD(t), std::index_sequence<((K / S) % I)...>{}, j);
    }

    template<typename T, typename Sizes, typename Elts, typename Strides, std::size_t... I>
    KUMI_HIDDEN_ABI constexpr auto cartesian_product_(
      kumi::_::adl_tag_t, T&& t, Sizes s, Elts e, Strides st, std::index_sequence<I...>)
    {
      return kumi::make_tuple(cartesian_element_<I>(kumi::_::adl_tag, t, s, e, st)...);
    }
  }

  struct cartesian_product_t
  {
    template<kumi::concepts::product_type... Ts>
    [[nodiscard]] KUMI_ABI constexpr auto operator()(Ts&&... ts) const
    requires(kumi::concepts::follows_same_semantic<Ts...>)
    {
      if constexpr (sizeof...(Ts) == 0) return kumi::tuple{};
      else
      {
        using out = std::make_index_sequence<(kumi::size_v<Ts> * ...)>;
        using elts = std::index_sequence_for<Ts...>;
        using sizes = std::index_sequence<kumi::size_v<Ts>...>;
        using strides = kumi::function::cartesian_strides<sizes, elts>;
        return cartesian_product_(kumi::_::adl_tag, kumi::forward_as_tuple(KUMI_FWD(ts)...), sizes{}, elts{}, strides{},
                                  out{});
      }
    }
  };

  //====================================================================================================================
  /**
    @ingroup kumi_generators
    @brief  Callable object returning the Cartesian Product of all elements of its arguments product types

    @var cartesian_product

    @note This function does not take part in overload resolution if the input product types do not follow the same
          semantic. @see concepts::follows_same_semantic

    @qualifier nodiscard
    @qualifier inline
    @qualifier constexpr

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

      - A tuple containing all the product types built from all combination of all ts' elements

    @groupheader{Helper type}

    @snippet include/kumi/algorithm/cartesian_product.hpp cartesian_product_t

    Computes the return type of a call to kumi::cartesian_product

    @groupheader{Examples}

    @tab_begin

    @tab{Tuple}
    @godbolt{doc/tuple/algo/cartesian_product.cpp}

    @tab{Record}
    @godbolt{doc/record/algo/cartesian_product.cpp}

    @tab_end
  **/
  //====================================================================================================================
  KUMI_VARIABLE_ABI constexpr cartesian_product_t cartesian_product{};

  namespace result
  {
    //! [cartesian_product_t]
    template<typename... Ts> using cartesian_product_t = decltype(kumi::cartesian_product(std::declval<Ts>()...));

    template<typename... Ts> struct cartesian_product
    {
      using type = kumi::result::cartesian_product_t<Ts...>;
    };

    //! [cartesian_product_t]
  }
}
