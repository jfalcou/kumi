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

  kumi::record r = { "x"_n = 1, "y"_n = 2.3, "z"_n = 4.5f, "t"_n = '@' };
  
  std::cout << r["x"_n] << "\n"; 
  std::cout << kumi::get<"x"_n>(r) << "\n";
  std::cout << kumi::get<"y"_n>(r) << "\n";
  std::cout << kumi::get<"z"_n>(r) << "\n";

  kumi::get<"t"_n>(r)++;

  std::cout << kumi::get<"t"_n>(r) << "\n";
}
