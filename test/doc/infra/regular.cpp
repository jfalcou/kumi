/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <string>

using namespace kumi::literals;

inline constexpr auto name = kumi::identifier("name"_n);

int main()
{
  std::cout << kumi::record{ name = std::string{"Jane Doe"} } << "\n";
}
