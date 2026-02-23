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
  //! @ingroup utility
  //! @class unit
  //! @brief A type representing the product of no type also called the unit type
  //!
  //! kumi::unit provides a way to define the unit type in a constexpr friendly manner.
  //================================================================================================
  struct unit
  {
    KUMI_ABI friend constexpr auto operator<=>(unit, unit) noexcept = default;

    template<typename T>
    requires(concepts::unit_type<T>)
    [[nodiscard]] KUMI_ABI constexpr operator T() const noexcept
    {
      return {};
    };

    template<typename T>
    requires(concepts::unit_type<T>)
    [[nodiscard]] KUMI_ABI constexpr operator T() noexcept
    {
      return {};
    };

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, unit) noexcept
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
