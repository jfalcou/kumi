//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <ostream>

namespace kumi
{
  //================================================================================================
  //! @ingroup utility
  //! @class index_map_t 
  //! @brief Compile time tuple of index used to pass several index_map_t as NTTP.
  //!
  //! kumi::index_map_t provides a way to define compile time tuple of index_map_t.
  //================================================================================================
  template<indexer... V>
  struct index_map_t
  {
    using tuple_base      = kumi::tuple<V...>;
    using is_product_type = void;
  
    static constexpr bool is_index_map = true;
     
    //==============================================================================================
    //! @name Properties
    //! @{
    //==============================================================================================
    
    /// Returns the number of elements in a kumi::index_map_t
    [[nodiscard]] KUMI_ABI static constexpr auto size() noexcept  { return sizeof...(V);      };
    
    /// Returns `true` if a kumi::index_map_t contains 0 elements
    [[nodiscard]] KUMI_ABI static constexpr auto empty() noexcept { return sizeof...(V) == 0; };
  
    //==============================================================================================
    //! @}
    //==============================================================================================

    //==============================================================================================
    //! @name Accessors
    //! @{
    //==============================================================================================

    //==============================================================================================
    //! @brief Extracts the Ith element from a kumi::index_map_t
    //!
    //! @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
    //! @param  i Compile-time index of the element to access
    //! @return A copy of the value of the selected element of current index_map_t.
    //==============================================================================================
    template<std::size_t I>
    requires( I < sizeof...(V) )
    [[nodiscard]] KUMI_ABI friend constexpr decltype(auto) get(index_map_t& i) noexcept
    {
      return kumi::get<I>(i.data);
    }
 
    /// @overload
    template<std::size_t I>
    requires( I < sizeof...(V))
    [[nodiscard]] KUMI_ABI friend constexpr decltype(auto) get(index_map_t const& i) noexcept
    {
      return kumi::get<I>(i.data);
    }
 
    //==============================================================================================
    //! @}
    //==============================================================================================

    friend std::ostream& operator<<(std::ostream& os, index_map_t const& i)
    {
      return os << i.data;
    }

    tuple_base data;
  };

  template<indexer... V> KUMI_CUDA index_map_t(V...) -> index_map_t<V...>;

  template<indexer... T>
  KUMI_ABI consteval auto make_index_map(T... t) noexcept
  {
    return index_map_t{t...};
  }
}

template<typename... V>
struct std::tuple_size<kumi::index_map_t<V...>> 
  : std::integral_constant<std::size_t,sizeof...(V)>
{};
  
template<std::size_t I, typename... V>
struct std::tuple_element<I, kumi::index_map_t<V...>> 
  : std::tuple_element<I, typename kumi::index_map_t<V...>::tuple_base>
{};
