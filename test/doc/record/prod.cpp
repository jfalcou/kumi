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

  auto t = kumi::record{"a"_f = 2.,"b"_f = 5,"c"_f = short{3},"d"_f = '\4'};

  std::cout << kumi::prod(t, 10) << "\n";
  std::cout << kumi::prod(t) << "\n";
}