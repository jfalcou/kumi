//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi::_
{
  //====================================================================================================================
  // We optimize layout for tuple of size 1->10 and for homogeneous layout
  // This shaves a bit of compile time and it makes symbol length of tuple NTTP shorter
  //====================================================================================================================

  // We usually don't want to optimize tuple of references
  template<typename... Ts> inline constexpr bool no_references = (true && ... && !std::is_reference_v<Ts>);

  // [[no_unique_address]] is to unstable at the moment, will go through the standard path
  template<typename... Ts> inline constexpr bool no_empty = (true && ... && !std::is_empty_v<Ts>);

  // We care about homogeneous tuple
  template<typename T0, typename... Ts> inline constexpr bool all_the_same = (true && ... && std::is_same_v<T0, Ts>);

  //====================================================================================================================
  // Optimized binder for homogeneous layout if:
  //  - Size is greater than 1
  //  - All types are the same, non-reference and not empty
  //====================================================================================================================
  template<std::size_t... Is, typename T0, typename T1, typename... Ts>
  requires(kumi::_::all_the_same<T0, T1, Ts...> && kumi::_::no_references<T0, T1, Ts...> &&
           kumi::_::no_empty<T0, T1, Ts...>)
  struct binder<std::index_sequence<Is...>, T0, T1, Ts...>
  {
    using type = T0;
    static constexpr std::size_t N = 2 + sizeof...(Ts);

    static constexpr bool is_homogeneous = true;
    type members[N];

    template<std::size_t I>
    KUMI_HIDDEN_ABI constexpr auto& operator()(std::integral_constant<std::size_t, I>) & noexcept
    {
      return members[I];
    }

    template<std::size_t I>
    KUMI_HIDDEN_ABI constexpr auto const& operator()(std::integral_constant<std::size_t, I>) const& noexcept
    {
      return members[I];
    }

    template<std::size_t I>
    KUMI_HIDDEN_ABI constexpr auto&& operator()(std::integral_constant<std::size_t, I>) && noexcept
    {
      return static_cast<type&&>(members[I]);
    }

    template<std::size_t I>
    KUMI_HIDDEN_ABI constexpr auto const&& operator()(std::integral_constant<std::size_t, I>) const&& noexcept
    {
      return static_cast<type const&&>(members[I]);
    }
  };

  //====================================================================================================================
  // Optimized binder for 1->10 elements, none being reference (Helps with symbol length of NTTPs)
  //====================================================================================================================
  FOR_LIST_OF_STRUCTS(KUMI_BINDER)
}
