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
  auto f0 = kumi::record {"a"_id =2.,"b"_id = 
    kumi::record {"c"_id =1., "d"_id ='u', "e"_id =3. }, "f"_id =3.f };

  std::cout << kumi::min_flat (f0 , [](auto m) { return sizeof(m); }) << "\n";
}
