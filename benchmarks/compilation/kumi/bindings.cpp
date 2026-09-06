//======================================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <kumi/tuple.hpp>
#include "payload.hpp"

int main()
{
  kumi::tuple<elem<0>, elem<1>, elem<2>, elem<3>> t;

  auto [a, b, c, d] = t;
  return a.value + b.value + c.value + d.value;
}
