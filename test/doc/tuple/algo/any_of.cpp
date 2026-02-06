/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{1,2.,3.f};
  std::cout << std::boolalpha << kumi::any_of( t, [](auto e) { return e == 2; }) << "\n";

  auto u = kumi::tuple{true,false,true,false};
  std::cout << std::boolalpha << kumi::any_of(u) << "\n";
}
