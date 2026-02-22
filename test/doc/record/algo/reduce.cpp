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

  auto r1 = kumi::record{"a"_id = 14,"b"_id = short{7}, "c"_id = 255ULL};
  std::cout << kumi::reduce(kumi::function::bit_and, r1)        << "\n";
  std::cout << kumi::reduce(kumi::function::bit_and, r1, 65535) << "\n";

  auto r2 = kumi::record{"a"_id = 1 ,"b"_id = short{8},"c"_id = ' ', "d"_id = 4ULL};
  std::cout << kumi::reduce(kumi::function::bit_or, r2)         << "\n";
  std::cout << kumi::reduce(kumi::function::bit_or, r2, 0)      << "\n";

  auto r3 = kumi::record{"a"_id = 3, "b"_id = short{23}, "c"_id = '\t'};
  std::cout << kumi::reduce(kumi::function::bit_xor, r3)        << "\n";
  std::cout << kumi::reduce(kumi::function::bit_xor, r3, 1)     << "\n";

  auto r4 = kumi::record{"a"_id = 2.,"b"_id = 5,"c"_id = short{3},"d"_id = '\4'};
  std::cout << kumi::reduce(kumi::function::multiplies, r4)     << "\n";
  std::cout << kumi::reduce(kumi::function::multiplies, r4, 1)  << "\n";

  auto r5 = kumi::record{"a"_id = 2.,"b"_id = 1,"c"_id = short{55},"d"_id = ' '};
  std::cout << kumi::reduce(kumi::function::plus, r5)           << "\n";
  std::cout << kumi::reduce(kumi::function::plus, r5, 42)        << "\n";
}
