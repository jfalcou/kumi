/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::tuple a = { 1, 2.3, 4.5f,'6',"7", short{89} };

  auto head = extract(a,0_c,1_c);
  auto mid  = extract(a,1_c,3_c);
  auto last = extract(a,kumi::index<3>);

  std::cout << a << " => " << head << ' '  << mid << ' ' << last << '\n';
}
