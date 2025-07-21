/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>

template<kumi::record_type Record>
void print(std::ostream& os, Record const& t)
{
  kumi::apply
  (
    [&os](auto const&... args)
    {
      os << '[';
      std::size_t n{0};
      ((os << args << (++n != kumi::size<Record>::value ? ", " : "")), ...);
      os << ']';
    }, t
  );

  os << '\n';
}

int main()
{
  using namespace kumi::literals;

  auto r = kumi::record{"x"_f = 1, "y"_f = 2., "z"_f = 3.f};

  // Simple operation: sum all values
  std::cout << kumi::apply( [](auto... m) { return (m + ...); }, r) << "\n";

  // Advanced usage
  print(std::cout, r);
}
