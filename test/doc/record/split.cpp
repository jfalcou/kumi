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

  kumi::record a = { "a"_f = 1, "b"_f = 2.3, "c"_f = 4.5f,"d"_f = '6',
                     "e"_f = "7", "f"_f = short{89} };

  auto[first, second] = split(a, 3_c);

  std::cout << a      << "\n";
  std::cout << first  << "\n";
  std::cout << second << "\n";
}