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

  kumi::tuple t = { "x"_id = 1, 2.3, my_field = '@' };
  std::cout << t << "\n";

  std::cout << t["x"_l] << "\n";
  std::cout << t["mystery"_l] << "\n";

  t["mystery"_l]++;
  std::cout << t["mystery"_l] << "\n";
}
