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
  //! @brief Reverse elements of a product type
  //!
  //! On record types, this function operates structurally and extract elements as if they were ordered. The considered
  //! order is the order of declaration.
  //!
  //! @param  t The product type to reverse
  //! @return A product type equivalent to product_type(t[index<size_v<T> - 1 - Idx>]...);
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type T> struct reverse;
  //!
  //!   template<product_type T>
  //!   using reverse_t = typename reverse<T>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::reverse
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/reverse.cpp
  //! @include doc/record/algo/reverse.cpp
  //====================================================================================================================
  template<concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto reverse(T&& t)
  {
    if constexpr (concepts::sized_product_type<T, 0>) return builder<T>::make();
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return builder<T>::make(get<(size_v<T> - 1 - I)>(KUMI_FWD(t))...);
      }(std::make_index_sequence<size<T>::value>());
    }
  }

  namespace result
  {
    template<concepts::product_type T> struct reverse
    {
      using type = decltype(kumi::reverse(std::declval<T>()));
    };

    template<concepts::product_type T> using reverse_t = typename reverse<T>::type;
  }
}
