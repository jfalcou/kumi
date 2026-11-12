/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <type_traits>

void show(char const* text, bool b)
{
  std::cout << text << ": " << std::boolalpha << b << '\n';
}

int main()
{
  using namespace kumi::literals;
  using std::is_same_v;
  using t_t = kumi::tuple<int, int, int>;

  // a power type of int, indexed at compile time
  kumi::array a = {1, 2, 3};
  std::cout << a << " has " << a[1_c] << " at index 1\n";
  show("kumi::array<int, 3> is a power type",
       kumi::concepts::power_type<decltype(a)>);
  show("kumi::tuple<int, int, int> is a power type",
       kumi::concepts::power_type<t_t>);
  show("kumi::tuple<int, int, int> is homogeneous",
       kumi::concepts::homogeneous_product_type<t_t>);

  // the empty array, the identity of the power types
  show("kumi::array{} is kumi::array<void, 0>",
       is_same_v<decltype(kumi::array{}), kumi::array<void, 0>>);

  // an algorithm that mixes types returns a kumi::tuple
  auto m = kumi::map([](int x) { return x * 2; }, a);
  auto p = kumi::push_back(a, 4.5);
  std::cout << m << " and " << p << '\n';
}
