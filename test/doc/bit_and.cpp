/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{14,short{7}, 255ULL};

  std::cout << kumi::bit_and(t, 65535) << "\n";
}
