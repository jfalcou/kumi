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
  //! @brief Constructs a tuple where the ith element is the tuple of all ith elements of ts...
  //!
  //! @param t0 Tuple to convert
  //! @param ts Tuples to convert
  //! @return The tuple of all combination of elements from t0, ts...
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple> struct zip;
  //!
  //!   template<product_type Tuple>
  //!   using zip_t = typename zip<Tuple>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::zip
  //!
  //! ## Example
  //! @include doc/zip.cpp
  //================================================================================================
  template<product_type T0, sized_product_type<size_v<T0>>... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto zip(T0 const &t0, Ts const &...ts)
  {
    using res_type = kumi::common_product_type_t<std::remove_cvref_t<T0>, std::remove_cvref_t<Ts>...>;

    return kumi::map( [](auto const &m0, auto const &...ms) 
                    { 
                        return builder<res_type>::make(m0, ms...);
                    }
                    , t0,ts...
                    );
  }

  namespace result
  {
    template<product_type T0, product_type... Ts>
    struct zip
    {
      using type = decltype( kumi::zip( std::declval<T0>(), std::declval<Ts>()... ) );
    };

    template<product_type T0, product_type... Ts>
    using zip_t = typename zip<T0,Ts...>::type;
  }
}
