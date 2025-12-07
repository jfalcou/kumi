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

  auto values = kumi::record{ "first"_f  = kumi::record{"a"_f=1, "b"_f='a', "c"_f=0.1   }
                            , "second"_f = kumi::record{"d"_f=2, "e"_f='b', "f"_f=0.01  }
                            };

  auto r = kumi::transpose( values );
  std::cout << r << "\n";
}
