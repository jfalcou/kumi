//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include <type_traits>

template<typename T> struct nary_traits : std::integral_constant<std::size_t, sizeof(T)>
{
};

TTS_CASE("Check map_traits behavior")
{
  using mapped = kumi::array<std::integral_constant<std::size_t, sizeof(int)>, 4>;

  TTS_TYPE_IS((kumi::map_traits_t<nary_traits, kumi::array<int, 4>>), (mapped));
};

template<kumi::concepts::product_type T> kumi::map_traits_t<nary_traits, T> f(T const&)
{
  return {};
}

template<kumi::concepts::product_type T> kumi::map_traits_t<std::add_pointer, T> g(T const&)
{
  return {};
}

template<typename... T>
requires(std::is_floating_point_v<T> && ...)
struct strict_traits
{
  using type = bool;
};

template<kumi::concepts::product_type T> kumi::map_traits_t<strict_traits, T> h(T const&)
{
  return true;
}

TTS_CASE("Check map_traits SFINAE compliance")
{
  kumi::array<char, 3> t;
  kumi::array<float, 4> u;

  // wrong # of arguments to traits
  TTS_EXPECT_COMPILES(t, { f(t); });
  TTS_EXPECT_COMPILES(t, { g(t); });

  // Unsupported types within array
  TTS_EXPECT_COMPILES(u, { h(u); });
  TTS_EXPECT_NOT_COMPILES(t, { h(t); });
};
