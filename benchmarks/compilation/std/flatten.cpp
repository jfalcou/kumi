//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <tuple>
#include "payload.hpp"

// The standard has no flatten: one tuple_cat over the members does the level asked for, and it is the
// cheapest form, tuple_cat being variadic rather than recursive.
template<typename T, std::size_t... I> auto flatten(T const& t, std::index_sequence<I...>)
{
  return std::tuple_cat(std::get<I>(t)...);
}

template<std::size_t... I> auto run(std::index_sequence<I...> seq)
{
  std::tuple<std::tuple<elem<I>, elem<I>>...> t;
  auto f = flatten(t, seq);

  return std::get<0>(f).value + int(std::tuple_size_v<decltype(f)>);
}

int main()
{
  return run(bench_indices{});
}
