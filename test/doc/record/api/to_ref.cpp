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
  auto original = kumi::make_record("a"_id=0,"b"_id='0',"c"_id=0.f);
  auto ref      = kumi::to_ref( original );

  std::cout << original << "\n";

  kumi::get<"a">(ref) = 9;
  kumi::get<"b">(ref) = 'z';
  kumi::get<"c">(ref) = 3.14159f;

  std::cout << original << "\n";
}
