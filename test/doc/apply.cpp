//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#include <kumi/tuple.hpp>
#include <iostream>

template<kumi::product_type Tuple>
void print(std::ostream& os, Tuple const& t)
{
  kumi::apply
  (
    [&os](auto const&... args)
    {
      os << '[';
      std::size_t n{0};
      ((os << args << (++n != kumi::size<Tuple>::value ? ", " : "")), ...);
      os << ']';
    }, t
  );

  os << '\n';
}

int main()
{
  auto t = kumi::tuple{1,2.,3.f};

  // Simple operation: sum all values
  std::cout << kumi::apply( [](auto... m) { return (m + ...); }, t) << "\n";

  // Advanced usage
  print(std::cout, t);
}
