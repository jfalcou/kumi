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

  kumi::record a =  { "a"_id = 1, "b"_id = 2.3, "c"_id = 4.5f, "d"_id = '6'
                    , "e"_id = "7", "f"_id = short{89} };

  auto head = extract(a,0_c,1_c);
  auto mid  = extract(a,1_c,3_c);
  auto last = extract(a,kumi::index<3>);

  std::cout << a << " => " << head << ' '  << mid << ' ' << last << '\n';
}