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

  // It is possible to have mixed nammed and unnamed fields
  std::cout << t["x"_f] << "\n";
  std::cout << t[1_c] << "\n";
  std::cout << t[2_c] << "\n";

  t["z"_f]++;

  std::cout << t[kumi::field<"z">] << "\n";
}
