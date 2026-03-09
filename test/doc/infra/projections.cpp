/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

using namespace kumi::literals;

int main()
{
  std::cout << kumi::projection_map{0_c, "a"_id} << "\n";
  std::cout << kumi::projection_map{0_c, 1_c, kumi::projection_map{2_c, 3_c}} << "\n\n"; 

  // Projections maps can be built from functions in simpler cases 
  std::cout << kumi::indexes(0_c, 1_c, 2_c) << "\n\n";
  std::cout << kumi::identifiers("a"_id, "b"_id) << "\n";
}
