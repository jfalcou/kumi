/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <iostream>
#include <array>

// std::array supports structured bindings so we just need to opt-in the Product Type semantic
template<typename T, std::size_t N>
struct  kumi::is_product_type<std::array<T,N>> : std::true_type
{};

int main()
{
  std::array<int,3> a = { 37, 15, 27};
  auto b = kumi::to_tuple(a);

  std::cout << b << "\n";
}
