/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::tuple t = { "x"_m = 1, "y"_m = 2.3, "z"_m = 4.5f, "t"_m = '@' };
  std::cout << t << "\n";
  std::cout << t["x"_m] << "\n";
  std::cout << t["y"_m] << "\n";
  std::cout << t["z"_m] << "\n";

  t["t"_m]++;

  std::cout << t["t"_m] << "\n";
}
