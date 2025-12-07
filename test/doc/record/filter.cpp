/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <type_traits>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  int     a = 4;
  double  b = 3.1415;
  float   c = 0.01f;

  auto original = kumi::record{"a"_f=a,"b"_f=&a,"c"_f=b,"d"_f=&b,"e"_f=c,"f"_f=&c,"g"_f='z',"h"_f=nullptr};
  std::cout << original << "\n";

  std::cout << "Pointers : " << kumi::filter<std::is_pointer>(original) << "\n";
  std::cout << "Real     : " << kumi::filter<std::is_floating_point>(original) << "\n";
  std::cout << "nullptr  : " << kumi::filter<std::is_null_pointer>(original) << "\n";
}
