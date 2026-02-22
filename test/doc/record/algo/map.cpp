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
  auto lhs = kumi::record{"a"_id = 1,"b"_id = 2,"c"_id = 3};
  auto rhs = kumi::record{"a"_id = 2.5,"b"_id = 3.6,"c"_id = 4.7};

  auto res = kumi::map( [](auto l, auto r) { return l*r; }, lhs, rhs);

  std::cout << res << "\n";
}
