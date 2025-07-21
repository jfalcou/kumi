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
  std::cout << std::boolalpha << kumi::none_of( t, [](auto e) { return e > 10.; }) << "\n";
  std::cout << std::boolalpha << kumi::none_of( 8, [](auto e) { return e > 10.; }) << "\n";

  auto u = kumi::tuple{0,0.,0.f};
  std::cout << std::boolalpha << kumi::none_of( u ) << "\n";
}
