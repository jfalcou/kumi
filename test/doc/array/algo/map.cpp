/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto lhs = kumi::tuple{1,2,3};
  auto rhs = kumi::tuple{2.5,3.6,4.7};

  auto res = kumi::map( [](auto l, auto r) { return l*r; }, lhs, rhs);

  std::cout << res << "\n";
}
