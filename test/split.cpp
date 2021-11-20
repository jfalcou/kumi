//==================================================================================================
/**
  KUMI - Compact Tuple Tools
  Copyright : KUMI Contributors & Maintainers
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#define TTS_MAIN
#include <kumi.hpp>
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

  TTS_WHEN("Given a tuple of size 8")
  {
    kumi::tuple t = {'1', 2., 3.f, 4, 5, 6.f, 7., '8'};

    TTS_AND_THEN("We split it on index 0")
    {
      auto split = t.split(0_c);
      TTS_EQUAL(get<0>(split), kumi::tuple {});
      TTS_EQUAL(get<1>(split), t);
    }

    TTS_AND_THEN("We split it on index 1")
    {
      auto split = t.split(1_c);
      TTS_EQUAL(get<0>(split), (kumi::tuple {'1'}));
      TTS_EQUAL(get<1>(split), (kumi::tuple {2., 3.f, 4, 5, 6.f, 7., '8'}));
    }

    TTS_AND_THEN("We split it on index 2")
    {
      auto split = t.split(2_c);
      TTS_EQUAL(get<0>(split), (kumi::tuple {'1', 2.}));
      TTS_EQUAL(get<1>(split), (kumi::tuple {3.f, 4, 5, 6.f, 7., '8'}));
    }

    TTS_AND_THEN("We split it on index 3")
    {
      auto split = t.split(3_c);
      TTS_EQUAL(get<0>(split), (kumi::tuple {'1', 2., 3.f}));
      TTS_EQUAL(get<1>(split), (kumi::tuple {4, 5, 6.f, 7., '8'}));
    }

    TTS_AND_THEN("We split it on index 4")
    {
      auto split = t.split(4_c);
      TTS_EQUAL(get<0>(split), (kumi::tuple {'1', 2., 3.f, 4}));
      TTS_EQUAL(get<1>(split), (kumi::tuple {5, 6.f, 7., '8'}));
    }

    TTS_AND_THEN("We split it on index 5")
    {
      auto split = t.split(5_c);
      TTS_EQUAL(get<0>(split), (kumi::tuple {'1', 2., 3.f, 4, 5}));
      TTS_EQUAL(get<1>(split), (kumi::tuple {6.f, 7., '8'}));
    }

    TTS_AND_THEN("We split it on index 6")
    {
      auto split = t.split(6_c);
      TTS_EQUAL(get<0>(split), (kumi::tuple {'1', 2., 3.f, 4, 5, 6.f}));
      TTS_EQUAL(get<1>(split), (kumi::tuple {7., '8'}));
    }

    TTS_AND_THEN("We split it on index 7")
    {
      auto split = t.split(7_c);
      TTS_EQUAL(get<0>(split), (kumi::tuple {'1', 2., 3.f, 4, 5, 6.f, 7.}));
      TTS_EQUAL(get<1>(split), (kumi::tuple {'8'}));
    }

    TTS_AND_THEN("We split it on index 8")
    {
      auto split = t.split(8_c);
      TTS_EQUAL(get<0>(split), (kumi::tuple {'1', 2., 3.f, 4, 5, 6.f, 7., '8'}));
      TTS_EQUAL(get<1>(split), (kumi::tuple {}));
    }
  }
};

TTS_CASE("Check tuple::split constexpr behavior")
{
  using namespace kumi::literals;

  TTS_WHEN("Given a constexpr tuple of size 8")
  {
    constexpr kumi::tuple t = {'1', 2., 3.f, 4, 5, 6.f, 7., '8'};

    TTS_AND_THEN("We split it on index 0")
    {
      constexpr auto s = t.split(0_c);
      TTS_CONSTEXPR_EQUAL(get<0>(s), kumi::tuple {});
      TTS_CONSTEXPR_EQUAL(get<1>(s), t);
    }

    TTS_AND_THEN("We split it on index 1")
    {
      constexpr auto s = t.split(1_c);
      TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1'}));
      TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {2., 3.f, 4, 5, 6.f, 7., '8'}));
    }

    TTS_AND_THEN("We split it on index 2")
    {
      constexpr auto s = t.split(2_c);
      TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2.}));
      TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {3.f, 4, 5, 6.f, 7., '8'}));
    }

    TTS_AND_THEN("We split it on index 3")
    {
      constexpr auto s = t.split(3_c);
      TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2., 3.f}));
      TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {4, 5, 6.f, 7., '8'}));
    }

    TTS_AND_THEN("We split it on index 4")
    {
      constexpr auto s = t.split(4_c);
      TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2., 3.f, 4}));
      TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {5, 6.f, 7., '8'}));
    }

    TTS_AND_THEN("We split it on index 5")
    {
      constexpr auto s = t.split(5_c);
      TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2., 3.f, 4, 5}));
      TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {6.f, 7., '8'}));
    }

    TTS_AND_THEN("We split it on index 6")
    {
      constexpr auto s = t.split(6_c);
      TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2., 3.f, 4, 5, 6.f}));
      TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {7., '8'}));
    }

    TTS_AND_THEN("We split it on index 7")
    {
      constexpr auto s = t.split(7_c);
      TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2., 3.f, 4, 5, 6.f, 7.}));
      TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {'8'}));
    }

    TTS_AND_THEN("We split it on index 8")
    {
      constexpr auto s = t.split(8_c);
      TTS_CONSTEXPR_EQUAL(get<0>(s), (kumi::tuple {'1', 2., 3.f, 4, 5, 6.f, 7., '8'}));
      TTS_CONSTEXPR_EQUAL(get<1>(s), (kumi::tuple {}));
    }
  }
};
