//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto f0 = kumi::tuple {2., kumi::tuple {1., 'u', 3. }, 3.f };

  std::cout << kumi::min(f0, [](auto m) { return sizeof(m); }) << "\n";
}
