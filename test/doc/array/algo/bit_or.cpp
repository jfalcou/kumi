/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto t = kumi::array{1,8,4};

  std::cout << kumi::bit_or(t, 0) << "\n";
  std::cout << kumi::bit_or(t) << "\n";
}
