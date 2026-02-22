/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;
  auto r = kumi::record{"a"_id = 2.,"b"_id = 1,"c"_id = short{55},"d"_id = 'z'};

  auto output = kumi::inclusive_scan_right( [](auto elt, auto acc) 
                  { 
                    return acc + sizeof(elt); 
                  }
                  , r
                  , std::size_t{42}                
                );

  std::cout << output << "\n"; 

  auto u = kumi::record{"a"_id = 1,"b"_id = 3,"c"_id = 2,"d"_id = 4, "e"_id = 0
                      , "f"_id = 5,"g"_id = 9,"h"_id = 6,"i"_id = 7};

  std::cout << kumi::inclusive_scan_right(kumi::function::plus, u) << "\n";
}
