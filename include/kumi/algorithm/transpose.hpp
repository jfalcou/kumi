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
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        constexpr auto uz = []<typename N>(N const&, auto&& u) {
          return apply([](auto&&... m) { return builder<T>::make(get<N::value>(KUMI_FWD(m))...); }, KUMI_FWD(u));
        };

        return kumi::make_tuple(uz(index<I>, KUMI_FWD(t))...);
      }(std::make_index_sequence<size_v<raw_element_t<0, T>>>());
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
