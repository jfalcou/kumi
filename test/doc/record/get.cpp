/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/record.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::record r = { "x"_f = 1, "y"_f = 2.3, "z"_f = 4.5f, "t"_f = '@' };

  std::cout << kumi::get<0>(r) << "\n";
  std::cout << kumi::get<1>(r) << "\n";
  std::cout << kumi::get<2>(r) << "\n";

  kumi::get<3>(r)++;

  std::cout << kumi::get<3>(r) << "\n";
}
