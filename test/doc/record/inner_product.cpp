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

  auto bits = kumi::record{"a"_f= 1,"b"_f= 0,"c"_f=1,"d"_f=0,"e"_f=0,"f"_f=1};
  auto base = kumi::record{"f"_f=1,"e"_f=2,"d"_f=4,"c"_f=8,"b"_f=16,"a"_f=32};

  std::cout << 0b101001L << "\n";
  std::cout << kumi::inner_product(bits, base, 0) << "\n";
}
