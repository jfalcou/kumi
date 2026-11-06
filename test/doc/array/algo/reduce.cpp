/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

int main()
{
  auto t1 = kumi::tuple{14,short{7}, 255ULL};
  std::cout << kumi::reduce(kumi::function::bit_and, t1)        << "\n";
  std::cout << kumi::reduce(kumi::function::bit_and, t1, 65535) << "\n";

  auto t2 = kumi::tuple{1 ,short{8},' ', 4ULL};
  std::cout << kumi::reduce(kumi::function::bit_or, t2)         << "\n";
  std::cout << kumi::reduce(kumi::function::bit_or, t2, 0)      << "\n";

  auto t3 = kumi::tuple{3, short{23}, '\t'};
  std::cout << kumi::reduce(kumi::function::bit_xor, t3)        << "\n";
  std::cout << kumi::reduce(kumi::function::bit_xor, t3, 1)     << "\n";

  auto t4 = kumi::tuple{2.,5,short{3},'\4'};
  std::cout << kumi::reduce(kumi::function::multiplies, t4)     << "\n";
  std::cout << kumi::reduce(kumi::function::multiplies, t4, 1)  << "\n";

  auto t5 = kumi::tuple{2.,1,short{55},' '};
  std::cout << kumi::reduce(kumi::function::plus, t5)           << "\n";
  std::cout << kumi::reduce(kumi::function::plus, t5, 42)        << "\n";
}
