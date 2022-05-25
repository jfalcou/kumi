//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>
#include <type_traits>

int main()
{
  auto t = kumi::tuple{1, 2., 3.f, 'z'};
  std::cout << std::boolalpha
            << kumi::count_if( t, kumi::predicate<std::is_floating_point>() ) << "\n";
}
