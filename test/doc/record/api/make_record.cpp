/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <functional>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  int k = 99;
  auto t = kumi::make_record( "x"_id = 1, "y"_id = 2.3, "z"_id = 4.5f, "t"_id = '@', "m"_id = std::ref(k));

  std::cout << t << "\n";

  // Reference access
  kumi::get<"m"_id>(t)++;
  std::cout << k << "\n";
}
