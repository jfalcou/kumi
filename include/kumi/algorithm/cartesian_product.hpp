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
  struct cartesian_product_t
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
        return (*this)(kumi::forward_as_tuple(KUMI_FWD(ts)...), idx, sq);
      }
    }

  private:
    template<typename T, typename Seq, std::size_t... I>
    KUMI_ABI constexpr auto operator()(T&& t, Seq&& s, std::index_sequence<I...>) const
    {
      std::make_index_sequence<kumi::size_v<T>> ids{};
      return kumi::make_tuple(((*this)(KUMI_FWD(t), get<I>(s), ids))...);
    }

    template<typename T, std::size_t... E, std::size_t... I>
    KUMI_ABI constexpr auto operator()(T&& t, std::index_sequence<E...>, std::index_sequence<I...>) const
    {
      using U = kumi::common_product_type_t<std::remove_cvref_t<kumi::element_t<I, T>>...>;
      using res_t = kumi::builder_make_t<U, kumi::element_t<E, kumi::element_t<I, T>>...>;
      return res_t{get<E>(get<I>(KUMI_FWD(t)))...};
    }
  };

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
