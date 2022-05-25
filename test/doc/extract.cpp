//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  using namespace kumi::literals;

  kumi::tuple a = { 1, 2.3, 4.5f,'6',"7", short{89} };

  auto head = a.extract(0_c,1_c);
  auto mid  = a.extract(1_c,3_c);
  auto last = a.extract(kumi::index<3>);

  std::cout << a << " => " << head << ' '  << mid << ' ' << last << '\n';
}
