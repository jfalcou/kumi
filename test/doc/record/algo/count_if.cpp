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
  auto r = kumi::record{"a"_id = 1, "b"_id = 2.,"c"_id =  3.f, "d"_id = 'z'};
  std::cout << std::boolalpha
            << kumi::count_if( r, kumi::predicate<std::is_floating_point>() ) << "\n";
}
