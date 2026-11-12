/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <type_traits>

int main()
{
  using namespace kumi::literals;
  kumi::tuple t = {1, 2.5, 'c', 4.f};

  // the projection onto the indices 3, 1, 1, written 2, 0, 0 from 0
  std::cout << kumi::reorder<2, 0, 0>(t) << '\n';

  // every second component, from the index 0 to the end
  std::cout << kumi::extract(t, 0_c, 4_c, 2_c) << '\n';

  // the components of integral type
  std::cout << kumi::filter<std::is_integral>(t) << '\n';

  // the pair of projections cut at the index 2
  std::cout << kumi::split(t, 2_c) << '\n';

  // a projection of values holds copies, so t keeps its first component
  auto u = kumi::reorder<0>(t);
  kumi::get<0>(u) = 42;
  std::cout << t << " and " << u << '\n';
}
