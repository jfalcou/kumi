/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple a = { 65, 2.3, 4.5f};
  auto b = static_cast<kumi::tuple<char,int,double>>(a);

  std::cout << a << "\n";
  std::cout << b << "\n";
}
