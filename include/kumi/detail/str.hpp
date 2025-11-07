//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <iosfwd>
#include <cstdint>
#include <utility>
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

    template<std::size_t N, std::size_t... Is> requires ( N <= max_size )
    constexpr str(const char (&s)[N], std::index_sequence<Is...>)
        : data_{s[Is]...}, size_(N)
    {}

    template <std::size_t N> requires ( N <= max_size )
    constexpr str(const char (&s)[N])
        : str{s, std::make_index_sequence<N>{}}
    {}

    // There is a minus 1 to ease out conversion to string view, size() represent visible characters 
    KUMI_ABI constexpr std::size_t  size() const { return size_-1; }
    KUMI_ABI constexpr auto         data() const { return data_; }

    KUMI_ABI friend constexpr auto operator <=>(str const&, str const&) noexcept = default;

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT,Traits> &operator<<(  std::basic_ostream<CharT,Traits> &os
                                                        , str const& s) noexcept
    {
        os << '\'';
        for(std::size_t i=0;i<s.size();++i)
            os << s.data_[i];
        return os << '\'';
    }
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
      ((fill(Strs, std::make_index_sequence<Strs.size()-1>{}), 
        (I+1 < nb_strs ? (that.t[that.count++]='.', 0) : (that.t[that.count++]='\0',0))
      ), ...);
    }(std::make_index_sequence<nb_strs>{});
    
    return str(that.t);
  };
}
