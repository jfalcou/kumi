/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <array>
#include <iostream>
#include <vector>

void show(char const* text, bool b)
{
  std::cout << text << ": " << std::boolalpha << b << '\n';
}

int main()
{
  using kumi::concepts::container;
  using kumi::concepts::static_container;

  // a size known at compile time
  show("std::array is a static container",
       static_container<std::array<int, 3>>);
  show("int[3] is a static container", static_container<int[3]>);

  // a size known at run time only
  show("std::vector is a container", container<std::vector<int>>);
  show("std::vector is a static container",
       static_container<std::vector<int>>);
}
