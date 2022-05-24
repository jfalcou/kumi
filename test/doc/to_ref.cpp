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
  auto original = kumi::make_tuple(0,'0',0.f);
  auto ref      = kumi::to_ref( original );

  std::cout << original << "\n";

  kumi::get<0>(ref) = 9;
  kumi::get<1>(ref) = 'z';
  kumi::get<2>(ref) = 3.14159f;

  std::cout << original << "\n";
}
