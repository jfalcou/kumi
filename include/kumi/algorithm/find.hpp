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
  //! @ingroup queries
  //! @brief  Return the index of a value which type satisfies a given predicate
  //! @param  t Tuple to process
  //! @param  p Unary predicate. p must return a value convertible to `bool` for every element of t.
  //! @return Integral index of the element inside the tuple if present, kumi::size<tuple<T...>>::value
  //!         otherwise.
  //! ## Example:
  //! @include doc/tuple/algo/locate.cpp
  //================================================================================================
  template<typename Pred, concepts::product_type Tuple>
  [[nodiscard]] KUMI_ABI constexpr auto locate(Tuple&& t, Pred p) noexcept
  {
    if constexpr (concepts::sized_product_type<Tuple, 0>) return 0;
    else if constexpr (concepts::record_type<Tuple>) return locate(values_of(KUMI_FWD(t)), p);
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        bool checks[] = {invoke(p, get<I>(KUMI_FWD(t)))...};
        for (std::size_t i = 0; i < size_v<Tuple>; ++i)
          if (checks[i]) return i;
        return size_v<Tuple>;
      }(std::make_index_sequence<size_v<Tuple>>{});
  }
}
