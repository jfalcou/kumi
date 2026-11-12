/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

template<kumi::tuple<int, float> V> struct constant
{
  static constexpr auto value = V;
};

int main()
{
  // a kumi::tuple value as a template argument
  using c_t = constant<kumi::tuple<int, float>{1, 2.f}>;
  std::cout << c_t::value << '\n';
}
