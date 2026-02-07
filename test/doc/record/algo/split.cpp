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

  kumi::record a = { "a"_id = 1, "b"_id = 2.3, "c"_id = 4.5f,"d"_id = '6',
                     "e"_id = "7", "f"_id = short{89} };

  auto[first, second] = split(a, 3_c);

  std::cout << a      << "\n";
  std::cout << first  << "\n";
  std::cout << second << "\n";
}