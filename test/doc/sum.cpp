/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{2.,1,short{55},' '};

  std::cout << kumi::sum(t, 0) << "\n";

}
