/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{1, 'y', 3.f, short{55}, -8, 66., "Pete"};

  auto w = kumi::windows<3>(t); 
  std::cout << "  Standard Windows " << "\n";
  std::cout << w << "\n";

  kumi::for_each([&](auto tile)
  {
    get<0>(tile)++;
  },w);
  std::cout << t << "\n";

  auto w2 = kumi::windows<3>(kumi::to_ref(t)); 
  std::cout << "  Windows with references " << "\n";
  std::cout << w2 << "\n";

  kumi::for_each([&](auto tile)
  {
    get<0>(tile)++;
  },w2);
  std::cout << t << "\n";   
}
