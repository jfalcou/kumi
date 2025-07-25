/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

auto generate()
{
  return kumi::tuple{1,2.3,4.56f};
}

int main()
{
  int    i;
  double d;
  float  f;

  kumi::tie( i,d,f ) = generate();

  std::cout << i << " " << d << " " << f << "\n";
}
