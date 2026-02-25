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

  auto n = "Peter"_id;
  auto s = kumi::name<"Jackson">{};

  std::cout << n << "\n";
  std::cout << s << "\n";
}
