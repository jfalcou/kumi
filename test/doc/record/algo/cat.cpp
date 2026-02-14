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

  kumi::record a = { "r"_id = 1,"g"_id = 2.3, "b"_id = 4.5f};
  kumi::record b = { "x"_id = '6' };
  kumi::record c = { "y"_id = "7", "z"_id = short{89} };

  auto abc = cat(a,b,c);

  std::cout << a << " " << b << " " << c << "\n";
  std::cout << abc << "\n";
}