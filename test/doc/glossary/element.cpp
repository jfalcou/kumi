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
  using t_t = kumi::tuple<int&, int const>;
  using r_t = decltype(kumi::record{"x"_id = 1.f});

  // the elements keep their reference and their const
  show("tuple element 0 is int&", is_same_v<kumi::element_t<0, t_t>, int&>);
  show("tuple element 1 is int const",
       is_same_v<kumi::element_t<1, t_t>, int const>);

  // a record stores its values in fields
  show("record stores a float",
       is_same_v<kumi::stored_element_t<0, r_t>, float>);
}
