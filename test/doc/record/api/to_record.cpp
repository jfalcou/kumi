/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <cstdint>
#include <iostream>
#include <type_traits>
#include <utility>

using namespace kumi::literals;
struct pixel
{
  int r, g, b;
};

template<std::size_t I>
decltype(auto) get(pixel const& p) noexcept
{
  if constexpr(I==0) return kumi::capture_field<"r"_id>(p.r);
  if constexpr(I==1) return kumi::capture_field<"g"_id>(p.g);
  if constexpr(I==2) return kumi::capture_field<"b"_id>(p.b);
}

template<std::size_t I>
decltype(auto) get(pixel& p) noexcept
{
  if constexpr(I==0) return kumi::capture_field<"r"_id>(p.r);
  if constexpr(I==1) return kumi::capture_field<"g"_id>(p.g);
  if constexpr(I==2) return kumi::capture_field<"b"_id>(p.b);
}

// Opt-in for Record Type semantic
template<>
struct kumi::is_record_type<pixel> : std::true_type
{};

// Adapt as structured bindable type
template<>
struct  std::tuple_size<pixel> : std::integral_constant<std::size_t,3> 
{};

template<> struct std::tuple_element<0,pixel> { using type = kumi::field<kumi::name<"r">, int>; };
template<> struct std::tuple_element<1,pixel> { using type = kumi::field<kumi::name<"g">, int>; };
template<> struct std::tuple_element<2,pixel> { using type = kumi::field<kumi::name<"b">, int>; };

int main()
{
  pixel a = { 37, 15, 27 };
  auto b = kumi::to_record(a);

  std::cout << b << "\n";
}
