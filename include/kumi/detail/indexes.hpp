//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <ostream>
#include <kumi/detail/binder.hpp>

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
    using is_product_type = void;
    using binder_t        = _::make_binder_t<std::make_integer_sequence<int,sizeof...(V)>, V...>;

    static constexpr bool is_homogeneous    = binder_t::is_homogeneous;
    static constexpr bool is_index_map      = true;
    
    binder_t impl;
     
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
    /// Workaround to avoid depending on kumi::tuple and kumi::index_t
    template<std::size_t I>
    requires(I < sizeof...(V))
    KUMI_ABI constexpr decltype(auto) get_index() const noexcept
    {
      return _::get_leaf<I>(impl);
    }
    
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
      return i.get_index<I>();
    }
 
    /// @overload
    template<std::size_t I>
    requires( I < sizeof...(V))
    [[nodiscard]] KUMI_ABI friend constexpr decltype(auto) get(index_map_t const& i) noexcept
    {
      return i.get_index<I>(); 
    }
    //==============================================================================================
    //! @}
    //==============================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os,
                                                         index_map_t const &i) noexcept
    {
      os << "( ";
      [&]<std::size_t... I>(std::index_sequence<I...>)
      {
        using std::get;
        [[maybe_unused]] auto call = [&]<typename M>(M){ os << get<M::value>(i); };
        ( call(std::integral_constant<std::size_t, I>{}), ... );
      }
      (std::make_index_sequence<sizeof...(V)>());
      os << ")";

      return os;
    }
  };

  template<indexer... V> KUMI_CUDA index_map_t(V...) -> index_map_t<V...>;

  template<indexer... T>
  KUMI_ABI consteval auto make_index_map(T... t) noexcept
  {
    return index_map_t{t...};
  }
}
