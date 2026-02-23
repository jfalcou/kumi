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
  kumi::record a = { "a"_id = 14.f, "b"_id = 42,"c"_id =  55, "d"_id = short{89} };
  auto b = kumi::member_cast<char>(a);

  std::cout << a << "\n";
  std::cout << b << "\n";
}
