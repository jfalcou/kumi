/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

template<kumi::concepts::power_type T>
void print(std::ostream& os, T const& t)
{
  kumi::apply
  (
    [&os](auto const&... args)
    {
      os << '[';
      std::size_t n{0};
      ((os << args << (++n != kumi::size_v<T> ? ", " : "")), ...);
      os << ']';
    }, t
  );

  os << '\n';
}

int main()
{
  auto t = kumi::array{1,2,3};

  // Simple operation: sum all values
  std::cout << kumi::apply( [](auto... m) { return (m + ...); }, t) << "\n";

  // Advanced usage
  print(std::cout, t);
}
