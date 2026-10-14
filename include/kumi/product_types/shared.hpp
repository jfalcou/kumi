//======================================================================================================================
//! @file
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace kumi
{

  namespace _
  {
    template<typename T, typename U, std::size_t... I> constexpr T static_cast_(U&& u, std::index_sequence<I...>)
    {
      return {static_cast<kumi::element_t<I, T>>(get<I>(KUMI_FWD(u)))...};
    }

    template<typename T, typename U, std::size_t... I> constexpr void assign(T&& t, U&& u, std::index_sequence<I...>)
    {
      ((get<I>(KUMI_FWD(t)) = get<I>(KUMI_FWD(u))), ...);
    }

    template<typename T, typename U, std::size_t... I>
    constexpr auto compare(T&& t, U&& u, std::index_sequence<I...>) noexcept
    {
      return ((get<I>(KUMI_FWD(t)) == get<I>(KUMI_FWD(u))) && ...);
    }

    // The first position where t and u differ decides the order
    template<typename T, typename U, std::size_t... I>
    constexpr auto lexicographic_compare(T const& t, U const& u, std::index_sequence<I...>) noexcept
    {
      // The accumulators take the type of the whole fold: masks of different element types do not convert
      using result_t = decltype((... || (get<I>(t) < get<I>(u))));

      result_t less{false};
      result_t equal{true};

      ((less = less || (equal && (get<I>(t) < get<I>(u))), equal = equal && !less && !(get<I>(u) < get<I>(t))), ...);

      return less;
    }

    template<typename Os, typename T, std::size_t... I>
    constexpr Os& print(
      Os& os, T&& t, char start, [[maybe_unused]] char separator, char stop, std::index_sequence<I...>)
    {
      os << start << ' ';
      ((os << kumi::_::make_streamable(get<I>(KUMI_FWD(t))) << separator << ' '), ...);
      os << kumi::_::make_streamable(get<sizeof...(I)>(KUMI_FWD(t))) << ' ' << stop;
      return os;
    }
  }
}
