//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto lhs = kumi::tuple{1,2,3};
  auto rhs = kumi::tuple{2.5,3.6,4.7};

  auto r = kumi::map( [](auto l, auto r) { return l*r; }, lhs, rhs);

  std::cout << r << "\n";
}
