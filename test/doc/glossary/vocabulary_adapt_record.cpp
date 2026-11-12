/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <iostream>
#include <utility>

using namespace kumi::literals;

namespace geo
{
  struct point
  {
    double x;
    double y;
  };

  template<kumi::concepts::identifier auto ID>
  decltype(auto) get(point& p) noexcept
  {
    if constexpr (ID == "x"_id) return (p.x);
    else return (p.y);
  }

  template<kumi::concepts::identifier auto ID>
  decltype(auto) get(point const& p) noexcept
  {
    if constexpr (ID == "x"_id) return (p.x);
    else return (p.y);
  }

  template<kumi::concepts::identifier auto ID>
  decltype(auto) get(point&& p) noexcept
  {
    if constexpr (ID == "x"_id) return std::move(p.x);
    else return std::move(p.y);
  }
}

// the opt-in that makes geo::point a record
template<> inline constexpr bool kumi::is_record_type_v<geo::point> = true;

template<>
struct std::tuple_size<geo::point>
  : std::integral_constant<std::size_t, 2> {};

template<> struct std::tuple_element<0, geo::point>
{
  using type = kumi::field<kumi::name<"x">, double>;
};

template<> struct std::tuple_element<1, geo::point>
{
  using type = kumi::field<kumi::name<"y">, double>;
};

static_assert(kumi::concepts::record_type<geo::point>);

int main()
{
  geo::point p = {1.5, -2.};

  // get returns references, so that kumi::for_each scales the members
  kumi::for_each([](auto& e) { e *= 2; }, p);
  auto print = [](auto n, auto e) { std::cout << n << " = " << e << '\n'; };
  kumi::for_each_field(print, p);
}
