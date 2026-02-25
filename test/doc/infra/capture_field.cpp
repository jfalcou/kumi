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

  int field = { 1 }; 

  std::cout << field << "\n";
  std::cout << kumi::capture_field<"x"_id>(field) << "\n";
}
