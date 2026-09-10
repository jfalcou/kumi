/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

template<typename T> struct is_int : std::is_same<std::remove_cvref_t<T>, int>
{};

int main()
{
  auto twice = [](auto v) { return v * 2; };

  // A pipeline is built once and applied to any product type.
  auto p = kumi::filter<is_int> | kumi::map[twice] | kumi::sum[0];

  std::cout << p(kumi::tuple{1, 2.5, 3, 'x'}) << "\n";
  std::cout << p(kumi::tuple{10, 20, 30}) << "\n";
}
