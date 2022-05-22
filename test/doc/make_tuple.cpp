//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <functional>
#include <iostream>

int main()
{
  int k = 99;
  auto t = kumi::make_tuple( 1, 2.3, 4.5f, '@', std::ref(k));

  std::cout << t << "\n";

  // Reference access
  get<4>(t)++;
  std::cout << k << "\n";
}
