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
  //================================================================================================
  //! @ingroup generators
  //! @brief Reorder elements of a kumi::product_type
  //!
  //! This function does not participate in overload resolution if any IDx is outside [0, size_v<T>[.
  //!
  //! @note Nothing prevent the number of reordered index to be lesser or greater than t size or
  //!       the fact they can appear multiple times.
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
  #include <kumi/detail/builder.hpp>

  template<std::size_t... Idx, product_type Tuple>
  requires((Idx < size_v<Tuple>) && ...)
  [[nodiscard]] KUMI_ABI constexpr auto reorder(Tuple &&t)
  {
    return _::builder<std::remove_cvref_t<Tuple>>::make( get<Idx>(KUMI_FWD(t))... );
  }

  namespace result
  {
    template<product_type Tuple, std::size_t... Idx>
    struct reorder
    {
      using type = decltype( kumi::reorder<Idx...>( std::declval<Tuple>() ) );
    };

    template<product_type Tuple, std::size_t... Idx>
    using reorder_t = typename reorder<Tuple,Idx...>::type;
  }
}
