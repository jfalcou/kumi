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
  auto t = kumi::tuple{1, 2., 0ULL, 3.f, 'z'};

  std::cout << std::boolalpha
            << kumi::locate( t, kumi::predicate<std::is_floating_point>() ) << "\n";

  std::cout << std::boolalpha << kumi::locate( t, [](auto e) { return e > 3; } ) << "\n";
}
