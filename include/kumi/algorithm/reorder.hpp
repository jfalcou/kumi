//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/detail/builder.hpp>
#include <kumi/detail/indexes.hpp>

namespace kumi
{

  namespace _
  {
    template<index_map auto idxs, product_type T>
    consteval auto in_bound_index()
    {
      using map_t = std::remove_cvref_t<decltype(idxs)>;
      if constexpr ( sized_product_type<T,0> )            return false;
      else if constexpr ( sized_product_type<map_t, 0> )  return true;
      else return []<std::size_t... N>(std::index_sequence<N...>)
      {
        bool checks[] = {( []()
        {
          if constexpr ( product_type<element_t<N,map_t>> ) return in_bound_index<get<N>(idxs), T>();
          else if constexpr( get<N>(idxs) < size_v<T> )     return true;
          else                                              return false;
        }())...};

        for(std::size_t i=0;i<idxs.size();++i) 
          if(!checks[i]) return false;

        return true; 
      }( std::make_index_sequence<idxs.size()>{} );
    };
  }
  //================================================================================================
  //! @ingroup generators
  //! @brief Reorder elements of a kumi::product_type
  //!
  //! This function does not participate in overload resolution if any Idx is outside [0, size_v<T>[.
  //!
  //! @note Nothing prevent the number of reordered index to be lesser or greater than t size or
  //!       the fact they can appear multiple times.
  //!
  //! @note reorder(tuple) works and is equivalent to reorder<>(tuple)
  //!
  //! @tparam Idx     Reordered index of elements
  //! @param  t kumi::product_type to reorder
  //! @return A tuple equivalent to kumi::make_tuple(t[index<Idx>]...);
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple,std::size_t... Idx> struct reorder;
  //!
  //!   template<product_type Tuple,std::size_t... Idx>
  //!   using reorder_t = typename reorder<Tuple,Idx...>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::reorder
  //! 
  //! ## Example
  //! @include doc/reorder.cpp
  //================================================================================================
  template<std::size_t... Idx, product_type Tuple>
  requires((Idx < size_v<Tuple>) && ...)
  [[nodiscard]] KUMI_ABI constexpr auto reorder(Tuple &&t)
  {
    return _::builder<Tuple>::make( get<Idx>(KUMI_FWD(t))... );
  }

  //================================================================================================
  //! @ingroup generators
  //! @brief Reindex elements of a kumi::product_type
  //!
  //! This function does not participate in overload resolution if any Idx is outside [0, size_v<T>[.
  //!
  //! @note Nothing prevent the number of reordered index to be lesser or greater than t size or
  //!       the fact they can appear multiple times.
  //!
  //! @tparam Indexes   A kumi::index_map_t representing the reindexed slot of the elements
  //! @param  t kumi::product_type to reindex
  //! @return A potentially nested tuple following the Indexes order 
  //!
  //! ## Helper type
  //! @code
  //! namespace kumi::result
  //! {
  //!   template<product_type Tuple,std::size_t... Idx> struct reindex;
  //!
  //!   template<product_type Tuple,std::size_t... Idx>
  //!   using reorder_t = typename reindex<Tuple,Idx...>::type;
  //! }
  //! @endcode
  //!
  //! Computes the return type of a call to kumi::reindex
  //! 
  //! ## Example
  //! @include doc/reindex.cpp
  //================================================================================================
  template<index_map auto Indexes, product_type Tuple>
  requires ( _::in_bound_index<Indexes, Tuple>() )
  [[nodiscard]] KUMI_ABI constexpr auto reindex(Tuple &&t)
  {
    using idx_type = std::remove_cvref_t<decltype(Indexes)>;
    auto mk = [&]<auto Idx>() -> decltype(auto)
    {
      if constexpr ( product_type<decltype(Idx)> )  return reindex<Idx>(KUMI_FWD(t));
      else                                          return get<Idx>(KUMI_FWD(t));                  
    };
  
    if constexpr ( sized_product_type<Tuple, 0> )         return _::builder<Tuple>::make();
    else if constexpr( sized_product_type<idx_type, 0> )  return _::builder<Tuple>::make();
    else return [&]<std::size_t ...I>(std::index_sequence<I...>)
    {
      return _::builder<Tuple>::make( mk.template operator()<get<I>(Indexes)>()... );
    }(std::make_index_sequence<Indexes.size()>{});
  }

  namespace result
  {
    template<product_type Tuple, std::size_t... Idx>
    struct reorder
    {
      using type = decltype( kumi::reorder<Idx...>( std::declval<Tuple>() ) );
    };
   
    template<product_type Tuple, index_map auto Indexes> 
    struct reindex 
    {
      using type = decltype( kumi::reindex<Indexes>( std::declval<Tuple>() ) );
    };

    template<product_type Tuple, std::size_t... Idx>
    using reorder_t = typename reorder<Tuple,Idx...>::type;
     
    template<product_type Tuple, index_map auto Indexes>
    using reindex_t = typename reindex<Tuple,Indexes>::type;
  }
}
