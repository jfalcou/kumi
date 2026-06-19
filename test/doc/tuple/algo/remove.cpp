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

  kumi::tuple a = { 1, 2.3, 4.5f,'6',"7", short{89} };

  auto last = kumi::remove(a,0_c,1_c);
  auto mid  = kumi::remove(a,1_c,3_c);
  auto head = kumi::remove(a,kumi::index<3>);

  std::cout << a << " => " << head << ' '  << mid << ' ' << last << '\n';
}
