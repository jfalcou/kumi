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
  std::cout << kumi::pop_back( kumi::tuple{} )  << "\n";

  kumi::tuple t{1,2.,3.4f};
  std::cout << t                    << "\n";
  std::cout << kumi::pop_back(t)   << "\n";
}
