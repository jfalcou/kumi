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
  [[nodiscard]] KUMI_ABI constexpr auto zip(T0 &&t0, Ts &&...ts)
  requires ( compatible_product_types<T0, Ts...> )
  {
    return kumi::map( [](auto const &m0, auto const &...ms) 
                    { 
                        return kumi::make_tuple(m0, ms...);
                    }
                    , KUMI_FWD(t0),KUMI_FWD(ts)...
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
