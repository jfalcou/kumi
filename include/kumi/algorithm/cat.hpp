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
        return (*this)(kumi::forward_as_tuple(KUMI_FWD(ts)...), std::make_index_sequence<sizeof...(Ts)>{}, get<1>(pos),
                       get<0>(pos));
      }
    }

  private:
    template<typename T, std::size_t... Elt, std::size_t... E, std::size_t... I>
    KUMI_ABI constexpr auto operator()(T&& t,
                                       std::index_sequence<Elt...>,
                                       std::index_sequence<E...>,
                                       std::index_sequence<I...>) const
    {
      using U = kumi::common_product_type_t<std::remove_cvref_t<kumi::element_t<Elt, T>>...>;
      using res_t = kumi::builder_make_t<U, kumi::element_t<E, kumi::element_t<I, T>>...>;
      return res_t{get<E>(get<I>(KUMI_FWD(t)))...};
    }
  };

  inline constexpr cat_t cat{};

  namespace result
  {
    template<kumi::concepts::product_type... Ts> struct cat
    {
      using type = decltype(kumi::cat(std::declval<Ts>()...));
    };

    template<concepts::product_type... Ts> using cat_t = typename kumi::result::cat<Ts...>::type;
  }
}
