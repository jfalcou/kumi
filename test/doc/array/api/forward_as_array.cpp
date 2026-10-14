/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

template<typename Data>
int sum(Data d)
{
  return kumi::get<0>(d) + kumi::get<1>(d) + kumi::get<2>(d);
}

int main()
{
  int a = 1, b = 2, c = 3;

  // forward_as_array builds an array of references, here an array<int&, 3>.
  auto arr = kumi::forward_as_array(a, b, c);

  std::cout << sum(arr) << "\n";
}
