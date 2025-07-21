/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple t = { 1, 2.3, 4.5f, '@' };
  
  std::cout << kumi::get<int>(t)    << "\n";
  std::cout << kumi::get<double>(t) << "\n";
  std::cout << kumi::get<float>(t)  << "\n";

  kumi::get<char>(t)++;

  std::cout << kumi::get<char>(t) << "\n";
}
