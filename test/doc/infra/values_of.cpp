/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::tuple t = { "x"_id = 1, 2.3, 4.5f, "z"_id = '@' };
  kumi::record r = {"x"_id = 1, "y"_id = 2.f, "z"_id = '#', "t"_id = 12};

  std::cout << kumi::values_of(t) << "\n";
  std::cout << kumi::values_of(r) << "\n";
}
