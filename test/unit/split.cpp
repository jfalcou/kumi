//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/tuple.hpp>
#include <tts/tts.hpp>

TTS_CASE("Check result::split<Tuple,I> behavior")
{
  TTS_TYPE_IS ( (kumi::result::split_t<kumi::tuple<char,short,int,double>, 0>)
              , (kumi::tuple<kumi::tuple<>,kumi::tuple<char,short,int,double>>)
              );

  TTS_TYPE_IS ( (kumi::result::split_t<kumi::tuple<char,short,int,double>, 1>)
              , (kumi::tuple<kumi::tuple<char>,kumi::tuple<short,int,double>>)
              );

  TTS_TYPE_IS ( (kumi::result::split_t<kumi::tuple<char,short,int,double>, 2>)
              , (kumi::tuple<kumi::tuple<char,short>,kumi::tuple<int,double>>)
              );

  TTS_TYPE_IS ( (kumi::result::split_t<kumi::tuple<char,short,int,double>, 3>)
              , (kumi::tuple<kumi::tuple<char,short,int>,kumi::tuple<double>>)
              );

  TTS_TYPE_IS ( (kumi::result::split_t<kumi::tuple<char,short,int,double>, 4>)
              , (kumi::tuple<kumi::tuple<char,short,int,double>,kumi::tuple<>>)
              );
};

TTS_CASE("Check tuple::split behavior")
{
  using namespace kumi::literals;

  kumi::tuple t = {'1', 2., 3.f, 4, 5, 6.f, 7., '8'};

  auto[s00,s01] = kumi::split(t,0_c);
  TTS_EQUAL(s00, kumi::tuple {});
  TTS_EQUAL(s01, t);

  auto[s10,s11] = kumi::split(t,1_c);
  TTS_EQUAL(s10, (kumi::tuple {'1'}));
  TTS_EQUAL(s11, (kumi::tuple {2., 3.f, 4, 5, 6.f, 7., '8'}));

  auto[s20,s21] = kumi::split(t,2_c);
  TTS_EQUAL(s20, (kumi::tuple {'1', 2.}));
  TTS_EQUAL(s21, (kumi::tuple {3.f, 4, 5, 6.f, 7., '8'}));

  auto[s30,s31] = kumi::split(t,3_c);
  TTS_EQUAL(s30, (kumi::tuple {'1', 2., 3.f}));
  TTS_EQUAL(s31, (kumi::tuple {4, 5, 6.f, 7., '8'}));

  auto[s40,s41] = kumi::split(t,4_c);
  TTS_EQUAL(s40, (kumi::tuple {'1', 2., 3.f, 4}));
  TTS_EQUAL(s41, (kumi::tuple {5, 6.f, 7., '8'}));

  auto[s50,s51]= kumi::split(t,5_c);
  TTS_EQUAL(s50, (kumi::tuple {'1', 2., 3.f, 4, 5}));
  TTS_EQUAL(s51, (kumi::tuple {6.f, 7., '8'}));

  auto[s60,s61]= kumi::split(t,6_c);
  TTS_EQUAL(s60, (kumi::tuple {'1', 2., 3.f, 4, 5, 6.f}));
  TTS_EQUAL(s61, (kumi::tuple {7., '8'}));

  auto[s70,s71] = kumi::split(t,7_c);
  TTS_EQUAL(s70, (kumi::tuple {'1', 2., 3.f, 4, 5, 6.f, 7.}));
  TTS_EQUAL(s71, (kumi::tuple {'8'}));

  auto[s80,s81] = kumi::split(t,8_c);
  TTS_EQUAL(s80, (kumi::tuple {'1', 2., 3.f, 4, 5, 6.f, 7., '8'}));
  TTS_EQUAL(s81, (kumi::tuple {}));
};

TTS_CASE("Check tuple::split constexpr behavior")
{
  using namespace kumi::literals;

  constexpr kumi::tuple t = {'1', 2., 3.f, 4, 5, 6.f, 7., '8'};

  {
    constexpr auto s = kumi::split(t,0_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), kumi::tuple {});
    TTS_CONSTEXPR_EQUAL(get<1>(s), t);
  }

  {
    constexpr auto s = kumi::split(t,1_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1'}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {2., 3.f, 4, 5, 6.f, 7., '8'}));
  }

  {
    constexpr auto s = kumi::split(t,2_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2.}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {3.f, 4, 5, 6.f, 7., '8'}));
  }

  {
    constexpr auto s = kumi::split(t,3_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2., 3.f}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {4, 5, 6.f, 7., '8'}));
  }

  {
    constexpr auto s = kumi::split(t,4_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2., 3.f, 4}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {5, 6.f, 7., '8'}));
  }

  {
    constexpr auto s = kumi::split(t,5_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2., 3.f, 4, 5}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {6.f, 7., '8'}));
  }

  {
    constexpr auto s = kumi::split(t,6_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2., 3.f, 4, 5, 6.f}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {7., '8'}));
  }

  {
    constexpr auto s = kumi::split(t,7_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2., 3.f, 4, 5, 6.f, 7.}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {'8'}));
  }

  {
    constexpr auto s = kumi::split(t,8_c);
    TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2., 3.f, 4, 5, 6.f, 7., '8'}));
    TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {}));
  }
};
