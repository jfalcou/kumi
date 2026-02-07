/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <string>

using namespace kumi::literals;

inline constexpr auto modal = "modal window"_id = std::bool_constant<true>{};

int main()
{
  std::cout << kumi::record{ modal } << "\n";
}
