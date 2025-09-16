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
  return kumi::record{"i"_f = 1,"d"_f = 2.3,"f"_f = 4.56f};
}

int main()
{
  int    i;
  double d;
  float  f;

  kumi::tie<"i"_f, "d"_f, "f"_f>( i,d,f ) = generate();

  std::cout << i << " " << d << " " << f << "\n";
}