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
  kumi::array b = {  6 };
  kumi::array c = { 7, 89 };

  auto abc = kumi::cat(a,b,c);

  std::cout << a << " " << b << " " << c << "\n";
  std::cout << abc << "\n";
}
