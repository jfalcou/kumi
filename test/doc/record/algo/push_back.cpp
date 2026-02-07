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

  std::cout << kumi::push_back( kumi::record{}, "a"_n = 63.21)  << "\n";

  kumi::record t{"a"_n = 1,"b"_n = 2.,"c"_n = 3.4f};
  std::cout << t                          << "\n";
  std::cout << kumi::push_back(t, "d"_n = 'Z')   << "\n";
}