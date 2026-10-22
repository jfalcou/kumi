/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  kumi::array x{2,3,4,5};

  std::cout << kumi::front(x) << "\n";
  std::cout << kumi::back(x)  << "\n";

  kumi::front(x) = 2;
  kumi::back(x)  = 5;

  std::cout << x << "\n";
}
