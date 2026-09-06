//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <cstddef>
#include <utility>

// The workload of a compilation benchmark: BENCH_N elements, each of a type of its own, so that no
// instantiation is shared between two of them and the cost measured is the cost of the size asked for.
#if !defined(BENCH_N)
#define BENCH_N 16
#endif

template<std::size_t I> struct elem
{
  int value = I;

  friend constexpr auto operator<=>(elem const&, elem const&) = default;
  friend constexpr bool operator==(elem const&, elem const&) = default;
};

using bench_indices = std::make_index_sequence<BENCH_N>;
