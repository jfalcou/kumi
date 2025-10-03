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
  //! @class indexes_t 
  //! @brief Compile time tuple of index used to pass several indexes_t as NTTP.
  //!
  //! kumi::indexes_t provides a way to define compile time tuple of indexes_t.
  //================================================================================================
  template<indexer... V>
  struct indexes_t
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
    
    /// Returns the number of elements in a kumi::indexes_t
    [[nodiscard]] KUMI_ABI static constexpr auto size() noexcept  { return sizeof...(V);      };
    
    /// Returns `true` if a kumi::indexes_t contains 0 elements
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
    //! @brief Extracts the Ith element from a kumi::indexes_t
    //!
    //! @note Does not participate in overload resolution if `I` is not in [0, sizeof...(Ts)).
    //! @param  i Compile-time index of the element to access
    //! @return A copy of the value of the selected element of current indexes_t.
    //==============================================================================================
    template<std::size_t I>
    requires( I < sizeof...(V) )
    [[nodiscard]] KUMI_ABI friend constexpr decltype(auto) get(indexes_t& i) noexcept
    {
      return i.get_index<I>();
    }
 
    /// @overload
    template<std::size_t I>
    requires( I < sizeof...(V))
    [[nodiscard]] KUMI_ABI friend constexpr decltype(auto) get(indexes_t const& i) noexcept
    {
      return i.get_index<I>(); 
    }
    //==============================================================================================
    //! @}
    //==============================================================================================
    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os,
                                                         indexes_t const &i) noexcept
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

 //================================================================================================
  //! @ingroup utility 
  //! @brief kumi::indexes_t deduction guide
  //! @tparam Ts  Type lists to build the indexes with.
  //================================================================================================
  template<indexer... V> KUMI_CUDA indexes_t(V...) -> indexes_t<V...>;

  template<indexer... T>
  [[nodiscard]] KUMI_ABI consteval auto indexes(T... t) noexcept
  {
    return indexes_t{t...};
  }
}
