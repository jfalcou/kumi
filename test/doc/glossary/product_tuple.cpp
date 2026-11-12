/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;
  kumi::tuple<int, float, char> t = {42, 13.37f, 'd'};

  // the index 0 computes the first projection
  std::cout << t << '\n';
  std::cout << t[0_c] << " and " << kumi::get<0>(t) << '\n';
}
