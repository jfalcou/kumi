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

  auto r      = kumi::record{"a"_id = 1,"b"_id = 2, "c"_id = 3};
  auto nest_1 = kumi::record{"e"_id = r};
  auto nest_2 = kumi::record{"f"_id = nest_1};

  auto r2 = kumi::record{"g"_id = nest_1, "h"_id = nest_2};

  std::cout << kumi::compress( nest_2 ) << "\n";
  std::cout << kumi::compress( r2 ) << "\n";
}
