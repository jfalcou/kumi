/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto t = [](auto p){ return 42.63 + p; };
  std::cout << kumi::generate<7>(t) << "\n";
}
