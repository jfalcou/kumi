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
  namespace _
  {
    template<std::size_t N, std::size_t... S> constexpr auto digits(std::size_t v) noexcept
    {
      struct { std::size_t data[N]; } digits = {};
      std::size_t shp[] = {S...};
      std::size_t i = 0;

      while(v != 0)
      {
        digits.data[i] = v % shp[i];
        v /= shp[i++];
      }

      return digits;
    }
  }

  // MSVC chokes on the other code for empty calls
#if !defined(KUMI_DOXYGEN_INVOKED)
  [[nodiscard]] constexpr auto cartesian_product() { return kumi::tuple<>{}; }
#endif

  //================================================================================================
  //! @ingroup generators
  //! @brief  Return the Cartesian Product of all elements of its arguments product types
  //! @param  ts Tuples to process
  //! @return a tuple containing all the tuple build from all combination of all ts' elements
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi
  //! {
  //!   template<product_type... Tuples> struct cartesian_product;
  //!
  //!   template<product_type... Tuples>
  //!   using cartesian_product_t = typename cartesian_product<Tuples...>::type;
  //! }
  //! @endcode
  //!
  //! Computes the type returned by a call to kumi::cartesian_product.
  //!
  //! ## Example:
  //! @include doc/cartesian_product.cpp
  //================================================================================================
  template<product_type... Ts>
  [[nodiscard]] constexpr auto cartesian_product(Ts&&... ts)
  {
    auto maps = [&]<std::size_t... I>(auto k, std::index_sequence<I...>)
    {
      constexpr auto dg = _::digits<sizeof...(Ts),kumi::size_v<Ts>...>(k);
      using tuple_t = kumi::tuple<std::tuple_element_t<dg.data[I],std::remove_cvref_t<Ts>>...>;
      return tuple_t{kumi::get<dg.data[I]>(std::forward<Ts>(ts))...};
    };

    return [&]<std::size_t... N>(std::index_sequence<N...>)
    {
      return kumi::make_tuple(maps( kumi::index<N>, std::make_index_sequence<sizeof...(ts)>{})...);
    }(std::make_index_sequence<(kumi::size_v<Ts> * ...)>{});
  }

  namespace result
  {
    template<typename... T> struct cartesian_product
    {
      using type = decltype( kumi::cartesian_product( std::declval<T>()... ) );
    };

    template<typename... T> using cartesian_product_t = typename cartesian_product<T...>::type;
  }
}
