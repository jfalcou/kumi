//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{1,2.,3.f};
  std::cout << std::boolalpha << kumi::any_of( t, [](auto e) { return e == 2; }) << "\n";
}
