//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#pragma once

#if defined(__ANDROID__) || defined(__APPLE__)
#include <type_traits>

namespace kumi
{
  template<typename From, typename To>
  concept convertible_to = std::is_convertible_v<From, To> && requires { static_cast<To>(std::declval<From>()); };
}
#else
#include <concepts>

namespace kumi
{
  using std::convertible_to;
}
#endif
