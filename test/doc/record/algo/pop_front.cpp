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
  std::cout << kumi::pop_front( kumi::record{} )  << "\n";

  kumi::record r{"a"_id = 1,"b"_id = 2.,"c"_id = 3.4f};
  std::cout << r                    << "\n";
  std::cout << kumi::pop_front(r)   << "\n";
}
