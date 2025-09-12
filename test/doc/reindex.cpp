/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto values = kumi::tuple { 1, 'a', 0.1 };

  constexpr auto basic = kumi::make_index_map(2,1,0);
  constexpr auto stack = kumi::make_index_map(2,1,0, kumi::make_index_map(0,1,2));
  constexpr auto pairs = kumi::make_index_map(kumi::make_index_map(0,0), kumi::make_index_map(1,1));
  
  std::cout << values << "\n";
  std::cout << kumi::reindex<basic>(values) << "\n";
  std::cout << kumi::reindex<stack>(values) << "\n";
  std::cout << kumi::reindex<pairs>(values) << "\n";
}
