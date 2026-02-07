/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

using namespace kumi::literals;

template<kumi::concepts::product_type T>
void check_contains(T const& )
{
  if constexpr(contains_none(T{}, "malus"_id, "other"_id))
    std::cout << "Correct product_type\n";
  else
    std::cout << "Incorrect product type\n";
}

int main()
{
  check_contains( kumi::tuple{"value"_id = 9  });
  check_contains( kumi::tuple{"active"_id = std::bool_constant<true>{}});
  check_contains( kumi::tuple{"malus"_id = 6.5, "value"_id = 17} );
  check_contains( kumi::tuple{"active"_id = std::bool_constant<true>{}, "value"_id = 17} );
  check_contains( kumi::tuple{"active"_id = std::bool_constant<true>{}, "value"_id = 17, "other"_id = false});
}
