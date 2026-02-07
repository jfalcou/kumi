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

  kumi::record a = { "r"_n = 1,"g"_n = 2.3, "b"_n = 4.5f};
  kumi::record b = { "x"_n = '6' };
  kumi::record c = { "y"_n = "7", "z"_n = short{89} };

  auto abc = cat(a,b,c);

  std::cout << a << " " << b << " " << c << "\n";
  std::cout << abc << "\n";
}