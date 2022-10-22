/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/tuple.hpp>
#include <type_traits>
#include <array>

// std::array supports structured bindings so we just need to opt-in the Product Type semantic
template<typename T, std::size_t N>
struct  kumi::is_product_type<std::array<T,N>> : std::true_type
{};

int main()
{
  using three_floats   = kumi::as_tuple_t<std::array<float,3>>;
  using three_pointers = kumi::as_tuple_t<std::array<float,3>, std::add_pointer>;

  static_assert( std::same_as<three_floats  , kumi::tuple<float ,float ,float > >);
  static_assert( std::same_as<three_pointers, kumi::tuple<float*,float*,float*> >);
}
