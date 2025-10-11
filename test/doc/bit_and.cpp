/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{14,short{7}, 255ULL};

  std::cout << kumi::fold_left(kumi::function::bit_and, t, 65535) << "\n";
  std::cout << kumi::reduce(kumi::function::bit_and, t) << "\n";
}
