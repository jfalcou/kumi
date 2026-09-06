//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kumi/tuple.hpp>
#include <kumi/algorithm/flatten.hpp>
#include "payload.hpp"

template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  kumi::tuple<kumi::tuple<element<I>, element<I>>...> t;
  auto f = kumi::flatten(t);

  return kumi::get<0>(f).value + int(f.size());
}

int main()
{
  return run(bench_indices{});
}
