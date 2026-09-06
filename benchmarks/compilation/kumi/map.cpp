//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kumi/tuple.hpp>
#include <kumi/algorithm/map.hpp>
#include "payload.hpp"

template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  kumi::tuple<elem<I>...> t;
  auto u = kumi::map([](auto const& e) { return e.value * 2; }, t);

  return kumi::get<0>(u);
}

int main()
{
  return run(bench_indices{});
}
