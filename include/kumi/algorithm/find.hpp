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
  //! @include doc/locate.cpp
  //================================================================================================
  template<typename Pred, product_type Tuple>
  [[nodiscard]] KUMI_ABI constexpr auto locate( Tuple&& t, Pred p ) noexcept
  {
    return kumi::apply([&](auto &&...m)
    {
      bool checks[] = { p(m)...  };
      for(std::size_t i=0;i<size_v<Tuple>;++i)
        if(checks[i]) return i;
      return size_v<Tuple>;
    }, KUMI_FWD(t));
  }
}
