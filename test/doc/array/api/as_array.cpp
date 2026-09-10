/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
**/
#include <kumi/kumi.hpp>
#include <cstdint>
#include <type_traits>

int main()
{
  using three_floats   = kumi::as_array_t<kumi::array<float, 3>>;
  using three_pointers = kumi::as_array_t<kumi::array<float, 3>, std::add_pointer>;
  using single_float   = kumi::as_array_t<float>;

  static_assert( std::same_as<three_floats  , kumi::array<float, 3>  >);
  static_assert( std::same_as<three_pointers, kumi::array<float*, 3> >);
  static_assert( std::same_as<single_float  , kumi::array<float, 0>  >);
}
