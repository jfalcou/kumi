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
  auto values = kumi::record{"a"_id=1,"b"_id=2,"c"_id=3,"d"_id=4,"e"_id=5,"f"_id=6};

  std::cout << values << "\n";
  std::cout << kumi::rotate_right<1>(values) << "\n";
  std::cout << kumi::rotate_right<3>(values) << "\n";
}
