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
  auto t = kumi::record{"a"_id = 1,"b"_id = short{8},"c"_id = ' ', "d"_id = 4ULL};

  std::cout << kumi::bit_or(t, 0) << "\n";
  std::cout << kumi::bit_or(t) << "\n";
}
