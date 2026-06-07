//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi
{
  //====================================================================================================================
  /**
    @ingroup  types
    @class    str
    @brief    Static string used to create named fields.

    @note the `.` character is reserved for internal manipulation.

    kumi::str provides a way to define compile time names.
  **/
  //====================================================================================================================
  struct str
  {
    static constexpr std::size_t max_size = 64;
    static constexpr std::size_t npos = static_cast<std::size_t>(-1);
    static constexpr char separator = '.';

    char data_[max_size + 1];
    unsigned int size_;

    constexpr str() = default;

    // -1 to be on par with std::string
    template<std::size_t N, std::size_t... Is>
    requires(N <= max_size)
    constexpr str(char const (&s)[N], std::index_sequence<Is...>) : data_{s[Is]...}, size_(N - 1)
    {
    }

    template<std::size_t N, std::size_t O, std::size_t... Is>
    requires(sizeof...(Is) <= max_size)
    constexpr str(char const (&s)[N], std::integral_constant<std::size_t, O>, std::index_sequence<Is...>)
      : data_{s[Is + O]...}, size_(sizeof...(Is))
    {
    }

    template<std::size_t N>
    requires(N <= max_size)
    constexpr str(char const (&s)[N]) : str{s, std::make_index_sequence<N>{}}
    {
    }

    template<std::size_t N, std::size_t P, std::size_t S>
    requires((N >= P + S) && ((N - P - S) <= max_size))
    constexpr str(char const (&s)[N],
                  std::integral_constant<std::size_t, P> prefix,
                  std::integral_constant<std::size_t, S>)
      : str{s, prefix, std::make_index_sequence<(N - 1) - P - S>{}}
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

    KUMI_ABI constexpr str remove_prefix(std::size_t n) const
    {
      if (n > size_) throw "Out of range";
      return substr(n, size_ - n);
    }

    KUMI_ABI constexpr str remove_suffix(std::size_t n) const
    {
      if (n > size_) throw "Out of range";
      return substr(0, size_ - n);
    }

    KUMI_ABI constexpr str substr(std::size_t pos = 0, std::size_t count = npos) const
    {
      std::size_t len = (count == npos || pos + count > size_) ? (size_ - pos) : count;
      str res{};
      res.size_ = len;
      for (std::size_t i = 0; i < len; ++i) res.data_[i] = data_[pos + i];
      return res;
    }

    KUMI_ABI constexpr bool starts_with(str const& s) const
    {
      if (s.size_ > size_) return false;
      for (std::size_t i = 0; i < s.size_; ++i)
        if (data_[i] != s.data_[i]) return false;
      return true;
    }

    KUMI_ABI constexpr bool ends_with(str const& s) const
    {
      if (s.size_ > size_) return false;
      for (std::size_t i = 0; i < s.size_; ++i)
        if (data_[size_ - s.size_ + i] != s.data_[i]) return false;
      return true;
    }

    KUMI_ABI constexpr bool contains(str const& s) const { return find(s) != npos; }

    constexpr std::size_t find(str const& s, std::size_t pos = 0) const
    {
      if (s.size_ == 0) return pos <= size_ ? pos : npos;
      if (s.size_ > size_) return npos;
      for (std::size_t i = pos; i <= size_ - s.size_; ++i)
      {
        bool match = true;
        for (std::size_t j = 0; j < s.size_; ++j)
          if (data_[i + j] != s.data_[j])
          {
            match = false;
            break;
          }
        if (match) return i;
      }
      return npos;
    }

    constexpr int compare(str const& other) const noexcept
    {
      std::size_t min_size = (size_ < other.size_) ? size_ : other.size_;

      for (std::size_t i = 0; i < min_size; ++i)
      {
        if (data_[i] < other.data_[i]) return -1;
        if (data_[i] > other.data_[i]) return 1;
      }
      if (size_ < other.size_) return -1;
      if (size_ > other.size_) return 1;
      return 0;
    }

    constexpr std::size_t rfind(str const& s, std::size_t pos = npos) const
    {
      if (s.size_ == 0) return (pos > size_ ? size_ : pos);
      if (s.size_ > size_) return npos;
      std::size_t start = (pos > size_ - s.size_) ? (size_ - s.size_) : pos;
      for (int i = static_cast<int>(start); i >= 0; --i)
      {
        bool match = true;
        for (std::size_t j = 0; j < s.size_; ++j)
          if (data_[i + j] != s.data_[j])
          {
            match = false;
            break;
          }
        if (match) return static_cast<std::size_t>(i);
      }
      return npos;
    }

    KUMI_ABI constexpr std::size_t find_first_of(str const& s, std::size_t pos = 0) const
    {
      for (std::size_t i = pos; i < size_; ++i)
        for (std::size_t j = 0; j < s.size_; ++j)
          if (data_[i] == s.data_[j]) return i;
      return npos;
    }

    KUMI_ABI constexpr std::size_t find_last_of(str const& s, std::size_t pos = npos) const
    {
      if (size_ == 0) return npos;
      for (std::size_t i = (pos >= size_ ? size_ - 1 : pos);; --i)
      {
        for (std::size_t j = 0; j < s.size_; ++j)
          if (data_[i] == s.data_[j]) return i;
        if (i == 0) break;
      }
      return npos;
    }

    KUMI_ABI constexpr std::size_t find_first_not_of(str const& s, std::size_t pos = 0) const
    {
      for (std::size_t i = pos; i < size_; ++i)
      {
        bool found = false;
        for (std::size_t j = 0; j < s.size_; ++j)
          if (data_[i] == s.data_[j])
          {
            found = true;
            break;
          }
        if (!found) return i;
      }
      return npos;
    }

    KUMI_ABI constexpr std::size_t find_last_not_of(str const& s, std::size_t pos = npos) const
    {
      if (size_ == 0) return npos;
      for (std::size_t i = (pos >= size_ ? size_ - 1 : pos);; --i)
      {
        bool found = false;
        for (std::size_t j = 0; j < s.size_; ++j)
          if (data_[i] == s.data_[j])
          {
            found = true;
            break;
          }
        if (!found) return i;
        if (i == 0) break;
      }
      return npos;
    }

    constexpr str operator+(str const& other) const
    {
      std::size_t new_size = size_ + 1 + other.size_;
      if (new_size > max_size) throw "Overflow";

      str res{};
      res.size_ = new_size;

      for (std::size_t i = 0; i < size_; ++i) res.data_[i] = data_[i];

      res.data_[size_] = kumi::str::separator;

      for (std::size_t i = 0; i < other.size_; ++i) res.data_[size_ + 1 + i] = other.data_[i];

      res.data_[new_size] = '\0';
      return res;
    }

    static constexpr str from(char const* s, std::size_t n)
    {
      str res{};
      if (n > str::max_size) throw "Overflow";
      for (std::size_t i = 0; i < n; ++i) res.data_[i] = s[i];
      res.size_ = n;
      return res;
    }
  };

  inline namespace literals
  {
    constexpr auto operator""_str(char const* s, std::size_t n)
    {
      return kumi::str::from(s, n);
    }
  }

  //====================================================================================================================
  /**
    @ingroup  types
    @class    unknown
    @brief    Type indicating a identifier was not found in a given kumi::product_type
  **/
  //====================================================================================================================
  struct unknown
  {
    constexpr inline operator kumi::str() const noexcept { return str{"kumi::unknown"}; }

    KUMI_ABI friend constexpr auto operator<=>(unknown const&, unknown const&) noexcept = default;

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, unknown const&) noexcept
    {
      return os << "kumi::unknown";
    }
  };
}
