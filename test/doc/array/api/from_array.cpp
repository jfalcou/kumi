/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

struct point3
{
  int x, y, z;
};

int main()
{
  kumi::array<int, 3> a = { 1, 2, 3 };
  auto p = kumi::from_array<point3>( a );

  std::cout << p.x << ' ' << p.y << ' ' << p.z << "\n";
}
