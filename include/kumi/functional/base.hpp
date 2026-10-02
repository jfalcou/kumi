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
  // Tuple free apply from generator data
  // template<typename Func>
  // EVE_FORCEINLINE decltype(auto) apply(Func &&f, Generator<I...> const& g)
  //{
  //  const auto impl = [&](Generator<I...> const &)
  //    {
  //      return EVE_FWD(f)(std::integral_constant<std::size_t, I>{}...);
  //    };
  //
  //  return impl(g);
  //}

  // Tuple free apply
  template<std::size_t N, typename Func, std::size_t... I>
  KUMI_HIDDEN_ABI decltype(auto) apply(Func&& f, std::index_sequence<I...> = std::make_index_sequence<N>{})
  {
    if constexpr (sizeof...(I) == 0) return kumi::invoke(KUMI_FWD(f));
    else return kumi::invoke(KUMI_FWD(f)(std::integral_constant<std::size_t, I>{}...));
  }

  template<std::size_t N, typename F, typename... Ts>
  KUMI_HIDDEN_ABI constexpr decltype(auto) for_(auto N, F f, Ts&&... ts)
  {
    return kumi::invoke(f, get<N>(KUMI_FWD(t)), get<N>(KUMI_FWD(ts))...);
  }

  // Reusable for-loop like meta-function
  // template<auto Begin, auto Step, auto End, typename Func>
  // EVE_FORCEINLINE constexpr void for_(Func f)
  //{
  //  using type = decltype(Begin);
  //  auto body = [&]<typename N>(N)
  //    {
  //      return f(std::integral_constant<type, Begin + N::value*Step>{} );
  //    };
  //
  //  [&]<auto... Iter>( std::integer_sequence<type,Iter...> )
  //  {
  //    ( body( std::integral_constant<type,Iter>{} ), ...);
  //  }( std::make_integer_sequence<type, (End - Begin + Step - 1) / Step>{});
  //}
}
