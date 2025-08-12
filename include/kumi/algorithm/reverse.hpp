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
  //! @brief Reverse elements of a kumi::product_type
  //!
  //! @param  t kumi::product_type to reverse
  //! @return A tuple equivalent to kumi::make_tuple(t[index<size_v<T> - 1 - Idx>]...);
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct reverse;
  //!
  //!   template<product_type Tuple>
  //!   using reverse_t = typename reverse<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::reverse
  //!
  //! ## Example
  //! @include doc/reverse.cpp
  //================================================================================================
  template<product_type Tuple>
  [[nodiscard]] KUMI_ABI constexpr auto reverse(Tuple &&t)
  {
    using base_t = std::remove_cvref_t<Tuple>;
    if constexpr(sized_product_type<Tuple,0>) return base_t{}; 
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return _::builder<base_t>::make(get<(size_v<Tuple> - 1 - I)>(KUMI_FWD(t))...);
      }
      (std::make_index_sequence<size<Tuple>::value>());
    }
  }

  namespace result
  {
    template<product_type Tuple>
    struct reverse
    {
      using type = decltype( kumi::reverse( std::declval<Tuple>() ) );
    };

    template<product_type Tuple>
    using reverse_t = typename reverse<Tuple>::type;
  }
}
