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

// On par with kumi::for_each: the same callable, invoked once per element through std::invoke, which is what
// a library would do rather than a fold expression written for this one case.
template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  std::tuple<element<I>...> t;
  int total = 0;
  auto f = [&](auto const& e) { total += e.value; };

  std::apply([&](auto const&... e) { (std::invoke(f, e), ...); }, t);
  return total;
}

int main()
{
  return run(bench_indices{});
}
