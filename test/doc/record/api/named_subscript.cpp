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

  kumi::record r = { "x"_id = 1, "y"_id = 2.3, "z"_id = 4.5f, "t"_id = '@' };
  std::cout << r << "\n";
  std::cout << r["x"_id] << "\n";
  std::cout << r["y"_id] << "\n";
  std::cout << r["z"_id] << "\n";

  r["t"_id]++;

  std::cout << r["t"_id] << "\n";
}
