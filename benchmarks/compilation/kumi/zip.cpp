//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kumi/tuple.hpp>
#include <kumi/algorithm/zip.hpp>
#include "payload.hpp"

template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  kumi::tuple<elem<I>...> t;
  auto z = kumi::zip(t, t);

  return kumi::get<0>(kumi::get<0>(z)).value;
}

int main()
{
  return run(bench_indices{});
}
