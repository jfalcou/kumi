/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

using namespace kumi::literals;

template<typename T>
struct is_big : std::bool_constant<(sizeof(T) > 2)> {};

inline constexpr auto large_value = kumi::identifier("large"_n, kumi::if_<is_big>);

int main()
{
  std::cout << kumi::record{ large_value = 9.6 } << "\n";
}
