/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  kumi::array a = { 1, 2, 3, 4 };

  std::cout << kumi::get<0>(a) << "\n";
  std::cout << kumi::get<1>(a) << "\n";
  std::cout << kumi::get<2>(a) << "\n";

  kumi::get<3>(a)++;

  std::cout << kumi::get<3>(a) << "\n";
}
