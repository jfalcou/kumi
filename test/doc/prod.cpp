/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{2.,5,short{3},'\4'};

  std::cout << kumi::prod(t, 1) << "\n";
}
