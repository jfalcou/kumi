/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/record.hpp>
#include <iostream>

using namespace kumi::literals;

auto generate()
{
  return kumi::record{"x"_f = 1, "y"_f = 2.3, "z"_f = 4.56f};
}

int main()
{

  int    i;
  double d;
  float  f;

  /*
  kumi::field_capture<"x", int    > i;
  kumi::field_capture<"y", double > d;
  kumi::field_capture<"z", float  > f;
*/

  kumi::tie( "x"_f = i, "y"_f = d, "z"_f = f ) = generate();

  std::cout << i << " " << d << " " << f << "\n";
}
