//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>
#include <vector>

int main()
{
  auto bits = kumi::tuple{ 1, 0,1,0,0,1};
  auto base = kumi::tuple{32,16,8,4,2,1};

  std::cout << 0b101001L << "\n";
  std::cout << kumi::inner_product(bits, base, 0) << "\n";
}
