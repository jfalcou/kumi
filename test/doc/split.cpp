/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::tuple a = { 1, 2.3, 4.5f,'6',"7", short{89} };

  auto[first, second] = split(a, 3_c);

  std::cout << a      << "\n";
  std::cout << first  << "\n";
  std::cout << second << "\n";
}
