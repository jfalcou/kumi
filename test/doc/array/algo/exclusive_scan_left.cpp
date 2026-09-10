/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{2.,1,short{55},'z'};

  auto output = kumi::exclusive_scan_left( [](auto acc, auto elt) 
                  { 
                    return acc + sizeof(elt); 
                  }
                  , t
                  , std::size_t{42}                
                );

  std::cout << output << "\n"; 

  auto u = kumi::tuple{1,3,2,4,0,5,9,6,7};

  std::cout << kumi::exclusive_scan_left(kumi::function::plus, u) << "\n";
}
