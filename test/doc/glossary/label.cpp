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
  kumi::record r = {"x"_id = 42, "y"_id = 13.37f};

  // a label, a kumi::str, reads a field of a record by name
  std::cout << kumi::get<"x">(r) << '\n';
  std::cout << r["y"_l] << '\n';

  // label() of a field type returns its label
  using velocity = decltype("velocity"_id = 1.f);
  std::cout << velocity::label() << '\n';
}
