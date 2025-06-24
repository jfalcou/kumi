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
  namespace result
  {
    template<typename T> struct template_of
    {
        using type = kumi::tuple<>;
    };

    template<template<class ...> class Box, typename... Ts>
    requires requires { typename Box<>; }
    struct template_of<Box<Ts...>>
    {
      using type = Box<>;
    };

    template<typename T>
    using template_of_t = typename template_of<T>::type;
  }
    

  template<typename T, typename... Ts>
  constexpr auto common_product_type()
  {
      if constexpr((std::is_same_v< result::template_of_t<T>,
                                    result::template_of_t<Ts>
                                > && ...))
          return result::template_of_t<T>{};
      else
          return kumi::tuple<>{};
  }

  namespace result
  {
    template<typename T, typename... Ts>
    struct common_product_type
    {
        using type = decltype( kumi::common_product_type<T, Ts...>() );
    };

    template<typename... Ts>
    using common_product_type_t = typename common_product_type<Ts...>::type;
  }
}

namespace kumi::_
{
  template<typename T> struct builder
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
  using builder_t = typename builder<T>::to<Args...>;
}
