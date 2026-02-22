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
  //! ## Examples:
  //! @include doc/tuple/algo/reverse.cpp
  //! @include doc/record/algo/reverse.cpp
  //================================================================================================
  template<concepts::product_type Tuple> [[nodiscard]] KUMI_ABI constexpr auto reverse(Tuple&& t)
  {
    if constexpr (concepts::sized_product_type<Tuple, 0>) return builder<Tuple>::make();
    else
    {
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        return builder<Tuple>::make(get<(size_v<Tuple> - 1 - I)>(KUMI_FWD(t))...);
      }(std::make_index_sequence<size<Tuple>::value>());
    }
  }

  namespace result
  {
    template<concepts::product_type Tuple> struct reverse
    {
      using type = decltype(kumi::reverse(std::declval<Tuple>()));
    };

    template<concepts::product_type Tuple> using reverse_t = typename reverse<Tuple>::type;
  }
}
