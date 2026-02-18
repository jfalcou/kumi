//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

namespace kumi
{
  //================================================================================================
  //! @ingroup generators
  //! @brief Transpose a product type of product types by shifting elements in their transposed
  //!        position always returning a tuple as the external product type.
  //!
  //! @param t Product type to transpose
  //! @return  A tuple containing the transposed elements of t.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct transpose;
  //!
  //!   template<product_type T>
  //!   using transpose_t = typename transpose<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::transpose
  //!
  //! ## Example
  //! @include doc/tuple/algo/transpose.cpp
  //================================================================================================
  template<concepts::product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto transpose(T&& t)
  requires(_::supports_transpose<T>)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return tuple{};
    else if constexpr (concepts::record_type<T>) return transpose(values_of(KUMI_FWD(t)));
    else
    {
      constexpr std::size_t count = size_v<T>;
      constexpr std::size_t size = size_v<element_t<0, T>>;
      constexpr auto pos = _::zipper<count, size>();

      auto maps = [&]<std::size_t... I>(auto k, std::index_sequence<I...>) {
        constexpr auto offset = k * count;
        using type =
          builder_make_t<element_t<0, T>,
                         element_t<pos.e[offset + I], std::remove_cvref_t<element_t<pos.t[offset + I], T>>>...>;
        return type{get<pos.e[offset + I]>(get<pos.t[offset + I]>(KUMI_FWD(t)))...};
      };

      return [&]<std::size_t... N>(std::index_sequence<N...>) {
        std::make_index_sequence<count> ids;
        return kumi::make_tuple(maps(index<N>, ids)...);
      }(std::make_index_sequence<size>{});
    }
  }

  namespace result
  {
    template<concepts::product_type T> struct transpose
    {
      using type = decltype(kumi::transpose(std::declval<T>()));
    };

    template<concepts::product_type T> using transpose_t = typename transpose<T>::type;
  }
}
