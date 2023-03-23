/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{1,short{8},' ', 4ULL};

  std::cout << kumi::bit_or(t, 0) << "\n";
}
