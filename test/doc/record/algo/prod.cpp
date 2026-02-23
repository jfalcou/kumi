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
  auto r = kumi::record{"a"_id = 2.,"b"_id = 5,"c"_id = short{3},"d"_id = '\4'};

  std::cout << kumi::prod(r, 10) << "\n";
  std::cout << kumi::prod(r) << "\n";
}
