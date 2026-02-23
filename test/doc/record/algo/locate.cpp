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
  auto r = kumi::record{"a"_id = 1, "b"_id = 2., "c"_id = 0ULL, "d"_id = 3.f, "e"_id = 'z'};

  std::cout << std::boolalpha
            << kumi::locate( r, kumi::predicate<std::is_floating_point>() ) << "\n";

  std::cout << std::boolalpha << kumi::locate( r, [](auto e) { return e > 3; } ) << "\n";
}