/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  using target_t = kumi::tuple<int, bool, float, long>;

  kumi::tuple a = { 14.f, 42, '7', short{89} };
  
  auto b = kumi::tuple_cast<target_t>(a);

  std::cout << a << "\n";
  std::cout << b << "\n";
}
