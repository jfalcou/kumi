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
  using n_t = kumi::name<"x">;
  using i_t = std::integral_constant<std::size_t, 0>;

  // "x"_id is a value of the identifier type kumi::name<"x">
  show("\"x\"_id is a kumi::name<\"x\">",
       std::is_same_v<decltype("x"_id), n_t>);
  show("kumi::name is an identifier", kumi::concepts::identifier<n_t>);
  show("kumi::name is an index", kumi::concepts::index<n_t>);

  // an integral constant models both concepts
  show("integral_constant is an identifier",
       kumi::concepts::identifier<i_t>);
  show("integral_constant is an index", kumi::concepts::index<i_t>);
}
