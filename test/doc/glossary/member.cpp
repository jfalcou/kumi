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
  using std::is_same_v;
  using t_t = kumi::tuple<int>;
  using r_t = kumi::tuple<int&>;

  // the value category and the const of the tuple reach the member
  show("lvalue tuple<int> gives int&",
       is_same_v<kumi::member_t<0, t_t&>, int&>);
  show("rvalue tuple<int> gives int&&",
       is_same_v<kumi::member_t<0, t_t&&>, int&&>);
  show("const tuple<int> gives int const&",
       is_same_v<kumi::member_t<0, t_t const&>, int const&>);

  // except through a reference element
  show("rvalue tuple<int&> gives int&",
       is_same_v<kumi::member_t<0, r_t&&>, int&>);
}
