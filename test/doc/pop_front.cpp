//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  std::cout << kumi::pop_front( kumi::tuple{} )  << "\n";

  kumi::tuple t{1,2.,3.4f};
  std::cout << t                    << "\n";
  std::cout << kumi::pop_front(t)   << "\n";
}
