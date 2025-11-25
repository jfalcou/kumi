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
  template< template<typename...> typename Traits
          , product_type T
          , typename Seq = std::make_index_sequence<size<T>::value>
          >
  struct apply_traits;

  template< template<typename...> typename Traits
          , product_type T
          , std::size_t... Is
          >
  requires( requires {typename Traits<element_t<Is,T>...>::type;})
  struct  apply_traits<Traits, T, std::index_sequence<Is...>>
  {
    using type = typename Traits<element_t<Is,T>...>::type;
  };

  template< template<typename...> typename Traits
          , product_type T
          >
  using apply_traits_t = typename apply_traits<Traits, T>::type;



  template< template<typename...> typename Traits
          , product_type T
          , typename Seq = std::make_index_sequence<size<T>::value>
          >
  struct map_traits;

  template< template<typename...> typename Traits
          , product_type T
          , std::size_t... Is
          >
  requires( requires {typename Traits<element_t<Is,T>>::type;} && ...)
  struct  map_traits<Traits, T, std::index_sequence<Is...>>
  {
    using type = tuple <typename Traits<element_t<Is, T>>::type...>;
  };

  template< template<typename...> typename Traits
          , product_type T
          >
  using map_traits_t = typename map_traits<Traits, T>::type;

}
