/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  kumi::tuple t = { 1, 2.3, 4.5f, '@' };

  // It is possible to have mixed nammed and unnamed fields
  std::cout << t[ kumi::as<int>{}    ] << "\n";
  std::cout << t[ kumi::as<double>{} ] << "\n";
  std::cout << t[ kumi::as<float>{}  ] << "\n";

  t[kumi::as<int>{}]++;

  std::cout << t[kumi::as<int>{}] << "\n";
}
