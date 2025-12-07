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
  auto nbrs       = kumi::record{"first"_f=1,"second"_f=2,"third"_f=3};
  auto more_nbrs  = kumi::record{"zero"_f=0,"nbrs"_f=nbrs,"fourth"_f=4};
  auto ltrs       = kumi::record{"a"_f='a',"b"_f='b',"c"_f='c'};

  auto r = kumi::flatten( kumi::record{"double"_f=3.5,"data"_f=nbrs,"id"_f='z'
                                      ,"data_bis"_f=more_nbrs,"float"_f=5.35f,"index"_f=ltrs} );
  std::cout << r << "\n";
}
