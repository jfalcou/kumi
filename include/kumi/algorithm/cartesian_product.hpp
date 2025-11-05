//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/utils/pp_helpers.hpp>
#include <kumi/detail/builder.hpp>

namespace kumi
{

  //================================================================================================
  namespace _
  {
    template<std::size_t N, std::size_t... S> struct digits
    {
      KUMI_ABI constexpr auto operator()(std::size_t v) noexcept
      {
        struct { std::size_t data[N]; } values = {};
        std::size_t shp[N] = {S...};
        std::size_t i = 0;

        while(v != 0)
        {
          values.data[i] = v % shp[i];
          v /= shp[i++];
        }

        return values;
      }
    };
  }
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
  [[nodiscard]] KUMI_ABI constexpr auto cartesian_product( Ts &&... ts )
  requires ((!record_type<Ts> && ...) || (record_type<Ts> && ...))
  {
    using res_type = result::common_product_type_t<std::remove_cvref_t<Ts>...>;
    if constexpr (sizeof...(Ts)==0) return tuple{};
    else
    {
      constexpr auto idx = [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        kumi::_::digits<sizeof...(Ts),kumi::size_v<Ts>...> dgt{};
        using t_t = decltype(dgt(0));
        struct { t_t data[sizeof...(I)]; } that = {dgt(I)...};
        return that;
      }(std::make_index_sequence<(kumi::size_v<Ts> * ...)>{}); 

      auto maps = [&]<std::size_t... I>(auto k, std::index_sequence<I...>)
      {
        auto tps = kumi::forward_as_tuple(ts...);
        using tuple_t = kumi::tuple <raw_element_t< idx.data[k].data[I]
                                              , std::remove_cvref_t<element_t<I,decltype(tps)>>
                                              >...
                                    >;
        if constexpr( record_type<res_type> )
        {
          constexpr auto name = merge_str<
              name_of( as<element_t<idx.data[k].data[I],element_t<I, decltype(tps)>>>{})
          ...>(); 
          return field_capture<name,tuple_t>{ field_value_of( get<idx.data[k].data[I]>(get<I>(tps))) ...};
        }
        else return tuple_t{get<idx.data[k].data[I]>(get<I>(tps))...};
      };

      return [&]<std::size_t... N>(std::index_sequence<N...>)
      {
        std::make_index_sequence<sizeof...(Ts)> ids;
        return _::builder<res_type>::make( maps(index<N>, ids)...);
      }(std::make_index_sequence<(size_v<Ts> * ...)>{});
    }
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
