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
  auto nbrs      = kumi::record{"f"_id = 1,"s"_id = 2ULL,"t"_id = 3};
  auto more_nbrs = kumi::record{"z"_id = short{0},"n"_id = nbrs,"l"_id = 4.};
  auto ltrs      = kumi::record{"alpha"_id = 'a',"beta"_id = 'b', "gamma"_id = 'c'};

  auto r = kumi::flatten_all( kumi::record{"a"_id = 3.5,"b"_id = nbrs,"c"_id = 'z'
                                          ,"d"_id = more_nbrs,"e"_id = 5.35f,"f"_id = ltrs} );
  std::cout << r << "\n";

  auto sz = kumi::flatten_all (kumi::record{"a"_id = 3.5,"b"_id = nbrs,"c"_id = 'z'
                                          ,"d"_id = more_nbrs,"e"_id = 5.35f,"f"_id = ltrs}
                              , [](auto e) { return sizeof(e); }
                              );
  std::cout << sz << "\n";
}