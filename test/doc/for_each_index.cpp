//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{ 1, 2.3, 0.43f };

  kumi::for_each_index( [](auto i, auto& m) { m += (i+1)*10; }
                      , t
                      );

  std::cout << t << "\n";
}
