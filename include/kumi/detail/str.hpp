//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <iosfwd>
#include <string_view>
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

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT,Traits> &operator<<(  std::basic_ostream<CharT,Traits> &os
                                                        , str const& s) noexcept
    {
        return os << '\'' << s.value() << '\'';
    }
  };

  template<str... Strs>
  requires ( (((Strs.size()-1) + ... )+1) < str::max_size )
  [[nodiscard]] KUMI_ABI constexpr auto merge_str()
  {
    struct { std::uint8_t count = {}; char t[((Strs.size()-1) + ...)+1]; } that;

    auto fill = [&]<std::size_t...N>(str current, std::index_sequence<N...>)
    {
      ((that.t[that.count++] = current.data_[N]), ...);
    };

    [&]<std::size_t...I>(std::index_sequence<I...>)
    {
      ((fill(Strs, std::make_index_sequence<Strs.size()-1>{})), ...);
    }(std::make_index_sequence<sizeof...(Strs)>{});
    that.t[that.count++] = '\0';
    
    return str(that.t);
  };

  template<str... Strs>
  requires ( (Strs.size() + ...) < str::max_size )
  [[nodiscard]] KUMI_ABI constexpr auto concatenate_str()
  {
    constexpr auto nb_strs = sizeof...(Strs);
    struct { std::uint8_t count = {}; char t[(Strs.size() + ...)]; } that;

    auto fill = [&]<std::size_t...N>(str current, std::index_sequence<N...>)
    {
      ((that.t[that.count++] = current.data_[N]), ...);
    };
    
    [&]<std::size_t...I>(std::index_sequence<I...>)
    {
      ((fill(Strs, std::make_index_sequence<Strs.size()-1>{})
        , (I +1 < nb_strs ? (that.t[that.count++] = '.', 0) : 0)
      ), ...);
    }(std::make_index_sequence<nb_strs>{});
    that.t[that.count++] = '\0';
    
    return str(that.t);
  };
}
