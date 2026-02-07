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

  kumi::record r = { "x"_n = 1, "y"_n = 2.3, "z"_n = 4.5f, "t"_n = '@' };

  std::cout << r[0_c] << "\n";
  std::cout << r[1_c] << "\n";
  std::cout << r[2_c] << "\n";

  r[3_c].value++;

  std::cout << r[kumi::index<3>] << "\n";
}
