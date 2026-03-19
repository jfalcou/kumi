/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

struct my_id : kumi::identifier<my_id>
{
  using kumi::identifier<my_id>::operator=; 
  friend constexpr auto to_str(my_id) { return kumi::str{"Specific label"}; }
};
inline constexpr my_id my_kw{};

int main()
{
  using namespace kumi::literals;

  auto field = ( "x"_id = 1 ); 
  int standard = { 12 };
  auto custom = (my_kw = 255);

  std::cout << field << "\n";
  std::cout << kumi::label_of<decltype(field)>() << "\n";
  
  std::cout << standard << "\n";
  std::cout << kumi::label_of<decltype(standard)>() << "\n";

  std::cout << custom << "\n";
  std::cout << kumi::label_of<decltype(custom)>() << "\n";
}
