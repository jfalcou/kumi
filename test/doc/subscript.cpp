//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::tuple t = { 1, 2.3, 4.5f, '@' };

  std::cout << t[0_c] << "\n";
  std::cout << t[1_c] << "\n";
  std::cout << t[2_c] << "\n";

  t[3_c]++;

  std::cout << t[kumi::index<3>] << "\n";
}
