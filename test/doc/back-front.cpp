/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  kumi::tuple x{2.3,18, 5.f};

  std::cout << kumi::front(x) << "\n";
  std::cout << kumi::back(x)  << "\n";

  kumi::front(x) = 98.5;
  kumi::back(x)  = 66.f;

  std::cout << x << "\n";
}
