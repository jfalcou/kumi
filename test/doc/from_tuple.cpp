//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>
#include <string>

struct my_struct
{
  int         i;
  float       f;
  std::string name;
};

int main()
{
  auto a = kumi::make_tuple(1337, 2.3475f, "John");
  auto b = from_tuple<my_struct>( a );

  std::cout << a << "\n";
  std::cout << b.i << ' ' << b.f << ' ' << b.name << "\n";
}
