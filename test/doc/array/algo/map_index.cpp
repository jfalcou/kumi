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
  auto rhs = kumi::tuple{2.4,4.6,6.8};

  auto res = kumi::map_index( [](auto i, auto l, auto r) { return 1000*(i+1)+(l*r); }
                            , lhs, rhs
                            );

  std::cout << res << "\n";
}
