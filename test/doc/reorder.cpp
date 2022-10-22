/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto values = kumi::tuple { 1, 'a', 0.1 };

  std::cout << values << "\n";
  std::cout << kumi::reorder<2,1,0>(values) << "\n";
  std::cout << kumi::reorder<2,1,0,1,2>(values) << "\n";
  std::cout << kumi::reorder<1,1>(values) << "\n";
}
