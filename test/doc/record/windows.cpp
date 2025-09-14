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

  auto t = kumi::record{ "a"_f=1, "b"_f='y', "c"_f=3.f, "d"_f=short{55}
                       , "e"_f=-8, "f"_f=66., "g"_f="Pete"};

  auto w = kumi::windows<3>(t); 
  std::cout << "  Standard Windows " << "\n";
  std::cout << w << "\n";

  kumi::for_each([&](auto tile)
  {
    kumi::field_value_of(get<0>(tile))++;
  },w);
  std::cout << t << "\n";

  auto w2 = kumi::windows<3>(kumi::to_ref(t)); 
  std::cout << "  Windows with references " << "\n";
  std::cout << w2 << "\n";

  kumi::for_each([&](auto tile)
  {
  kumi::field_value_of(get<0>(tile))++;
  },w2);
  std::cout << t << "\n";   
}
