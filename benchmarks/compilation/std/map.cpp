//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <functional>
#include <tuple>
#include "payload.hpp"

// On par with kumi::map: the same callable, one std::invoke per element, and a tuple rebuilt from the results.
template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  std::tuple<element<I>...> t;
  auto f = [](auto const& e) { return e.value * 2; };
  auto u = std::apply([&](auto const&... e) { return std::make_tuple(std::invoke(f, e)...); }, t);

  return std::get<0>(u);
}

int main()
{
  return run(bench_indices{});
}
