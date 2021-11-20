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

TTS_CASE("Check result::reorder<Tuple,I...> behavior")
{
  using tuple_t = kumi::tuple<char,short,int,double>;

  TTS_TYPE_IS( (kumi::result::reorder_t<tuple_t,0,1,2,3>), tuple_t                              );
  TTS_TYPE_IS( (kumi::result::reorder_t<tuple_t,1,2,3,0>), (kumi::tuple<short,int,double,char>) );
  TTS_TYPE_IS( (kumi::result::reorder_t<tuple_t,3,3>    ), (kumi::tuple<double,double>)         );
  TTS_TYPE_IS( (kumi::result::reorder_t<tuple_t>        ), kumi::tuple<>                        );
};

TTS_CASE("Check reorder<I...>(tuple) behavior")
{
  TTS_WHEN("Given a tuple t of size 4")
  {
    auto t = kumi::tuple {1, 2., 3.4f, '5'};

    TTS_AND_THEN(" - we call reorder<0,1,2,3>(t)")
    {
      auto s = kumi::reorder<0,1,2,3>(t);
      TTS_EQUAL(s, t);
    }

    TTS_AND_THEN(" - we call reorder<3,2,1,0>(t)")
    {
      auto s = kumi::reorder<3,2,1,0>(t);
      TTS_EQUAL(s, (kumi::tuple{'5',3.4f,2.,1}));
    }

    TTS_AND_THEN(" - we call reorder<0,1,2>(t)")
    {
      auto s = kumi::reorder<0,1,2>(t);
      TTS_EQUAL(s, (kumi::tuple{1,2.,3.4f}) );
    }

    TTS_AND_THEN(" - we call reorder<0,1>(t)")
    {
      auto s = kumi::reorder<0,1>(t);
      TTS_EQUAL(s, (kumi::tuple{1,2.}) );
    }

    TTS_AND_THEN(" - we call reorder<0>(t)")
    {
      auto s = kumi::reorder<0>(t);
      TTS_EQUAL(s, (kumi::tuple{1}) );
    }

    TTS_AND_THEN(" - we call reorder<1>(t)")
    {
      auto s = kumi::reorder<1>(t);
      TTS_EQUAL(s, (kumi::tuple{2.}) );
    }

    TTS_AND_THEN(" - we call reorder<2>(t)")
    {
      auto s = kumi::reorder<2>(t);
      TTS_EQUAL(s, (kumi::tuple{3.4f}) );
    }

    TTS_AND_THEN(" - we call reorder<3>(t)")
    {
      auto s = kumi::reorder<3>(t);
      TTS_EQUAL(s, (kumi::tuple{'5'}) );
    }

    TTS_AND_THEN(" - we call reorder<0,1,2,3,2,1,0>(t)")
    {
      auto s = kumi::reorder<0,1,2,3,2,1,0>(t);
      TTS_EQUAL(s, (kumi::tuple{1,2.,3.4f,'5',3.4f,2.,1}) );
    }
  }
};

TTS_CASE("Check reorder<I...>(tuple) constexpr behavior")
{
  TTS_WHEN("Given a tuple t of size 4")
  {
    constexpr auto t = kumi::tuple {1, 2., 3.4f, '5'};

    TTS_AND_THEN(" - we call reorder<0,1,2,3>(t)")
    {
      constexpr auto s = kumi::reorder<0,1,2,3>(t);
      TTS_CONSTEXPR_EQUAL(s, t);
    }

    TTS_AND_THEN(" - we call reorder<3,2,1,0>(t)")
    {
      constexpr auto s = kumi::reorder<3,2,1,0>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{'5',3.4f,2.,1}));
    }

    TTS_AND_THEN(" - we call reorder<0,1,2>(t)")
    {
      constexpr auto s = kumi::reorder<0,1,2>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1,2.,3.4f}) );
    }

    TTS_AND_THEN(" - we call reorder<0,1>(t)")
    {
      constexpr auto s = kumi::reorder<0,1>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1,2.}) );
    }

    TTS_AND_THEN(" - we call reorder<0>(t)")
    {
      constexpr auto s = kumi::reorder<0>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1}) );
    }

    TTS_AND_THEN(" - we call reorder<1>(t)")
    {
      constexpr auto s = kumi::reorder<1>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{2.}) );
    }

    TTS_AND_THEN(" - we call reorder<2>(t)")
    {
      constexpr auto s = kumi::reorder<2>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{3.4f}) );
    }

    TTS_AND_THEN(" - we call reorder<3>(t)")
    {
      constexpr auto s = kumi::reorder<3>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{'5'}) );
    }

    TTS_AND_THEN(" - we call reorder<0,1,2,3,2,1,0>(t)")
    {
      constexpr auto s = kumi::reorder<0,1,2,3,2,1,0>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1,2.,3.4f,'5',3.4f,2.,1}) );
    }
  }
};
