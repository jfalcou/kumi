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
  std::tuple<element<I>...> t;
  return (std::get<I>(t).value + ...);
}

int main()
{
  return run(bench_indices{});
}
