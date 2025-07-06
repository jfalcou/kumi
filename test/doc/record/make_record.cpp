/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <functional>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  int k = 99;
  auto t = kumi::make_record( "x"_f = 1, "y"_f = 2.3, "z"_f = 4.5f, "t"_f = '@', "m"_f = std::ref(k));

  std::cout << t << "\n";

  // Reference access
  kumi::get<"m"_f>(t)++;
  std::cout << k << "\n";
}
