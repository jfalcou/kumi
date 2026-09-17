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

    template<typename T, typename U, std::size_t... I>
    constexpr auto lexicographic_compare(T&& t, U&& u, std::index_sequence<I...>) noexcept
    {
      return ((get<0>(KUMI_FWD(t)) < get<0>(KUMI_FWD(u))) || ... ||
              (get<I + 1>(KUMI_FWD(t)) < get<I + 1>(KUMI_FWD(u)) && get<I>(KUMI_FWD(u)) >= get<I>(KUMI_FWD(t))));
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
