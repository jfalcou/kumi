/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>
#include <type_traits>

int main()
{
  auto t = kumi::tuple{1, 0, 2., nullptr, 3.f, false, 'z'};
  std::cout << std::boolalpha << kumi::count(t ) << "\n";
  std::cout << std::boolalpha << kumi::count(7.89) << "\n";
}
