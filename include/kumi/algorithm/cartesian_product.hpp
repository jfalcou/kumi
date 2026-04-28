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
    @ingroup    generators
    @brief      Return the Cartesian Product of all elements of its arguments product types
    @param ts   Product types to process
    @return     A tuple containing all the product types built from all combination of all ts'
                elements

    @note This function does not take part in overload resolution if the input product types do not follow the same
          semantic. @see concepts::follows_same_semantic

    ## Helper type
    @code
    namespace kumi
    {
      template<product_type... Ts> struct cartesian_product;

      template<product_type... Ts>
      using cartesian_product_t = typename cartesian_product<Ts...>::type;
    }
    @endcode

    Computes the type returned by a call to kumi::cartesian_product.

    ## Examples:
    ### Tuple:
    @include doc/tuple/algo/cartesian_product.cpp
    ### Record:
    @include doc/record/algo/cartesian_product.cpp
  **/
  //====================================================================================================================
  template<kumi::concepts::product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto cartesian_product(Ts&&... ts)
  requires(kumi::concepts::follows_same_semantic<Ts...>)
  {
    if constexpr (sizeof...(Ts) == 0) return kumi::tuple{};
    else
    {
      using res_type = kumi::common_product_type_t<std::remove_cvref_t<Ts>...>;
      constexpr auto idx =
        kumi::function::cartesian_producer(kumi::index<(kumi::size_v<Ts> * ...)>, kumi::index<kumi::size_v<Ts>>...);

      auto maps = [&]<std::size_t... E, std::size_t... I>(std::index_sequence<E...>, std::index_sequence<I...>) {
        auto tps = kumi::forward_as_tuple(KUMI_FWD(ts)...);
        using res_t = builder_make_t<res_type, element_t<E, element_t<I, decltype(tps)>>...>;
        return res_t{get<E>(get<I>(tps))...};
      };

      return [&]<std::size_t... N>(std::index_sequence<N...>) {
        std::make_index_sequence<sizeof...(Ts)> ids;
        return kumi::make_tuple(maps(get<N>(idx), ids)...);
      }(std::make_index_sequence<(kumi::size_v<Ts> * ...)>{});
    }
  }

  namespace result
  {
    template<typename... Ts> struct cartesian_product
    {
      using type = decltype(kumi::cartesian_product(std::declval<Ts>()...));
    };

    template<typename... Ts> using cartesian_product_t = typename cartesian_product<Ts...>::type;
  }
}
