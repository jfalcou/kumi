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
  auto c = std::tuple_cat(t, t);

  return std::get<0>(c).value + int(std::tuple_size_v<decltype(c)>);
}

int main()
{
  return run(bench_indices{});
}
