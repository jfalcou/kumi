//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <ostream>
#include <cstdint>

#include <kumi/detail/abi.hpp>

namespace kumi 
{
  //================================================================================================
  //! @ingroup utility
  //! @class str
  //! @brief Static string used to create named fields.
  //!
  //! kumi::str provides a way to define compile time names.
  //================================================================================================
  struct str 
  {
    static constexpr std::size_t max_size = 64;

    char            data_[max_size+1];
    std::uint8_t    size_;

    template<std::size_t N, std::size_t... Is>
    constexpr str(const char (&s)[N], std::index_sequence<Is...>)
        : data_{s[Is]...}, size_(N)
    {}

    template <std::size_t N>
    constexpr str(const char (&s)[N])
        : str{s, std::make_index_sequence<N>{}}
    {}

    KUMI_ABI constexpr std::size_t       size()  const { return size_; }
    KUMI_ABI constexpr std::string_view  value() const { return std::string_view(&data_[0], size_-1); }

    KUMI_ABI friend constexpr auto operator <=>(str const&, str const&) noexcept = default;

    friend std::ostream& operator<<(std::ostream& os, str const& s)
    {
        return os << '\'' << s.value() << '\'';
    }
  };
}
