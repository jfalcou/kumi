/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <string>
#include <cstdint>

namespace ns
{
  struct price
  {
      std::uint64_t integer;
      std::uint64_t decimal;
  };

  auto as_streamable(price const& p)
  {
    return std::to_string(p.integer) + "."
         + std::to_string(p.decimal);
  }
}

int main()
{
  ns::price baguette{1, 50};
  ns::price cards   {7, 90};
  
  kumi::tuple shop_list = {baguette, cards};
  std::cout << shop_list << "\n";
}
