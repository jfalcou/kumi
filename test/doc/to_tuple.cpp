/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <cstdint>
#include <iostream>
#include <type_traits>
#include <utility>

struct pixel
{
  int r, g, b;
};

template<std::size_t I>
decltype(auto) get(pixel const& p) noexcept
{
  if constexpr(I==0) return p.r;
  if constexpr(I==1) return p.g;
  if constexpr(I==2) return p.b;
}

template<std::size_t I>
decltype(auto) get(pixel& p) noexcept
{
  if constexpr(I==0) return p.r;
  if constexpr(I==1) return p.g;
  if constexpr(I==2) return p.b;
}

// Opt-in for Product Type semantic
template<>
struct kumi::is_product_type<pixel> : std::true_type
{};

// Adapt as structured bindable type
template<>
struct  std::tuple_size<pixel>
      : std::integral_constant<std::size_t,3> {};

template<std::size_t I> struct std::tuple_element<I,pixel> { using type = int; };

int main()
{
  pixel a = { 37, 15, 27 };
  auto b = kumi::to_tuple(a);

  std::cout << b << "\n";
}
