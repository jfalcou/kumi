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
  auto r = kumi::record{"a"_id = 2.,"b"_id = 1,"c"_id = short{55},"d"_id = ' '};

  std::cout << kumi::sum(r, 100) << "\n";
  std::cout << kumi::sum(r) << "\n";
}
