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
  auto f0 = kumi::record {"a"_id = 1, "b"_id ='A', "c"_id =-9.77f, "d"_id =3. };
  auto f1 = kumi::record {"a"_id =2., "b"_id =f0, "c"_id =3.f };

  std::cout << kumi::min(f0, [](auto m) { return sizeof(m); }) << "\n";
  std::cout << kumi::min(f1, [](auto m) { return sizeof(m); }) << "\n";
}
