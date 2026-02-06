//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>
#include <type_traits>
#include <algorithm>

template<typename... T> struct nary_traits : std::integral_constant<std::size_t, std::max({sizeof(T)...})>
{
};

TTS_CASE("Check apply_traits behavior")
{
  TTS_TYPE_IS((kumi::apply_traits_t<nary_traits, kumi::tuple<int const, char, void*, float, double&, volatile short>>),
              (std::integral_constant<std::size_t, 8>));
};

template<kumi::concepts::product_type T> kumi::apply_traits_t<nary_traits, T> f(T const&)
{
  return {};
}

template<kumi::concepts::product_type T> kumi::apply_traits_t<std::add_pointer, T> g(T const&)
{
  return {};
}

template<typename... T>
requires(std::is_floating_point_v<T> && ...)
struct strict_traits
{
  using type = bool;
};

template<kumi::concepts::product_type T> kumi::apply_traits_t<strict_traits, T> h(T const&)
{
  return true;
}

TTS_CASE("Check apply_traits SFINAE compliance")
{
  kumi::tuple<char, short, double> t;
  kumi::tuple<float, double, float, double> u;

  // wrong # of arguments to traits
  TTS_EXPECT_COMPILES(t, { f(t); });
  TTS_EXPECT_NOT_COMPILES(t, { g(t); });

  // Unsupported types within tuple
  TTS_EXPECT_COMPILES(u, { h(u); });
  TTS_EXPECT_NOT_COMPILES(t, { h(t); });
};
