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
  //! @return A kumi::product_type equivalent to (t[index<size_v<T> - 1 - Idx>]...);
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
  //! ## Example
  //! @include doc/reverse.cpp
  //================================================================================================
  template<product_type T>
  [[nodiscard]] KUMI_ABI constexpr auto reverse(T &&t)
  {
    if constexpr(sized_product_type<T,0>) return _::builder<T>::make(); 
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        return _::builder<T>::make(get<(size_v<T> - 1 - I)>(KUMI_FWD(t))...);
      }
      (std::make_index_sequence<size<T>::value>());
    }
  }

  namespace result
  {
    template<product_type T>
    struct reverse
    {
      using type = decltype( kumi::reverse( std::declval<T>() ) );
    };

    template<product_type T>
    using reverse_t = typename reverse<T>::type;
  }
}
