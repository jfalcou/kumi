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

    // less and equal accumulate over the positions without converting to bool, so an element comparison returning
    // a mask keeps its type
    template<typename L, typename E> struct lexicographic_order
    {
      L less;
      E equal;

      template<std::size_t J, typename T, typename U>
      constexpr void next(kumi::index_t<J>, T const& t, U const& u) noexcept
      {
        if constexpr (J != 0)
        {
          auto l = get<J>(t) < get<J>(u);
          less = less || (equal && l);
          equal = equal && !l && !(get<J>(u) < get<J>(t));
        }
      }
    };

    template<typename L, typename E> lexicographic_order(L, E) -> lexicographic_order<L, E>;

    template<typename T, typename U, std::size_t... I>
    constexpr auto lexicographic_compare(T&& t, U&& u, std::index_sequence<I...>) noexcept
    {
      if constexpr (sizeof...(I) == 0) return false;
      else
      {
        auto less = get<0>(t) < get<0>(u);
        lexicographic_order order{less, !less && !(get<0>(u) < get<0>(t))};
        (order.next(kumi::index<I>, t, u), ...);
        return order.less;
      }
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
