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
  auto t = kumi::record{"a"_id = 1,"b"_id = 2.,"c"_id = 3.f};
  std::cout << std::boolalpha << kumi::all_of( t, [](auto e) { return e < 5; }) << "\n";

  auto u = kumi::record{"a"_id = true,"b"_id = false,"c"_id = true, "d"_id = false};
  std::cout << std::boolalpha << kumi::all_of(u) << "\n";
}
