/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

void show(char const* text, bool b)
{
  std::cout << text << ": " << std::boolalpha << b << '\n';
}

struct unit {};

int main()
{
  // an empty class with one value, unknown to the tuple protocol
  show("struct unit is a unit type", kumi::concepts::unit_type<unit>);
  show("struct unit is a product type", kumi::concepts::product_type<unit>);
}
