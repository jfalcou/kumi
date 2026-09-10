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
    
  auto c = kumi::chunks<2>(t); 
  std::cout << "  Standard Chunks " << "\n";
  std::cout << c << "\n";

  kumi::for_each([&](auto tile)
  {
    get<0>(tile)++;
  },c);
  std::cout << t << "\n";

  auto c2 = kumi::chunks<2>(kumi::to_ref(t));
  std::cout << "  Chunks with references " << "\n";
  std::cout << c2 << "\n";

  kumi::for_each([&](auto tile)
  {
    get<0>(tile)++;
  },c2);
  std::cout << t << "\n";
}
