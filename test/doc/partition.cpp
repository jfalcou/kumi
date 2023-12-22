/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <type_traits>
#include <iostream>

int main()
{
  int     a = 4;
  double  b = 3.1415;
  float   c = 0.01f;

  auto original = kumi::tuple{a,&a,b,&b,c,&c,'z',nullptr};
  std::cout << original << "\n";

  std::cout << "Pointers first: " << kumi::partition<std::is_pointer>(original) << "\n";
  std::cout << "Real     first: " << kumi::partition<std::is_floating_point>(original) << "\n";
  std::cout << "nullptr  first: " << kumi::partition<std::is_null_pointer>(original) << "\n";
}
