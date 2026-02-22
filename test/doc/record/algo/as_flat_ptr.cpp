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
  
  kumi::record a = { "a"_id = 1, "b"_id = 
    kumi::record{ "c"_id = 2.3, "d"_id = 4.5f }, "e"_id = short{89} };

  auto ptr = kumi::as_flat_ptr(a);

  std::cout << a << "\n";
  std::cout << ptr << "\n";

  kumi::for_each([](auto p) { *p += 5; }, ptr );

  std::cout << a << "\n";
}
