//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kumi/tuple.hpp>
#include <kumi/algorithm/fold.hpp>
#include "payload.hpp"

template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  kumi::tuple<elem<I>...> t;
  return kumi::fold_left([](auto acc, auto const& e) { return acc + e.value; }, t, 0);
}

int main()
{
  return run(bench_indices{});
}
