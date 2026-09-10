/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

using namespace kumi::literals;

int main()
{
  auto r = kumi::record{ "name"_id = std::string{"kumi"}, "size"_id = 4 };

  kumi::for_each_field( [](auto field, auto& m)
                        { std::cout << field << " = " << m << "\n"; }
                      , r
                      );

  std::cout << "\n";
}
