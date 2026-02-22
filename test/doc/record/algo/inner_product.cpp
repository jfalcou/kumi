/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <vector>

int main()
{
  using namespace kumi::literals;
  auto bits = kumi::record{"a"_id = 1, "b"_id = 0, "c"_id = 1, "d"_id = 0,"e"_id = 0,"f"_id = 1};
  auto base = kumi::record{"f"_id = 32,"e"_id = 16,"d"_id = 8,"c"_id = 4,"b"_id = 2,"a"_id = 1};

  std::cout << 0b101001L << "\n";
  std::cout << kumi::inner_product(bits, base, 0) << "\n";
}
