/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto values = kumi::tuple { 1, 'a', 0.1 };

  std::cout << values << "\n";
  std::cout << kumi::reverse(values) << "\n";
}
