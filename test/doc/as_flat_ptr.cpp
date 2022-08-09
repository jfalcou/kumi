//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>

int main()
{
  kumi::tuple a = { 1, kumi::tuple{ 2.3, 4.5f }, short{89} };

  auto ptr = kumi::as_flat_ptr(a);

  std::cout << a << "\n";
  std::cout << ptr << "\n";

  kumi::for_each([](auto ptr) { *ptr += 5; }, ptr );

  std::cout << a << "\n";
}
