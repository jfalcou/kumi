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
  auto values = kumi::tuple { 1, 'a', 0.1 };

  constexpr auto basic = kumi::indexes(2_c,1_c,0_c);
  constexpr auto stack = kumi::projection_map(2_c,1_c,0_c, kumi::indexes(0_c,1_c,2_c));
  constexpr auto pairs = kumi::projection_map(kumi::indexes(0_c,0_c), kumi::indexes(1_c,1_c));
  
  std::cout << values << "\n";
  std::cout << kumi::reindex<basic>(values) << "\n";
  std::cout << kumi::reindex<stack>(values) << "\n";
  std::cout << kumi::reindex<pairs>(values) << "\n";
}
