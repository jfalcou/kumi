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

  kumi::tuple t = { "x"_f = 1, 2.3, 4.5f, "z"_f = '@' };
  kumi::record r = {"x"_f = 1, "y"_f = 2.f, "z"_f = '#', "t"_f = 12};

  std::cout << kumi::values_of(t) << "\n";
  std::cout << kumi::values_of(r) << "\n";
}
