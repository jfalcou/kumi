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

TTS_CASE("Check result::reorder<Tuple,I...> behavior")
{
  using tuple_t = kumi::tuple<char,short,int,double>;

  TTS_TYPE_IS( (kumi::result::reorder_t<tuple_t,0,1,2,3>), tuple_t                              );
  TTS_TYPE_IS( (kumi::result::reorder_t<tuple_t,1,2,3,0>), (kumi::tuple<short,int,double,char>) );
  TTS_TYPE_IS( (kumi::result::reorder_t<tuple_t,3,3>    ), (kumi::tuple<double,double>)         );
  TTS_TYPE_IS( (kumi::result::reorder_t<tuple_t>        ), kumi::tuple<>                        );

  using nested_t = kumi::tuple<kumi::tuple<int, float>, int>;
  TTS_TYPE_IS( (kumi::result::reorder_t<nested_t, 0>), (kumi::tuple<kumi::tuple<int, float>>));
};

TTS_CASE("Check reorder<I...>(tuple) behavior")
{
  {
    auto t = kumi::tuple {1, 2., 3.4f, '5'};

    {
      auto s = kumi::reorder<0,1,2,3>(t);
      TTS_EQUAL(s, t);
    }

    {
      auto s = kumi::reorder<3,2,1,0>(t);
      TTS_EQUAL(s, (kumi::tuple{'5',3.4f,2.,1}));
    }

    {
      auto s = kumi::reorder<0,1,2>(t);
      TTS_EQUAL(s, (kumi::tuple{1,2.,3.4f}) );
    }

    {
      auto s = kumi::reorder<0,1>(t);
      TTS_EQUAL(s, (kumi::tuple{1,2.}) );
    }

    {
      auto s = kumi::reorder<0>(t);
      TTS_EQUAL(s, (kumi::tuple{1}) );
    }

    {
      auto s = kumi::reorder<1>(t);
      TTS_EQUAL(s, (kumi::tuple{2.}) );
    }

    {
      auto s = kumi::reorder<2>(t);
      TTS_EQUAL(s, (kumi::tuple{3.4f}) );
    }

    {
      auto s = kumi::reorder<3>(t);
      TTS_EQUAL(s, (kumi::tuple{'5'}) );
    }

    {
      auto s = kumi::reorder<0,1,2,3,2,1,0>(t);
      TTS_EQUAL(s, (kumi::tuple{1,2.,3.4f,'5',3.4f,2.,1}) );
    }
    {
      auto s = kumi::reorder<0,1,2,3,2,1,0>(std::move(t));
      TTS_EQUAL(s, (kumi::tuple{1,2.,3.4f,'5',3.4f,2.,1}) );
    }
  }
};

TTS_CASE("Check reorder<I...>(tuple) constexpr behavior")
{
  {
    constexpr auto t = kumi::tuple {1, 2., 3.4f, '5'};

    {
      constexpr auto s = kumi::reorder<0,1,2,3>(t);
      TTS_CONSTEXPR_EQUAL(s, t);
    }

    {
      constexpr auto s = kumi::reorder<3,2,1,0>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{'5',3.4f,2.,1}));
    }

    {
      constexpr auto s = kumi::reorder<0,1,2>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1,2.,3.4f}) );
    }

    {
      constexpr auto s = kumi::reorder<0,1>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1,2.}) );
    }

    {
      constexpr auto s = kumi::reorder<0>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1}) );
    }

    {
      constexpr auto s = kumi::reorder<1>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{2.}) );
    }

    {
      constexpr auto s = kumi::reorder<2>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{3.4f}) );
    }

    {
      constexpr auto s = kumi::reorder<3>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{'5'}) );
    }

    {
      constexpr auto s = kumi::reorder<0,1,2,3,2,1,0>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1,2.,3.4f,'5',3.4f,2.,1}) );
    }
  }
};
