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

  auto nbrs  = kumi::record{"a"_id=1  ,"b"_id=2   ,"c"_id=3    };
  auto ltrs  = kumi::record{"d"_id='a',"e"_id='b' ,"f"_id='c'  };
  auto ratio = kumi::record{"g"_id=0.1,"h"_id=0.01,"i"_id=0.001};

  auto r = kumi::zip( nbrs, ltrs, ratio );
  std::cout << r << "\n";
}
