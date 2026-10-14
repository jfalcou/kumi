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

  kumi::array a = { 1, 2, 3, 4 };

  std::cout << a[0_c] << "\n";
  std::cout << a[1_c] << "\n";
  std::cout << a[2_c] << "\n";

  a[3_c]++;

  std::cout << a[kumi::index<3>] << "\n";
}
