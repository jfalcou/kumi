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

  kumi::for_each( [](auto& m) { m *= 10.f; }
                , t
                );

  std::cout << t << "\n";
}
