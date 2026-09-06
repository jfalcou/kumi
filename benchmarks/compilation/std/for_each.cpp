//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <tuple>
#include "payload.hpp"

template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  std::tuple<element<I>...> t;
  int total = 0;

  // A fold expression over std::apply is the shortest path the standard library offers.
  std::apply([&](auto const&... e) { ((total += e.value), ...); }, t);
  return total;
}

int main()
{
  return run(bench_indices{});
}
