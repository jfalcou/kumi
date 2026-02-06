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

  kumi::record r = { "x"_f = 1, "y"_f = 2.3, "z"_f = 4.5f, "t"_f = '@' };

  std::cout << r[0_c] << "\n";
  std::cout << r[1_c] << "\n";
  std::cout << r[2_c] << "\n";

  r[3_c].value++;

  std::cout << r[kumi::index<3>] << "\n";
}
