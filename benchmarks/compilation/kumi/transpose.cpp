//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kumi/tuple.hpp>
#include <kumi/algorithm/transpose.hpp>
#include "payload.hpp"

template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  kumi::tuple<kumi::tuple<elem<I>, elem<I>>...> t;
  auto r = kumi::transpose(t);

  return kumi::get<0>(kumi::get<0>(r)).value;
}

int main()
{
  return run(bench_indices{});
}
