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

  auto values = kumi::record { "a"_f = 1, "b"_f = 'a', "c"_f = 0.1 };

  std::cout << values << "\n";
  std::cout << kumi::reverse(values) << "\n";
}