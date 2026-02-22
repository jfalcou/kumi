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
  auto values = kumi::record { "a"_id = 1, "b"_id = 'a', "c"_id = 0.1 };

  constexpr auto basic = kumi::indexes(2,1,0);
  
  std::cout << values << "\n";
  std::cout << kumi::reindex<basic>(values) << "\n";
}
