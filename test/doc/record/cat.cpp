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

  kumi::record a = { "r"_f = 1,"g"_f = 2.3, "b"_f = 4.5f};
  kumi::record b = { "x"_f = '6' };
  kumi::record c = { "y"_f = "7", "z"_f = short{89} };

  auto abc = cat(a,b,c);

  std::cout << a << " " << b << " " << c << "\n";
  std::cout << abc << "\n";
}