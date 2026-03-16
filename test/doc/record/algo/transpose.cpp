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

  auto values = kumi::record{ "first"_id  = kumi::record{"a"_id=1, "b"_id='a', "c"_id=0.1   }
                            , "second"_id = kumi::record{"d"_id=2, "e"_id='b', "f"_id=0.01  }
                            };

  auto r = kumi::transpose( values );
  std::cout << r << "\n";
}
