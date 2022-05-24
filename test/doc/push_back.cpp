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
  std::cout << kumi::push_back( kumi::tuple{}, 63.21)  << "\n";

  kumi::tuple t{1,2.,3.4f};
  std::cout << t                          << "\n";
  std::cout << kumi::push_back(t, 'Z')   << "\n";
}
