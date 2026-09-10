/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto f0 = kumi::tuple {1, 'A', -9.77f, 3. };
  auto f1 = kumi::tuple {2., f0, 3.f };

  std::cout << kumi::min(f0, [](auto m) { return sizeof(m); }) << "\n";
  std::cout << kumi::min(f1, [](auto m) { return sizeof(m); }) << "\n";
}
