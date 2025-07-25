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

  kumi::tuple t = { 1, 2.3, 4.5f, '@' };

  std::cout << kumi::get<0>(t) << "\n";
  std::cout << kumi::get<1>(t) << "\n";
  std::cout << kumi::get<2>(t) << "\n";

  kumi::get<3>(t)++;

  std::cout << kumi::get<3>(t) << "\n";
}
