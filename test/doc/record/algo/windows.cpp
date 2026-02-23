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

  auto r = kumi::record{"a"_id = 1, "b"_id = 'y', "c"_id = 3.f, "d"_id = short{55}
                       ,"e"_id = -8, "f"_id = 66., "g"_id = "Pete"};

  auto w = kumi::windows<3>(r); 
  std::cout << "  Standard Windows " << "\n";
  std::cout << w << "\n";

  kumi::for_each([&](auto tile)
  {
    get<0>(kumi::values_of(tile))++;
  },w);
  std::cout << r << "\n";

  auto w2 = kumi::windows<3>(kumi::to_ref(r)); 
  std::cout << "  Windows with references " << "\n";
  std::cout << w2 << "\n";

  kumi::for_each([&](auto tile)
  {
    get<0>(kumi::values_of(tile))++;
  },w2);
  std::cout << r << "\n";   
}
