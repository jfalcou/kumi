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
  template<typename Pred, typename... Ts>
  [[nodiscard]] KUMI_ABI constexpr auto locate( tuple<Ts...> const& t, Pred p ) noexcept
  {
    auto locator = [&](auto const&... m)
    {
      bool checks[] = { p(m)...  };
      for(std::size_t i=0;i<sizeof...(Ts);++i)
        if(checks[i]) return i;
      return sizeof...(Ts);
    };

    return kumi::apply(locator, t);
  }
}
