/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::record r = { "x"_id = 1, "y"_id = 2.3, "z"_id = 4.5f, "t"_id = '@' };

  std::cout << kumi::get<0>(r) << "\n";
  std::cout << kumi::get<1>(r) << "\n";
  std::cout << kumi::get<2>(r) << "\n";

  kumi::get<3>(r).value++;

  std::cout << kumi::get<3>(r) << "\n";
}
