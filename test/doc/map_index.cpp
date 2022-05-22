//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto lhs = kumi::tuple{1,2,3};
  auto rhs = kumi::tuple{2.4,4.6,6.8};

  auto r = kumi::map_index( [](auto i, auto l, auto r) { return 1000*(i+1)+(l*r); }
                          , lhs, rhs
                          );

  std::cout << r << "\n";
}
