/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
    using tuple = kumi::tuple<int, int, char, int, float, float>;

    tuple a = {1, 2, 'x', 3, 1.f, 2.f};

    std::cout << kumi::all_unique(a) << "\n";
}
