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
  inline constexpr auto npos = static_cast<kumi::config::default_size_type>(-1);

  //====================================================================================================================
  /**
    @ingroup kumi_types
    @class    str
    @brief    Static string used to create named fields.

    @tparam N Number of characters in the string (the storage holds N + 1 chars, for the null terminator).

    @note the `.` character is reserved for internal manipulation.

    kumi::str provides a way to define compile time names. A literal "abc" is deduced as kumi::str<3>.
    Member functions taking another string accept a character array (`char const (&)[M]`, M including the
    terminator), so they work with literals as well as with `other.data_`.
  **/
  //====================================================================================================================
  template<kumi::config::default_size_type N> struct str
  {
    using size_type = kumi::config::default_size_type;
    static constexpr char separator = '.';

    char data_[N + 1] = {0};

    constexpr str() = default;

    KUMI_ABI constexpr str(char const (&s)[N + 1])
    {
      for (size_type i = 0; i < N + 1; ++i) data_[i] = s[i];
    }

    KUMI_ABI constexpr size_type size() const noexcept { return N; }

    KUMI_ABI constexpr auto data() const noexcept { return data_; }

    template<typename T>
    requires requires { T{data_, size_type{N}}; }
    KUMI_ABI constexpr auto as() const
    {
      return T{data_, size_type{N}};
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, str const& s) noexcept
    {
      os << '\'';
      for (size_type i = 0; i < N; ++i) os << s.data_[i];
      return os << '\'';
    }

    // The size of the result depends on the arguments, so they are passed as std::integral_constant.
    template<kumi::concepts::index Pos, kumi::concepts::index Count>
    KUMI_ABI constexpr auto substr(Pos p, Count c) const
    {
      constexpr size_type pos = static_cast<size_type>(p);
      constexpr size_type count = static_cast<size_type>(c);
      static_assert(pos <= N, "Out of range");
      constexpr size_type len = (count == kumi::npos || pos + count > N) ? (N - pos) : count;
      str<len> res{};
      for (size_type i = 0; i < len; ++i) res.data_[i] = data_[pos + i];
      return res;
    }

    template<kumi::concepts::index Pos> KUMI_ABI constexpr auto substr(Pos p) const
    {
      return substr(p, std::integral_constant<size_type, kumi::npos>{});
    }

    KUMI_ABI constexpr auto substr() const { return substr(std::integral_constant<size_type, 0>{}); }

    template<kumi::concepts::index Size> KUMI_ABI constexpr auto remove_prefix(Size s) const
    {
      static_assert(static_cast<size_type>(s) <= N, "Out of range");
      return substr(std::integral_constant<size_type, static_cast<size_type>(s)>{},
                    std::integral_constant<size_type, N - static_cast<size_type>(s)>{});
    }

    template<kumi::concepts::index Size> KUMI_ABI constexpr auto remove_suffix(Size s) const
    {
      static_assert(static_cast<size_type>(s) <= N, "Out of range");
      return substr(std::integral_constant<size_type, 0>{},
                    std::integral_constant<size_type, N - static_cast<size_type>(s)>{});
    }

    template<size_type M> KUMI_ABI constexpr bool starts_with(char const (&s)[M]) const
    {
      constexpr size_type n = M - 1;
      if (n > N) return false;
      for (size_type i = 0; i < n; ++i)
        if (data_[i] != s[i]) return false;
      return true;
    }

    template<size_type M> KUMI_ABI constexpr bool ends_with(char const (&s)[M]) const
    {
      constexpr size_type n = M - 1;
      if (n > N) return false;
      for (size_type i = 0; i < n; ++i)
        if (data_[N - n + i] != s[i]) return false;
      return true;
    }

    template<size_type M> KUMI_ABI constexpr bool contains(char const (&s)[M]) const { return find(s) != kumi::npos; }

    template<size_type M> KUMI_ABI constexpr size_type find(char const (&s)[M], size_type pos = 0) const
    {
      constexpr size_type n = M - 1;
      if (n == 0) return pos <= N ? pos : kumi::npos;
      if (n > N) return kumi::npos;
      for (size_type i = pos; i <= N - n; ++i)
      {
        bool match = true;
        for (size_type j = 0; j < n; ++j)
          if (data_[i + j] != s[j])
          {
            match = false;
            break;
          }
        if (match) return i;
      }
      return kumi::npos;
    }

    template<size_type M> KUMI_ABI constexpr int compare(char const (&other)[M]) const noexcept
    {
      constexpr size_type n = M - 1;
      constexpr size_type min_size = (N < n) ? N : n;

      for (size_type i = 0; i < min_size; ++i)
      {
        if (data_[i] < other[i]) return -1;
        if (data_[i] > other[i]) return 1;
      }
      if (N < n) return -1;
      if (N > n) return 1;
      return 0;
    }

    template<size_type M> KUMI_ABI constexpr size_type rfind(char const (&s)[M], size_type pos = kumi::npos) const
    {
      constexpr size_type n = M - 1;
      if (n == 0) return (pos > N ? N : pos);
      if (n > N) return kumi::npos;
      size_type start = (pos > N - n) ? (N - n) : pos;
      for (size_type i = start; i > 0; --i)
      {
        bool match = true;
        for (size_type j = 0; j < n; ++j)
          if (data_[i + j] != s[j])
          {
            match = false;
            break;
          }
        if (match) return i;
      }
      return kumi::npos;
    }

    template<size_type M> KUMI_ABI constexpr size_type find_first_of(char const (&s)[M], size_type pos = 0) const
    {
      constexpr size_type n = M - 1;
      for (size_type i = pos; i < N; ++i)
        for (size_type j = 0; j < n; ++j)
          if (data_[i] == s[j]) return i;
      return kumi::npos;
    }

    template<size_type M>
    KUMI_ABI constexpr size_type find_last_of(char const (&s)[M], size_type pos = kumi::npos) const
    {
      constexpr size_type n = M - 1;
      if (N == 0) return kumi::npos;
      for (size_type i = (pos >= N ? N - 1 : pos);; --i)
      {
        for (size_type j = 0; j < n; ++j)
          if (data_[i] == s[j]) return i;
        if (i == 0) break;
      }
      return kumi::npos;
    }

    template<size_type M> KUMI_ABI constexpr size_type find_first_not_of(char const (&s)[M], size_type pos = 0) const
    {
      constexpr size_type n = M - 1;
      for (size_type i = pos; i < N; ++i)
      {
        bool found = false;
        for (size_type j = 0; j < n; ++j)
          if (data_[i] == s[j])
          {
            found = true;
            break;
          }
        if (!found) return i;
      }
      return kumi::npos;
    }

    template<size_type M>
    KUMI_ABI constexpr size_type find_last_not_of(char const (&s)[M], size_type pos = kumi::npos) const
    {
      constexpr size_type n = M - 1;
      if (N == 0) return kumi::npos;
      for (size_type i = (pos >= N ? N - 1 : pos);; --i)
      {
        bool found = false;
        for (size_type j = 0; j < n; ++j)
          if (data_[i] == s[j])
          {
            found = true;
            break;
          }
        if (!found) return i;
        if (i == 0) break;
      }
      return kumi::npos;
    }

    // N chars + separator + (M - 1) chars
    template<size_type M> KUMI_ABI constexpr str<N + M> operator+(char const (&other)[M]) const
    {
      str<N + M> res{};

      for (size_type i = 0; i < N; ++i) res.data_[i] = data_[i];

      res.data_[N] = separator;

      for (size_type i = 0; i < M - 1; ++i) res.data_[N + 1 + i] = other[i];

      return res;
    }

    // str + str: a str is not deduced through its conversion to char array, so it needs its own overload
    template<size_type M> KUMI_ABI constexpr str<N + 1 + M> operator+(str<M> const& other) const
    {
      return *this + other.data_;
    }
  };

  template<kumi::config::default_size_type M> str(char const (&)[M]) -> str<M - 1>;

  template<kumi::config::default_size_type N, kumi::config::default_size_type M>
  KUMI_ABI constexpr bool operator==(str<N> const& lhs, str<M> const& rhs) noexcept
  {
    return lhs.compare(rhs.data_) == 0;
  }

  template<kumi::config::default_size_type N, kumi::config::default_size_type M>
  KUMI_ABI constexpr auto operator<=>(str<N> const& lhs, str<M> const& rhs) noexcept
  {
    return lhs.compare(rhs.data_) <=> 0;
  }

  template<kumi::config::default_size_type N, kumi::config::default_size_type M>
  KUMI_ABI constexpr bool operator==(str<N> const& lhs, char const (&rhs)[M]) noexcept
  {
    return lhs.compare(rhs) == 0;
  }

  template<kumi::config::default_size_type N, kumi::config::default_size_type M>
  KUMI_ABI constexpr auto operator<=>(str<N> const& lhs, char const (&rhs)[M]) noexcept
  {
    return lhs.compare(rhs) <=> 0;
  }

  inline namespace literals
  {
    template<kumi::str S> KUMI_ABI constexpr auto operator""_str()
    {
      return S;
    }
  }

  //====================================================================================================================
  /**
    @ingroup kumi_types
    @class    unknown
    @brief    Type indicating an identifier was not found in a given kumi::product_type
  **/
  //====================================================================================================================
  struct unknown
  {
    static constexpr auto value = kumi::str{"kumi::unknown"};
    using type = decltype(value);

    constexpr inline operator type() const noexcept { return value; }

    KUMI_ABI friend constexpr auto operator<=>(unknown const&, unknown const&) noexcept = default;

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, unknown const&) noexcept
    {
      return os << "kumi::unknown";
    }
  };
}
