/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto values = kumi::tuple {'A','B','C','D','E','F'};

  std::cout << values << "\n";
  std::cout << kumi::rotate_right<1>(values) << "\n";
  std::cout << kumi::rotate_right<3>(values) << "\n";
}
