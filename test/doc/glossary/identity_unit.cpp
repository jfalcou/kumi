/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <cstddef>
#include <iostream>

void show(char const* text, bool b)
{
  std::cout << text << ": " << std::boolalpha << b << '\n';
}

int main()
{
  // the unit types of kumi, and its constant
  show("kumi::unit is a unit type", kumi::concepts::unit_type<kumi::unit>);
  show("kumi::tuple<> is a unit type",
       kumi::concepts::unit_type<kumi::tuple<>>);
  show("std::nullptr_t is a unit type",
       kumi::concepts::unit_type<std::nullptr_t>);
  std::cout << "kumi::none prints as " << kumi::none << '\n';
}
