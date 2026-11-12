/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <string>
#include <iostream>
#include <utility>

namespace ns
{
  struct people
  {
    std::string name;
    int         age;
  };

  template<std::size_t I>
  decltype(auto) get(people& p) noexcept
  {
    if constexpr (I == 0) return (p.name);
    else return (p.age);
  }

  template<std::size_t I>
  decltype(auto) get(people const& p) noexcept
  {
    if constexpr (I == 0) return (p.name);
    else return (p.age);
  }

  template<std::size_t I>
  decltype(auto) get(people&& p) noexcept
  {
    if constexpr (I == 0) return std::move(p.name);
    else return std::move(p.age);
  }
}

template<>
struct std::tuple_size<ns::people>
  : std::integral_constant<std::size_t, 2> {};

template<> struct std::tuple_element<0, ns::people>
{
  using type = std::string;
};

template<> struct std::tuple_element<1, ns::people>
{
  using type = int;
};

int main()
{
  ns::people p = {"Peter", 24};

  // get returns references, so that kumi::for_each writes to the members
  kumi::for_each([](auto& e) { e += e; }, p);
  std::cout << p.name << " " << p.age << '\n';
}
