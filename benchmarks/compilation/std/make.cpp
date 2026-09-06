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
  auto t = std::make_tuple(elem<I>{}...);
  return std::get<0>(t).value;
}

int main()
{
  return run(bench_indices{});
}
