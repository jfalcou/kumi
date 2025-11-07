/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{2.,5,short{3},'\4'};

  std::cout << kumi::prod(t, 10) << "\n";
  std::cout << kumi::prod(t) << "\n";
}
