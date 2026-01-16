//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <kumi/detail/binder.hpp>
#include <kumi/utils/traits.hpp>
#include <kumi/utils/concepts.hpp>

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
    template<_::stream Os> friend auto &operator<<(Os &os, indexes_t const& i) noexcept
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
  template<indexer... Ts> KUMI_CUDA indexes_t(Ts...) -> indexes_t<Ts...>;

  //================================================================================================
  //! @ingroup utility 
  //! @brief Creates a kumi::indexes object, deducing the target type from the types of arguments.
  //!
  //! @note The arguments should model kumi::indexer 
  //!
  //! @param ts	Zero or more indexes to construct the indexes from.
  //! @return A kumi::indexes constructed from the ts 
  //================================================================================================
  template<indexer... Ts>
  [[nodiscard]] KUMI_ABI consteval auto indexes(Ts... ts) noexcept
  {
    return indexes_t{ts...};
  }
}
