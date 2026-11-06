/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
    kumi::array a = {1, 2, 3, 4, 5, 6};

    std::cout << kumi::all_unique(a) << "\n";
}
