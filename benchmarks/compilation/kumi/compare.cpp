//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kumi/tuple.hpp>
#include "payload.hpp"

template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  kumi::tuple<element<I>...> t;
  kumi::tuple<element<I>...> u;

  return (t == u) ? 0 : 1;
}

int main()
{
  return run(bench_indices{});
}
