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

  kumi::record r = { "a"_id=1,"b"_id=2.3,"c"_id=4.5f, "d"_id='@' };

  std::cout << r[ kumi::as<int>{}    ] << "\n";
  std::cout << r[ kumi::as<double>{} ] << "\n";
  std::cout << r[ kumi::as<float>{}  ] << "\n";

  r[kumi::as<int>{}]++;

  std::cout << r[kumi::as<int>{}] << "\n";
}
