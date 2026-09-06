//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <tuple>
#include "payload.hpp"

// The standard has no map: applying the function under std::apply and rebuilding a tuple from the pack
// is the shortest form, and the one that instantiates the least.
template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  std::tuple<element<I>...> t;
  auto u = std::apply([](auto const&... e) { return std::make_tuple(e.value * 2 ...); }, t);

  return std::get<0>(u);
}

int main()
{
  return run(bench_indices{});
}
