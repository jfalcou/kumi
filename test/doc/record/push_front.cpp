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

  std::cout << kumi::push_front( kumi::record{}, "a"_f = 63.21)  << "\n";

  kumi::record t{"a"_f = 1,"b"_f = 2.,"c"_f = 3.4f};
  std::cout << t                          << "\n";
  std::cout << kumi::push_front(t, "d"_f = 'Z')   << "\n";
}