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
  std::tuple<elem<0>, elem<1>, elem<2>, elem<3>> t;

  auto [a, b, c, d] = t;
  return a.value + b.value + c.value + d.value;
}
