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
  kumi::record r = {"x"_id = 42, "y"_id = 13.37f, "z"_id = 'd'};

  std::cout << r << '\n';

  // the identifier of the field, in the subscript or in get
  std::cout << r["x"_id] << " and " << kumi::get<"x"_id>(r) << '\n';

  // the label alone, a kumi::str
  std::cout << kumi::get<"x">(r) << '\n';
}
