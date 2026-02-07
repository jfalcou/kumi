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

  kumi::tuple t = { "x"_id = 1, "y"_id = 2.3, "z"_id = 4.5f, "t"_id = '@' };
  std::cout << t << "\n";
  std::cout << t["x"_id] << "\n";
  std::cout << t["y"_id] << "\n";
  std::cout << t["z"_id] << "\n";

  t["t"_id]++;

  std::cout << t["t"_id] << "\n";
}
