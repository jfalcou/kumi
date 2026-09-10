/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto t      = kumi::tuple{1,2,3};
  auto nest_1 = kumi::tuple{t};
  auto nest_2 = kumi::tuple{nest_1};

  auto t2 = kumi::tuple{nest_1, nest_2};

  std::cout << kumi::compress( nest_2 ) << "\n";
  std::cout << kumi::compress( t2 ) << "\n";
}
