//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#include <iosfwd>
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

    char data_[max_size + 1];
    unsigned int size_;

    // -1 to be on par with std::string
    template<std::size_t N, std::size_t... Is>
    requires(N <= max_size)
    constexpr str(char const (&s)[N], std::index_sequence<Is...>) : data_{s[Is]...}, size_(N - 1)
    {
    }

    template<std::size_t N>
    requires(N <= max_size)
    constexpr str(char const (&s)[N]) : str{s, std::make_index_sequence<N>{}}
    {
    }

    KUMI_ABI constexpr std::size_t size() const noexcept { return size_; }

    KUMI_ABI constexpr auto data() const noexcept { return data_; }

    template<typename T>
    requires requires { T{data_, size_}; }
    KUMI_ABI constexpr auto as() const
    {
      return T{data_, size_};
    }

    KUMI_ABI friend constexpr auto operator<=>(str const&, str const&) noexcept = default;

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, str const& s) noexcept
    {
      os << '\'';
      for (std::size_t i = 0; i < s.size(); ++i) os << s.data_[i];
      return os << '\'';
    }
  };

  template<str... Strs>
  requires((Strs.size() + ... + sizeof...(Strs)) < str::max_size)
  [[nodiscard]] KUMI_ABI constexpr auto concatenate_str()
  {
    constexpr auto nb_strs = sizeof...(Strs);

    struct
    {
      unsigned int count = {};
      char t[(Strs.size() + ... + sizeof...(Strs))];
    } that;

    auto fill = [&]<std::size_t... N>(str current, std::index_sequence<N...>) {
      ((that.t[that.count++] = current.data_[N]), ...);
    };

    [&]<std::size_t... I>(std::index_sequence<I...>) {
      ((fill(Strs, std::make_index_sequence<Strs.size()>{}),
        (I + 1 < nb_strs ? (that.t[that.count++] = '.', 0) : (that.t[that.count++] = '\0', 0))),
       ...);
    }(std::make_index_sequence<nb_strs>{});

    return str{that.t};
  };
}
