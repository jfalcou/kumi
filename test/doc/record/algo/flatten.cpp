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
  auto nbrs       = kumi::record{"a"_id = 1,"b"_id = 2,"c"_id = 3};
  auto more_nbrs  = kumi::record{"a"_id = 0,"b"_id = nbrs,"c"_id = 4};
  auto ltrs       = kumi::record{"a"_id = 'a',"b"_id = 'b',"c"_id = 'c'};

  auto r = kumi::flatten( kumi::record{"a"_id = 3.5,"b"_id = nbrs,"c"_id = 'z'
                          ,"d"_id = more_nbrs,"e"_id = 5.35f,"f"_id = ltrs} );
  std::cout << r << "\n";
}
