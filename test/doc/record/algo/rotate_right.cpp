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
  auto values = kumi::record{"a"_n=1,"b"_n=2,"c"_n=3,"d"_n=4,"e"_n=5,"f"_n=6};

  std::cout << values << "\n";
  std::cout << kumi::rotate_right<1>(values) << "\n";
  std::cout << kumi::rotate_right<3>(values) << "\n";
}
