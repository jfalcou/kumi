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
  //! @ingroup generators
  //! @brief Concatenates product types in a single one
  //!
  //! @param ts Product types to concatenate
  //! @return   A product type made of all element of all input product types in order.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type... Ts> struct cat;
  //!
  //!   template<product_type... Ts>
  //!   using cat_t = typename cat<Ts...>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::cat
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/cat.cpp
  //! @include doc/record/algo/cat.cpp
  //====================================================================================================================
  template<concepts::product_type... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto cat(Ts&&... ts)
  requires(concepts::follows_same_semantic<Ts...>)
  {
    if constexpr (sizeof...(Ts) == 0) return tuple{};
    else
    {
      // count is at least 1 so MSVC don't cry when we use a 0-sized array
      constexpr auto count = (1ULL + ... + size_v<Ts>);
      constexpr auto pos = [&]() {
        struct
        {
          std::size_t t[count], e[count];
        } that{};
        std::size_t k = 0, offset = 0;

        auto locate = [&]<std::size_t... I>(std::index_sequence<I...>) {
          (((that.t[I + offset] = k), (that.e[I + offset] = I)), ...);
          offset += sizeof...(I);
          k++;
        };

        (locate(std::make_index_sequence<size_v<Ts>>{}), ...);

        return that;
      }();

      using res_type = common_product_type_t<std::remove_cvref_t<Ts>...>;

      return [&]<std::size_t... N>(auto&& tuples, std::index_sequence<N...>) {
        using rts = std::remove_cvref_t<decltype(tuples)>;

        using type = builder_make_t<res_type, element_t<pos.e[N], std::remove_cvref_t<element_t<pos.t[N], rts>>>...>;

        return type{get<pos.e[N]>(get<pos.t[N]>(KUMI_FWD(tuples)))...};
      }(kumi::forward_as_tuple(KUMI_FWD(ts)...), std::make_index_sequence<count - 1>{});
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
