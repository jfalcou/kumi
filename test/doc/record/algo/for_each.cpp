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

  auto t = kumi::record{ "a"_n = 1, "b"_n = 2.3, "c"_n = 0.43f };

  kumi::for_each( [](auto& m) { m *= 10; }
                , t
                );

  std::cout << t << "\n";
}
