/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

using namespace kumi::literals;

auto generate()
{
  return kumi::record{"i"_n = 1,"d"_n = 2.3,"f"_n = 4.56f};
}

int main()
{
  int    i;
  double d;
  float  f;

  kumi::tie<"i"_n, "d"_n, "f"_n>( i,d,f ) = generate();

  std::cout << i << " " << d << " " << f << "\n";
}
