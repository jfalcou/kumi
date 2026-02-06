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

  kumi::tuple t = { "x"_f = 1, "y"_f = 2.3, "z"_f = 4.5f, "t"_f = '@' };
  
  std::cout << t["x"_f] << "\n"; 
  std::cout << kumi::get<"x"_f>(t) << "\n";
  std::cout << kumi::get<"y"_f>(t) << "\n";
  std::cout << kumi::get<"z"_f>(t) << "\n";

  kumi::get<"t"_f>(t)++;

  std::cout << kumi::get<"t"_f>(t) << "\n";
}
