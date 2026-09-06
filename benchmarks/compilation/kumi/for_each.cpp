//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kumi/tuple.hpp>
#include <kumi/algorithm/for_each.hpp>
#include "payload.hpp"

template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  kumi::tuple<elem<I>...> t;
  int total = 0;

  kumi::for_each([&](auto const& e) { total += e.value; }, t);
  return total;
}

int main()
{
  return run(bench_indices{});
}
