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

  kumi::tuple t = { "x"_n = 1, "y"_n = 2.3, "z"_n = 4.5f, "t"_n = '@' };
  std::cout << t << "\n";
  std::cout << t["x"_n] << "\n";
  std::cout << t["y"_n] << "\n";
  std::cout << t["z"_n] << "\n";

  t["t"_n]++;

  std::cout << t["t"_n] << "\n";
}
