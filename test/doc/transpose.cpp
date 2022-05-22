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
  auto values = kumi::tuple { kumi::tuple{ 1, 'a', 0.1   }
                            , kumi::tuple{ 2, 'b', 0.01  }
                            };

  auto r = kumi::transpose(values );
  std::cout << r << "\n";
}
