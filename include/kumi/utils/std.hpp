//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/utils/concepts.hpp>
#include <kumi/utils/traits.hpp>
#include <array>
#include <type_traits>
#include <utility>

#if !defined(KUMI_DOXYGEN_INVOKED)
//==================================================================================================
// Structured binding adaptation
//==================================================================================================
template<std::size_t I, typename Head, typename... Tail>
struct  std::tuple_element<I, kumi::tuple<Head, Tail...>>
      : std::tuple_element<I - 1, kumi::tuple<Tail...>>
{
};

template<std::size_t I, typename... Ts> struct std::tuple_element<I, kumi::tuple<Ts...> const>
{
  using type = typename tuple_element<I, kumi::tuple<Ts...>>::type const;
};

template<typename Head, typename... Tail> struct std::tuple_element<0, kumi::tuple<Head, Tail...>>
{
  using type = Head;
};

template<typename... Ts>
struct std::tuple_size<kumi::tuple<Ts...>> : std::integral_constant<std::size_t, sizeof...(Ts)>
{
};

//==================================================================================================
// Structured binding adaptation for records
//==================================================================================================
template<std::size_t I, typename Head, typename... Tail>
struct  std::tuple_element<I, kumi::record<Head, Tail...>>
      : std::tuple_element<I - 1, kumi::tuple<Tail...>>
{
};

template<std::size_t I, typename... Ts> struct std::tuple_element<I, kumi::record<Ts...> const>
{
  using type = typename tuple_element<I, kumi::record<Ts...>>::type const;
};

template<typename Head, typename... Tail> struct std::tuple_element<0, kumi::record<Head, Tail...>>
{
  using type = Head;
};

template<typename... Ts>
struct std::tuple_size<kumi::record<Ts...>> : std::integral_constant<std::size_t, sizeof...(Ts)>
{
};

//==================================================================================================
// Structured binding adaptation for index_map_t
//==================================================================================================
template<typename... V>
struct std::tuple_size<kumi::indexes_t<V...>> 
  : std::integral_constant<std::size_t,sizeof...(V)>
{};
  
template<std::size_t I, typename... V>
struct std::tuple_element<I, kumi::indexes_t<V...>> 
  : std::tuple_element<I, kumi::tuple<V...>>
{};

#if !defined( __ANDROID__ )
//==================================================================================================
// Common Reference support
//==================================================================================================
template< typename... Ts, typename... Us
        , template<class> class TQual, template<class> class UQual >
requires(sizeof...(Ts) == sizeof...(Us))
struct std::basic_common_reference<kumi::tuple<Ts...>, kumi::tuple<Us...>, TQual, UQual>
{
  using type = kumi::tuple<std::common_reference_t<TQual<Ts>, UQual<Us>>...>;
};
#endif

//==================================================================================================
// Standard types support (for those that model `tuple-like` & are declared in `utility`)
//==================================================================================================
template< typename T, std::size_t N >
struct kumi::is_product_type<std::array<T , N>> : std::true_type {};

template< typename... Ts >
struct kumi::is_product_type<std::tuple<Ts...>> : std::true_type {};

template< typename T1, typename T2 >
struct kumi::is_product_type<std::pair<T1,T2>> : std::true_type {};

#endif
