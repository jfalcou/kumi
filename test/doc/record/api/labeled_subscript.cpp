/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

struct my_id : kumi::identifier<my_id>
{
  using parent = kumi::identifier<my_id>;
  using parent::operator=;

  friend constexpr auto to_str(my_id) { return kumi::str{"mystery"}; }
};

inline constexpr my_id my_field{};

int main()
{
  using namespace kumi::literals;

  kumi::record r = { "x"_id = 1, "y"_id = 2.3, my_field = '@' };
  std::cout << r << "\n";

  std::cout << r["x"_l] << "\n";
  std::cout << r["y"_l] << "\n";
  std::cout << r["mystery"_l] << "\n";

  r["mystery"_l]++;
  std::cout << r["mystery"_l] << "\n";
}
