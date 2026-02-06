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
  template<template<typename...> typename Traits,
           concepts::product_type Tuple,
           typename Seq = std::make_index_sequence<size<Tuple>::value>>
  struct apply_traits;

  template<template<typename...> typename Traits, concepts::product_type Tuple, std::size_t... Is>
  requires(requires { typename Traits<element_t<Is, Tuple>...>::type; })
  struct apply_traits<Traits, Tuple, std::index_sequence<Is...>>
  {
    using type = typename Traits<element_t<Is, Tuple>...>::type;
  };

  template<template<typename...> typename Traits, concepts::product_type Tuple>
  using apply_traits_t = typename apply_traits<Traits, Tuple>::type;

  template<template<typename...> typename Traits,
           concepts::product_type Tuple,
           typename Seq = std::make_index_sequence<size<Tuple>::value>>
  struct map_traits;

  template<template<typename...> typename Traits, concepts::product_type Tuple, std::size_t... Is>
  requires(requires { typename Traits<element_t<Is, Tuple>>::type; } && ...)
  struct map_traits<Traits, Tuple, std::index_sequence<Is...>>
  {
    using type = tuple<typename Traits<element_t<Is, Tuple>>::type...>;
  };

  template<template<typename...> typename Traits, concepts::product_type Tuple>
  using map_traits_t = typename map_traits<Traits, Tuple>::type;

}
