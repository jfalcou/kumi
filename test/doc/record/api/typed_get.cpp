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

  kumi::record r = {"a"_id=1, "b"_id=2.3, "c"_id=4.5f, "d"_id='@' };
  
  std::cout << kumi::get<int>(r)    << "\n";
  std::cout << kumi::get<double>(r) << "\n";
  std::cout << kumi::get<float>(r)  << "\n";

  kumi::get<char>(r)++;

  std::cout << kumi::get<char>(r) << "\n";
}
