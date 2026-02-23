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
  auto t = kumi::record{"a"_id = 14,"b"_id = short{7}, "c"_id = 255ULL};

  std::cout << kumi::bit_and(t, 65535) << "\n";
  std::cout << kumi::bit_and(t) << "\n";
}
