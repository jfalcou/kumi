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
  auto r1 = kumi::record{"a"_id = 2.,"b"_id = 5,"c"_id = short{3},"d"_id = '\4'};
  auto r2 = kumi::record{"a"_id = 2 ,"b"_id = 1,"c"_id = short{55},"d"_id = ' '};

  auto times_two = [&](auto e){ return 2*e; };
  std::cout << kumi::map_reduce(times_two, kumi::function::multiplies, r1) << "\n";

  auto is_pair = [&](auto e){ return e%2==0; };
  std::cout << kumi::map_reduce(is_pair, kumi::function::plus, r2)        << "\n";
}
