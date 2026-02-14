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

  kumi::tuple t = { "x"_id = 1, "y"_id = 2.3, "z"_id = 4.5f, "t"_id = '@' };
  
  std::cout << t["x"_id] << "\n"; 
  std::cout << kumi::get<"x"_id>(t) << "\n";
  std::cout << kumi::get<"y"_id>(t) << "\n";
  std::cout << kumi::get<"z"_id>(t) << "\n";

  kumi::get<"t"_id>(t)++;

  std::cout << kumi::get<"t"_id>(t) << "\n";
}
