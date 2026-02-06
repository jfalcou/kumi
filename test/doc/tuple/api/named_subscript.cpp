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

  kumi::tuple t = { "x"_f = 1, "y"_f = 2.3, "z"_f = 4.5f, "t"_f = '@' };
  std::cout << t << "\n";
  std::cout << t["x"_f] << "\n";
  std::cout << t["y"_f] << "\n";
  std::cout << t["z"_f] << "\n";

  t["t"_f]++;

  std::cout << t["t"_f] << "\n";
}
