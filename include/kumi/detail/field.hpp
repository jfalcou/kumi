//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <iostream>
#include <cstdint>

namespace kumi 
{
  //================================================================================================
  //! @ingroup str
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

    constexpr std::size_t       size()  const { return size_; }
    constexpr std::string_view  value() const { return std::string_view(&data_[0], size_); }

    friend constexpr bool operator <=>(str const&, str const&) noexcept = default;

    friend std::ostream& operator<<(std::ostream& os, str const& s)
    {
        return os << '\'' << s.value() << '\'';
    }
  };

  //================================================================================================
  //! @ingroup str
  //! @class str_list
  //! @brief Compile time list of string used to retrieve named fields.
  //!
  //! kumi::str_list provides a way to define a compile time list of strings.
  //!
  //! @tparam Names A variadic number of non type template parameters kumi::str
  //================================================================================================
  template<auto... Names>
  struct str_list
  {
    static constexpr std::size_t size = sizeof...(Names);

    template<std::size_t I>
    static constexpr auto get()
    {
        constexpr kumi::str namelist[] = {Names...};
        return namelist[I];
    }
  };
}
