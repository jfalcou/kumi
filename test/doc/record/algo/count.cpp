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
  auto t = kumi::record{"a"_id = 1, "b"_id = 0, "c"_id = 2., "d"_id = nullptr
                      , "e"_id = 3.f, "f"_id = false, "g"_id = 'z'};
  std::cout << std::boolalpha << kumi::count(t ) << "\n";
}
