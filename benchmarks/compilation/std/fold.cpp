//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <functional>
#include <tuple>
#include "payload.hpp"

// On par with kumi::fold_left: the same callable and the same initial value, one std::invoke per element.
template<std::size_t... I> auto run(std::index_sequence<I...>)
{
  std::tuple<element<I>...> t;
  auto f = [](auto acc, auto const& e) { return acc + e.value; };

  return std::apply(
    [&](auto const&... e) {
      int acc = 0;
      ((acc = std::invoke(f, acc, e)), ...);
      return acc;
    },
    t);
}

int main()
{
  return run(bench_indices{});
}
