/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <array>
#include <span>
#include <vector>

static_assert(kumi::is_static_container_v<std::array<int,10>>);
static_assert(kumi::is_product_type_v<std::array<int,10>>);

static_assert(kumi::is_static_container_v<std::span<int,10>>);
static_assert(!kumi::is_product_type_v<std::span<int,10>>);

static_assert(!kumi::is_static_container_v<std::span<int>>);
static_assert(!kumi::is_static_container_v<std::vector<int>>);

int main()
{
  auto data = std::array{1,2,3,4,5,6,7,8,9,10};
  kumi::for_each([](auto elt){ std::cout << elt << ", "; }, data);
  std::cout << "\n";
    
  auto my_span = std::span(data);
  kumi::for_each([](auto elt){ std::cout << elt << ", "; }, kumi::to_tuple(my_span));
}
