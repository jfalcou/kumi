/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  kumi::tuple a = { 65, 2.3, 4.5f};
  auto b = a.cast<char,int,double>();

  std::cout << a << "\n";
  std::cout << b << "\n";
}
