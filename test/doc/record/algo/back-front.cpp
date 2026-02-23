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

  kumi::record x{"a"_id = 2.3,"b"_id = 18, "c"_id = 5.f};

  std::cout << kumi::front(x) << "\n";
  std::cout << kumi::back(x)  << "\n";

  kumi::front(x) = 98.5;
  kumi::back(x)  = 66.f;

  std::cout << x << "\n";
}
