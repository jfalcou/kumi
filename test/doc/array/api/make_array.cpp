/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  // The element type is deduced from the (identical) types of the arguments.
  auto a = kumi::make_array( 1, 2, 3, 4 );

  std::cout << a << "\n";
}
