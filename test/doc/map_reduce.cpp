/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto times_two = [&](auto e){ return 2*e; };
  auto t1 = kumi::tuple{2.,5,short{3},'\4'};
  std::cout << kumi::reduce(times_two, kumi::function::multiplies, t1) << "\n";

  auto is_pair = [&](auto e){ return e%2==0; };
  auto t2 = kumi::tuple{2.,1,short{55},' '};
  std::cout << kumi::reduce(kumi::function::bit_and, t2)        << "\n";
}
