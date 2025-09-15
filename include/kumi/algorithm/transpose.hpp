//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/detail/builder.hpp>

namespace kumi
{
  //================================================================================================
  //! @ingroup generators
  //! @brief Transpose a kumi::product_type of kumi::product_type by shifting elements in their transposed position
  //!
  //! @param t A kumi::product_type to transpose
  //! @return A kumi::product_type containing the transposed elements of t.
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
  //! @include doc/transpose.cpp
  //================================================================================================
  template<product_type T> [[nodiscard]] KUMI_ABI constexpr auto transpose(T && t)
  requires ( _::supports_transpose<T> )
  {
    if constexpr(sized_product_type<T,0>) return t;
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        constexpr auto uz = []<typename N>(N const &, auto &&u) {
          return apply([](auto &&...m){return _::builder<T>::make(get<N::value>(KUMI_FWD(m))...);}, KUMI_FWD(u));
        };

        return _::builder<T>::make(uz(index_t<I> {}, KUMI_FWD(t))...);
      }
      (std::make_index_sequence<size_v<element_t<0,T>>>());
    }
  }

  namespace result
  {
    template<product_type T> struct transpose
    {
      using type = decltype( kumi::transpose( std::declval<T>() ) );
    };

    template<product_type T>
    using transpose_t = typename transpose<T>::type;
  }
}
