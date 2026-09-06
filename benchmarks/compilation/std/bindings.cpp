//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <tuple>
#include "payload.hpp"

int main()
{
  std::tuple<element<0>, element<1>, element<2>, element<3>> t;

  auto [a, b, c, d] = t;
  return a.value + b.value + c.value + d.value;
}
