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

  kumi::record r = { "x"_id = 1, "y"_id = 2.3, "z"_id = 4.5f, "t"_id = '@' };
  
  std::cout << r["x"_id] << "\n"; 
  std::cout << kumi::get<"x"_id>(r) << "\n";
  std::cout << kumi::get<"y"_id>(r) << "\n";
  std::cout << kumi::get<"z"_id>(r) << "\n";

  kumi::get<"t"_id>(r)++;

  std::cout << kumi::get<"t"_id>(r) << "\n";
}
