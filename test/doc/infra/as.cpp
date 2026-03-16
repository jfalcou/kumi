/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

template<typename T> 
void display (kumi::as<T>)
{
  if constexpr ( std::same_as<T,void>)
    std::cout << "Type is void\n";
  else
    std::cout << "Other type\n";
};

int main()
{
  int a = 12;
  display(kumi::as(a));

  display(kumi::as<void>{});
}
