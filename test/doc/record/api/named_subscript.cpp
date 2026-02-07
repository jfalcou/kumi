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
  std::cout << r << "\n";
  std::cout << r["x"_n] << "\n";
  std::cout << r["y"_n] << "\n";
  std::cout << r["z"_n] << "\n";

  r["t"_n]++;

  std::cout << r["t"_n] << "\n";
}
