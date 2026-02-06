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

  auto v = 42_c;
  auto w = kumi::index<63>;

  std::cout << v << "\n";
  std::cout << w << "\n";
}
