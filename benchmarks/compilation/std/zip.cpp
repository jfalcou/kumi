//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <tuple>
#include "payload.hpp"

// The standard has no zip over tuples: one index_sequence and one make_tuple of pairs is the whole of it.
template<typename T, std::size_t... I> auto zip(T const& a, T const& b, std::index_sequence<I...>)
{
  return std::make_tuple(std::make_tuple(std::get<I>(a), std::get<I>(b))...);
}

template<std::size_t... I> auto run(std::index_sequence<I...> seq)
{
  std::tuple<elem<I>...> t;
  auto z = zip(t, t, seq);

  return std::get<0>(std::get<0>(z)).value;
}

int main()
{
  return run(bench_indices{});
}
