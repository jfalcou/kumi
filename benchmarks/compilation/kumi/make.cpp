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
  auto t = kumi::make_tuple(element<I>{}...);
  return kumi::get<0>(t).value;
}

int main()
{
  return run(bench_indices{});
}
