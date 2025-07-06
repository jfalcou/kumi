/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::record r = { "x"_f = 1, "y"_f = 2.3, "z"_f = 4.5f, "t"_f = '@' };
  
  std::cout << r["x"_f] << "\n"; 
  std::cout << kumi::get<"x"_f>(r) << "\n";
  std::cout << kumi::get<"y"_f>(r) << "\n";
  std::cout << kumi::get<"z"_f>(r) << "\n";

  kumi::get<"t"_f>(r)++;

  std::cout << kumi::get<"t"_f>(r) << "\n";
}
