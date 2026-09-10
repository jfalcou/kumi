/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  kumi::array a = { 65, 2, 4};
  auto b = static_cast<kumi::array<char,char,char>>(a);

  std::cout << a << "\n";
  std::cout << b << "\n";
}
