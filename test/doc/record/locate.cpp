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
  using namespace kumi::literals;

  auto r = kumi::record{"a"_f = 1, "b"_f = 2., "c"_f = 0ULL, "d"_f = 3.f, "e"_f = 'z'};

  std::cout << std::boolalpha
            << kumi::locate( r, kumi::predicate<std::is_floating_point>() ) << "\n";

  std::cout << std::boolalpha << kumi::locate( r, [](auto e) { return e > 3; } ) << "\n";
}
