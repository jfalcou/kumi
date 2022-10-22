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
  //! ## Example
  //! @include doc/cat.cpp
  //================================================================================================
  template<product_type... Tuples> [[nodiscard]] constexpr auto cat(Tuples&&... ts)
  {
    if constexpr(sizeof...(Tuples) == 0) return tuple{};
    else
    {
      // count is at least 1 so MSVC don't cry when we use a 0-sized array
      constexpr auto count = (1ULL + ... + kumi::size<Tuples>::value);
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

        (locate(std::make_index_sequence<kumi::size<Tuples>::value>{}),...);

        return that;
      }();

      return [&]<std::size_t... N>(auto&& tuples, std::index_sequence<N...>)
      {
        using ts  = std::remove_cvref_t<decltype(tuples)>;
        using type =  kumi::tuple
                      < std::tuple_element_t< pos.e[N]
                                            , std::remove_cvref_t<std::tuple_element_t<pos.t[N],ts>>
                                            >...
                      >;
        return type{get<pos.e[N]>(get<pos.t[N]>(tuples))...};
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
