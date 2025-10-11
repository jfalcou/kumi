/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto t = kumi::tuple{2.,1,short{55},' '};

  std::cout << kumi::fold_left(kumi::function::plus, t, 100) << "\n";
  std::cout << kumi::reduce(kumi::function::plus, t) << "\n";
}
