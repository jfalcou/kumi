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
  //! @brief Transpose a tuple of tuples by shifting elements in their transposed position
  //!
  //! @param t Tuple to transpose
  //! @return A tuple containing the transposed elements of t.
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct transpose;
  //!
  //!   template<product_type Tuple>
  //!   using transpose_t = typename transpose<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::transpose
  //!
  //! ## Example
  //! @include doc/transpose.cpp
  //================================================================================================
  template<product_type Tuple> [[nodiscard]] constexpr auto transpose(Tuple const &t)
  {
    if constexpr(sized_product_type<Tuple,0>) return t;
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        constexpr auto uz = []<typename N>(N const &, auto const &u) {
          return apply([](auto const &...m) { return kumi::make_tuple(get<N::value>(m)...); }, u);
        };

        return kumi::make_tuple(uz(index_t<I> {}, t)...);
      }
      (std::make_index_sequence<size<element_t<0,Tuple>>::value>());
    }
  }

  namespace result
  {
    template<product_type Tuple> struct transpose
    {
      using type = decltype( kumi::transpose( std::declval<Tuple>() ) );
    };

    template<product_type Tuple>
    using transpose_t = typename transpose<Tuple>::type;
  }
}
