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
  auto values = kumi::record{"a"_f=1,"b"_f=2,"c"_f=3,"d"_f=4,"e"_f=5,"f"_f=6};

  std::cout << values << "\n";
  std::cout << kumi::rotate_right<1>(values) << "\n";
  std::cout << kumi::rotate_right<3>(values) << "\n";
}
