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
  show("kumi::tuple<int, float> is an aggregate",
       std::is_aggregate_v<kumi::tuple<int, float>>);

  // brace elision initializes the elements inside the single member
  kumi::tuple<int, float> t = {1, 2.f};
  std::cout << t << '\n';

  // the parenthesized u(1, 2.f) does not compile,
  // a parenthesized list performing no brace elision
}
