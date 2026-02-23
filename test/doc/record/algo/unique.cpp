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
  auto a = kumi::record{"a"_id = 1, "b"_id = 2, "c"_id = 'x', "d"_id = 3,"e"_id =  1.f, "f"_id = 2.f};

  std::cout << kumi::unique(a) << "\n";
}