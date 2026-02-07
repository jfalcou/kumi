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

  kumi::record a = { "a"_n = 1, "b"_n = 2.3, "c"_n = 4.5f,"d"_n = '6',
                     "e"_n = "7", "f"_n = short{89} };

  auto[first, second] = split(a, 3_c);

  std::cout << a      << "\n";
  std::cout << first  << "\n";
  std::cout << second << "\n";
}