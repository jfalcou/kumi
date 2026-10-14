/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto original = kumi::make_array(0, 1, 2, 3, 4, 5);
  auto ref      = kumi::to_ref( original );

  std::cout << original << "\n";

  kumi::get<0>(ref) = 10;
  kumi::get<1>(ref) = 11;
  kumi::get<2>(ref) = 12;

  std::cout << original << "\n";
}
