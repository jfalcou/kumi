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

  kumi::tuple t = { "x"_n = 1, "y"_n = 2.3, "z"_n = 4.5f, "t"_n = '@' };
  
  std::cout << t["x"_n] << "\n"; 
  std::cout << kumi::get<"x"_n>(t) << "\n";
  std::cout << kumi::get<"y"_n>(t) << "\n";
  std::cout << kumi::get<"z"_n>(t) << "\n";

  kumi::get<"t"_n>(t)++;

  std::cout << kumi::get<"t"_n>(t) << "\n";
}
