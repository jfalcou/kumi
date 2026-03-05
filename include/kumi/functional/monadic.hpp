//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

namespace kumi::_
{
  //==============================================================================================
  // Fold helpers
  //==============================================================================================
  template<typename T> struct foldable
  {
    T value;

    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator>>(foldable&& x, C&& c)
    {
      return _::foldable{invoke(c, x.value)};
    }

    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator<<(C&& c, foldable&& x)
    {
      return _::foldable{invoke(c, x.value)};
    }

    constexpr auto operator()() const noexcept { return value; }
  };

  template<typename T> foldable(T&& t) -> foldable<std::unwrap_ref_decay_t<T>>;

  //==============================================================================================
  // Scan helpers
  //==============================================================================================
  template<typename F, typename V> struct scannable
  {
    F func;
    V value;

    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator>>(scannable&& m, C&& c)
    {
      auto res = invoke(c, m.value);
      return _::scannable{bind_front(std::move(m.func), std::move(m.value)), res};
    }

    template<typename C> KUMI_ABI friend constexpr decltype(auto) operator<<(C&& c, scannable&& m)
    {
      auto res = invoke(c, m.value);
      return _::scannable{bind_back(std::move(m.func), std::move(m.value)), res};
    }

    KUMI_ABI constexpr decltype(auto) operator()() const noexcept { return invoke(func, value); }
  };

  template<class F, class V> scannable(F&& f, V&& v) -> scannable<F, std::unwrap_ref_decay_t<V>>;

}
