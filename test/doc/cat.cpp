/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  kumi::tuple a = { 1, 2.3, 4.5f};
  kumi::tuple b = {  '6' };
  kumi::tuple c = { "7", short{89} };

  auto abc = cat(a,b,c);

  std::cout << a << " " << b << " " << c << "\n";
  std::cout << abc << "\n";
}
