//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi
{
  //====================================================================================================================
  //! @ingroup queries
  //! @brief  Return the index of a value which type satisfies a given predicate
  //!
  //! On record types, this function operates as if the elements are ordered. The considered order is the order of
  //! declaration.
  //!
  //! @param  t Product Type to process
  //! @param  p Unary predicate. p must return a value convertible to `bool` for every element of t.
  //! @return Integral index of the element inside the product type if present, kumi::size<T>::value
  //!         otherwise.
  //!
  //! ## Examples:
  //! @include doc/tuple/algo/locate.cpp
  //! @include doc/record/algo/locate.cpp
  //====================================================================================================================
  template<typename Pred, concepts::product_type T> [[nodiscard]] KUMI_ABI constexpr auto locate(T&& t, Pred p) noexcept
  {
    if constexpr (concepts::sized_product_type<T, 0>) return 0;
    else if constexpr (concepts::record_type<T>) return locate(values_of(KUMI_FWD(t)), p);
    else
      return [&]<std::size_t... I>(std::index_sequence<I...>) {
        bool checks[] = {invoke(p, get<I>(KUMI_FWD(t)))...};
        for (std::size_t i = 0; i < size_v<T>; ++i)
          if (checks[i]) return i;
        return size_v<T>;
      }(std::make_index_sequence<size_v<T>>{});
  }
}
