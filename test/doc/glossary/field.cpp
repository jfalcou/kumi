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

  // binding the identifier "x"_id to the value 42 builds a kumi::field
  auto f = ("x"_id = 42);

  std::cout << f << '\n';
  std::cout << f.value << '\n';
}
