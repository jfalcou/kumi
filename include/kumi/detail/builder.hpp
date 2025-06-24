//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include<kumi/utils/concepts.hpp>

namespace kumi
{
  template<typename T> 
  struct builder
  {
    template<typename... Ts>
    using to = kumi::tuple<Ts...>;

    template<typename...Args>
    static constexpr auto make(Args&&... args)
    {
      return kumi::tuple{ KUMI_FWD(args)... };
    }
  };

  template<template<class...> class Box, typename... Ts>
  struct builder<Box<Ts...>>
  {
    template<typename... Us>
    using to = Box<Us...>;

    template<typename... Args>
    static constexpr auto make(Args&&... args)
    {
      return Box{ KUMI_FWD(args)... };
    } 
  }; 

  template <typename T, typename... Args>
  using builder_t = typename builder<T>::template to<Args...>;
}
