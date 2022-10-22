/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto nbrs  = kumi::tuple{1,2,3};
  auto ltrs  = kumi::tuple{'a','b','c'};
  auto ratio = kumi::tuple{0.1,0.01,0.001};

  auto r = kumi::zip( nbrs, ltrs, ratio );
  std::cout << r << "\n";
}
