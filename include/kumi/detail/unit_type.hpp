//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <iosfwd>
#include <kumi/detail/abi.hpp>

namespace kumi
{
  //================================================================================================
  //! @ingroup utility 
  //! @class unit
  //! @brief A type representing the product of no type also called the unit type 
  //!
  //! kumi::unit provides a way to define the unit type in a constexpr friendly manner .
  //================================================================================================
  struct unit 
  {
    KUMI_ABI friend constexpr auto operator<=>(unit, unit) noexcept = default;

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> &operator<<( std::basic_ostream<CharT,Traits> &os
                                                        , unit) noexcept
    {
      return os << '\'' << "none" << '\'';
    }
  };
    
  //==============================================================================================
  //! @ingroup utility
  //! @brief Inline constant representing a kumi::unit.
  //==============================================================================================
  inline constexpr unit none = {};
}
