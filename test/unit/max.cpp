//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <array>
#include <kumi/kumi.hpp>
#include <tts/tts.hpp>
#include <vector>

TTS_CASE("Check result::max/max_flat<...> behavior")
{
  auto lambda = [](auto m) { return sizeof(m); };
  using func_t = decltype(lambda);

  TTS_TYPE_IS ( (kumi::result::max_t<kumi::tuple<char,short,double,int>>)
              , double
              );

  TTS_TYPE_IS ( (kumi::result::max_t<kumi::tuple<char,short,int,double>,func_t>)
              , std::size_t
              );

  TTS_TYPE_IS ( (kumi::result::max_flat_t<kumi::tuple<char,short,int,double>,func_t>)
              , std::size_t
              );

  TTS_TYPE_IS ( (kumi::result::max_flat_t<kumi::tuple<char,kumi::tuple<short,int>,double>,func_t>)
              , std::size_t
              );
};

TTS_CASE("Check tuple::max/max_flat behavior")
{
  auto t0 = kumi::tuple {'e', 2, 7894.5, short {55}, 'z'};
  TTS_EQUAL( kumi::max(t0), 7894.5);
  TTS_EQUAL((kumi::max(t0, [](auto m) { return sizeof(m); })), sizeof(double));

  auto f0 = kumi::tuple {'e', 2., kumi::tuple {1., short {55}, 'u'}, 3.f, 'z'};
  TTS_EQUAL((kumi::max      (f0 , [](auto m) { return sizeof(m); })), 2*sizeof(double));
  TTS_EQUAL((kumi::max_flat (f0 , [](auto m) { return sizeof(m); })),   sizeof(double));

  auto t1 = kumi::tuple {1.5,3.6f,8,-3.6,2.4,0};
  TTS_EQUAL((kumi::max(t1, [](auto m) { return (m-5)<0 ? (5-m) : (m-5); })), 8.6);
};

TTS_CASE("Check tuple::max/max_flat constexpr behavior")
{
  constexpr auto t0 = kumi::tuple {'e', 2, 7894.5, short {55}, 'z'};
  TTS_CONSTEXPR_EQUAL( kumi::max(t0), 7894.5);
  TTS_CONSTEXPR_EQUAL((kumi::max(t0, [](auto m) { return sizeof(m); })), sizeof(double));

  constexpr auto f0 = kumi::tuple {'e', 2., kumi::tuple {1., short {55}, 'u'}, 3.f, 'z'};
  TTS_CONSTEXPR_EQUAL((kumi::max      (f0 , [](auto m) { return sizeof(m); })), 2*sizeof(double));
  TTS_CONSTEXPR_EQUAL((kumi::max_flat (f0 , [](auto m) { return sizeof(m); })),   sizeof(double));

  constexpr auto t1 = kumi::tuple {1.5,3.6f,8,-3.6,2.4,0};
  TTS_CONSTEXPR_EQUAL((kumi::max(t1, [](auto m) { return (m-5)<0 ? (5-m) : (m-5); })), 8.6);
};
