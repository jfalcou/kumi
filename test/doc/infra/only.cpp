/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

using namespace kumi::literals;

inline constexpr auto char_value  = kumi::identifier("character"_id, kumi::only<char>);

int main()
{
  std::cout << kumi::record{ char_value  = 'Z' } << "\n";
}
