/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto f0 = kumi::tuple {1, 'A', 99.77f, 3. };
  auto f1 = kumi::tuple {2., f0, 3.f };

  std::cout << kumi::max(f0) << "\n";
  std::cout << kumi::max(f1, [](auto m) { return sizeof(m); }) << "\n";
}
