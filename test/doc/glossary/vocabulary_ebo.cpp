/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

struct tag {};

// the empty member occupies a byte, then the padding before i
struct with_member { tag t; int i; };

// the empty base class occupies no byte
struct with_base : tag { int i; };

int main()
{
  std::cout << "int                   " << sizeof(int) << '\n';
  std::cout << "with_member           " << sizeof(with_member) << '\n';
  std::cout << "with_base             " << sizeof(with_base) << '\n';

  // the empty element of a kumi::tuple occupies no byte
  std::cout << "kumi::tuple<tag, int> " << sizeof(kumi::tuple<tag, int>)
            << '\n';
}
