/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <type_traits>

int main()
{
  auto t = kumi::tuple{1, 2., 3.f, 'z'};
  std::cout << std::boolalpha
            << kumi::count_if( t, kumi::predicate<std::is_floating_point>() ) << "\n";
  std::cout << std::boolalpha
            << kumi::count_if( 2.3, kumi::predicate<std::is_floating_point>() ) << "\n";
}
