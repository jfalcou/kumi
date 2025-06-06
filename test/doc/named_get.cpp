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

  kumi::tuple t = { "x"_m = 1, "y"_m = 2.3, "z"_m = 4.5f, "t"_m = '@' };
  
  std::cout << t["x"_m] << "\n"; 
  std::cout << kumi::get<"x"_m>(t) << "\n";
  std::cout << kumi::get<"y"_m>(t) << "\n";
  std::cout << kumi::get<"z"_m>(t) << "\n";

  kumi::get<"t"_m>(t)++;

  std::cout << kumi::get<"t"_m>(t) << "\n";
}
