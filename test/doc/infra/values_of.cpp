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

  kumi::tuple t = { "x"_n = 1, 2.3, 4.5f, "z"_n = '@' };
  kumi::record r = {"x"_n = 1, "y"_n = 2.f, "z"_n = '#', "t"_n = 12};

  std::cout << kumi::values_of(t) << "\n";
  std::cout << kumi::values_of(r) << "\n";
}
