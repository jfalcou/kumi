//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <tuple>
#include "payload.hpp"

// The standard has no transpose: two index_sequences, the outer one over the rows and the inner one over
// the columns, and nothing else is needed.
template<std::size_t J, typename T, std::size_t... I> auto column(T const& t, std::index_sequence<I...>)
{
  return std::make_tuple(std::get<J>(std::get<I>(t))...);
}

template<typename T, std::size_t... J> auto transpose(T const& t, std::index_sequence<J...>)
{
  return std::make_tuple(column<J>(t, bench_indices{})...);
}

template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  std::tuple<std::tuple<element<I>, element<I>>...> t;
  auto r = transpose(t, std::make_index_sequence<2>{});

  return std::get<0>(std::get<0>(r)).value;
}

int main()
{
  return run(bench_indices{});
}
