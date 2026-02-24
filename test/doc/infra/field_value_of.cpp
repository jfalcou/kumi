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

  auto field = ( "x"_id = 1 ); 
  int standard = { 12 };

  std::cout << field << "\n";
  std::cout << kumi::field_value_of(field) << "\n";
  
  std::cout << standard << "\n";
  std::cout << kumi::field_value_of(standard) << "\n";
}
