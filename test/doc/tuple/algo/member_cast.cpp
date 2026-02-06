/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple a = { 14.f, 42, 55, short{89} };
  auto b = kumi::member_cast<char>(a);

  std::cout << a << "\n";
  std::cout << b << "\n";
}
