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
  //! @brief Concatenates tuples in a single one
  //!
  //! @param ts Tuples to concatenate
  //! @return   A tuple made of all element of all input tuples in order
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type... Tuples> struct cat;
  //!
  //!   template<product_type... Tuples>
  //!   using cat_t = typename cat<Tuples...>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::cat
  //!
  //! ## Examples
  //! @include doc/cat.cpp
  //! @include doc/record/cat.cpp
  //================================================================================================
  template<product_type... Tuples>
  [[nodiscard]] KUMI_ABI constexpr auto cat(Tuples&&... ts)
  requires ( (!record_type<Tuples> && ... ) || (record_type<Tuples> && ...) )
  {
    if constexpr(sizeof...(Tuples) == 0) return tuple{};
    else
    {
      // count is at least 1 so MSVC don't cry when we use a 0-sized array
      constexpr auto count = (1ULL + ... + size_v<Tuples>);
      constexpr auto pos = [&]()
      {
        struct { std::size_t t[count],e[count]; } that{};
        std::size_t k = 0, offset = 0;

        auto locate = [&]<std::size_t... I>(std::index_sequence<I...>)
        {
          (((that.t[I+offset] = k),(that.e[I+offset] = I)),...);
          offset += sizeof...(I);
          k++;
        };

        (locate(std::make_index_sequence<size_v<Tuples>>{}),...);

        return that;
      }();
    
      using res_type = result::common_product_type_t<std::remove_cvref_t<Tuples>...>;

      return [&]<std::size_t... N>(auto&& tuples, std::index_sequence<N...>)
      {
        using rts  = std::remove_cvref_t<decltype(tuples)>;
        
        using type = _::builder_make_t<res_type
                        , element_t<pos.e[N]
                            , std::remove_cvref_t<element_t<pos.t[N], rts>>
                            >...
                        >;

        return type{ get<pos.e[N]>(get<pos.t[N]>(KUMI_FWD(tuples)))... };
      }(kumi::forward_as_tuple(KUMI_FWD(ts)...), std::make_index_sequence<count-1>{});
    }
  }

  namespace result
  {
    template<product_type... Tuples> struct cat
    {
      using type = decltype( kumi::cat( std::declval<Tuples>()... ) );
    };

    template<product_type... Tuples> using cat_t  = typename cat<Tuples...>::type;
  }
}
