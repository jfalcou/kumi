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
  auto t = kumi::record{"a"_id = 1, "b"_id = 'y', "c"_id = 3.f, "d"_id = short{55}
                      , "e"_id = -8, "f"_id = 66., "g"_id = "Pete"};
    
  auto c = kumi::chunks<2>(t); 
  std::cout << "  Standard Chunks " << "\n";
  std::cout << c << "\n";

  kumi::for_each([&](auto tile)
  {
    get<0>(kumi::values_of(tile))++;
  },c);
  std::cout << t << "\n";

  auto c2 = kumi::chunks<2>(kumi::to_ref(t));
  std::cout << "  Chunks with references " << "\n";
  std::cout << c2 << "\n";

  kumi::for_each([&](auto tile)
  {
    get<0>(kumi::values_of(tile))++;
  },c2);
  std::cout << t << "\n";
}
