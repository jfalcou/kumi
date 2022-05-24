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
  auto nbrs       = kumi::tuple{1,2,3};
  auto more_nbrs  = kumi::tuple{0,nbrs,4};
  auto ltrs       = kumi::tuple{'a','b','c'};

  auto r = kumi::flatten( kumi::tuple{3.5,nbrs,'z',more_nbrs,5.35f,ltrs} );
  std::cout << r << "\n";
}
