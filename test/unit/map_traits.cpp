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

template<typename T>
struct nary_traits : std::integral_constant<std::size_t, sizeof(T)>
{};

TTS_CASE("Check map_traits behavior")
{
  using mapped = kumi::tuple< std::integral_constant<std::size_t, sizeof(int)>      , std::integral_constant<std::size_t, sizeof(char)>
                            , std::integral_constant<std::size_t, sizeof(void*)>    , std::integral_constant<std::size_t, sizeof(float)>
                            , std::integral_constant<std::size_t, sizeof(double)>   , std::integral_constant<std::size_t, sizeof(short)>
                            >;

  TTS_TYPE_IS ( (kumi::map_traits_t < nary_traits
                                      , kumi::tuple<int const, char, void*, float, double&, volatile short>
                                      >)
              , ( mapped )
              );
};

template<kumi::product_type T>
kumi::map_traits_t<nary_traits, T> f(T const&)
{
  return {};
}

template<kumi::product_type T>
kumi::map_traits_t<std::add_pointer, T> g(T const&)
{
  return {};
}

template<typename... T>
requires( std::is_floating_point_v<T> && ...)
struct strict_traits
{
  using type = bool;
};

template<kumi::product_type T>
kumi::map_traits_t<strict_traits, T> h(T const&)
{
  return true;
}

TTS_CASE("Check map_traits SFINAE compliance")
{
  kumi::tuple<char,short,double> t;
  kumi::tuple<float,double,float,double> u;

  // wrong # of arguments to traits
  TTS_EXPECT_COMPILES(t, { f(t); } );
  TTS_EXPECT_COMPILES(t, { g(t); } );

  // Unsupported types within tuple
  TTS_EXPECT_COMPILES(u, { h(u); } );
  TTS_EXPECT_NOT_COMPILES(t, { h(t); } );
};
