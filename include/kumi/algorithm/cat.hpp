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
  //====================================================================================================================
  /**
    @ingroup  generators
    @brief    Concatenates product types in a single one

    @param ts Product types to concatenate
    @return   A product type made of all element of all input product types in order.
    @note This function does not take part in overload resolution if the input product types do not follow the same
          semantic. @see concepts::follows_same_semantic

    ## Helper type
    @code
    namespace kumi::result
    {
      template<product_type... Ts> struct cat;

      template<product_type... Ts>
      using cat_t = typename cat<Ts...>::type;
    }
    @endcode

    Computes the return type of a call to kumi::cat

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/cat.cpp
    ### Record:
    @include doc/record/algo/cat.cpp
  **/
  //====================================================================================================================
  template<concepts::product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto cat(Ts&&... ts)
  requires(concepts::follows_same_semantic<Ts...>)
  {
    if constexpr (sizeof...(Ts) == 0) return tuple{};
    else
    {
      constexpr auto pos = _::concatenater(std::index_sequence<size_v<Ts>...>{});
      using res_type = common_product_type_t<std::remove_cvref_t<Ts>...>;

      return [&]<typename T, std::size_t... E, std::size_t... N>(T&& t, std::index_sequence<E...>,
                                                                 std::index_sequence<N...>) {
        using type = builder_make_t<res_type, element_t<E, std::remove_cvref_t<element_t<N, T>>>...>;
        return type{get<E>(get<N>(KUMI_FWD(t)))...};
      }(kumi::forward_as_tuple(KUMI_FWD(ts)...), pos.elt, pos.tpl);
    }
  }

  namespace result
  {
    template<concepts::product_type... Ts> struct cat
    {
      using type = decltype(kumi::cat(std::declval<Ts>()...));
    };

    template<concepts::product_type... Ts> using cat_t = typename cat<Ts...>::type;
  }
}
