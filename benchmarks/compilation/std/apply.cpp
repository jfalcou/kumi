//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <tuple>
#include "payload.hpp"

template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  std::tuple<elem<I>...> t;
  return std::apply([](auto const&... e) { return (e.value + ...); }, t);
}

int main()
{
  return run(bench_indices{});
}
