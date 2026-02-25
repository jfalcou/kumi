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
  
  auto caster = ( "y"_id = 'x' );

  std::cout << field << "\n";
  std::cout << kumi::field_cast<char>(field) << "\n";
  std::cout << kumi::field_cast<decltype(caster)>(field) << "\n";
}
