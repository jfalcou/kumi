//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  kumi::tuple a = { 65, 2.3, 4.5f};
  auto b = a.cast<char,int,double>();

  std::cout << a << "\n";
  std::cout << b << "\n";
}
