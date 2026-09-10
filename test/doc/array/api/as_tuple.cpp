/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <concepts>
#include <cstdint>
#include <type_traits>
#include <utility>

struct vec3
{
  float x, y, z;
};

template<std::size_t I>
decltype(auto) get(vec3 const& v) noexcept
{
  if constexpr(I==0) return v.x;
  if constexpr(I==1) return v.y;
  if constexpr(I==2) return v.z;
}

template<std::size_t I>
decltype(auto) get(vec3& v) noexcept
{
  if constexpr(I==0) return v.x;
  if constexpr(I==1) return v.y;
  if constexpr(I==2) return v.z;
}

// Adapt as structured bindable type
template<>
struct  std::tuple_size<vec3>
      : std::integral_constant<std::size_t,3> {};

template<std::size_t I> struct std::tuple_element<I,vec3> { using type = float; };

int main()
{
  using three_floats   = kumi::as_tuple_t<vec3>;
  using single_type    = kumi::as_tuple_t<float>;
  using three_pointers = kumi::as_tuple_t<vec3, std::add_pointer>;
  using single_pointer = kumi::as_tuple_t<float, std::add_pointer>;

  static_assert( std::same_as<three_floats  , kumi::tuple<float ,float ,float > >);
  static_assert( std::same_as<three_pointers, kumi::tuple<float*,float*,float*> >);
  static_assert( std::same_as<single_type   , kumi::tuple<float>  >);
  static_assert( std::same_as<single_pointer, kumi::tuple<float*> >);
}
