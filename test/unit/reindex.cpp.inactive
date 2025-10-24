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

TTS_CASE("Check result::reindex<Tuple,Indexes> behavior")
{
  using tuple_t = kumi::tuple<char,short,int,double>;
    
  constexpr auto id1 = kumi::indexes(0,1,2,3);
  constexpr auto id2 = kumi::indexes(1,2,3,0);
  constexpr auto id3 = kumi::indexes(3,3);
  constexpr auto id4 = kumi::indexes(1,2,3, kumi::indexes(0,1,2));

  TTS_TYPE_IS( (kumi::result::reindex_t<tuple_t,id1>    ), tuple_t                                                      );
  TTS_TYPE_IS( (kumi::result::reindex_t<tuple_t,id2>    ), (kumi::tuple<short,int,double,char>)                         );
  TTS_TYPE_IS( (kumi::result::reindex_t<tuple_t,id3>    ), (kumi::tuple<double,double>)                                 );
  TTS_TYPE_IS( (kumi::result::reindex_t<tuple_t, id4>   ), (kumi::tuple<short,int,double, kumi::tuple<char,short,int>>) );

  using nested_t = kumi::tuple<kumi::tuple<int, float>, int>;
  TTS_TYPE_IS( (kumi::result::reindex_t<nested_t, kumi::indexes(0)>), (kumi::tuple<kumi::tuple<int, float>>));
};

TTS_CASE("Check reindex<Indexes>(tuple) behavior")
{
  {
    auto t = kumi::tuple {1, 2., 3.4f, '5'};
    {
      constexpr auto id = kumi::indexes(0,1,2,3);
      auto s = kumi::reindex<id>(t);
      TTS_EQUAL(s, t);
    }

    {
      constexpr auto id = kumi::indexes(3,2,1,0);
      auto s = kumi::reindex<id>(t);
      TTS_EQUAL(s, (kumi::tuple{'5',3.4f,2.,1}));
    }

    {
      constexpr auto id = kumi::indexes(0,1,2);
      auto s = kumi::reindex<id>(t);
      TTS_EQUAL(s, (kumi::tuple{1,2.,3.4f}) );
    }

    {
      constexpr auto id = kumi::indexes(0,1);
      auto s = kumi::reindex<id>(t);
      TTS_EQUAL(s, (kumi::tuple{1,2.}) );
    }

    {
      constexpr auto id = kumi::indexes(0);
      auto s = kumi::reindex<id>(t);
      TTS_EQUAL(s, (kumi::tuple{1}) );
    }

    {
      constexpr auto id = kumi::indexes(1);
      auto s = kumi::reindex<id>(t);
      TTS_EQUAL(s, (kumi::tuple{2.}) );
    }

    {
      constexpr auto id = kumi::indexes(2);
      auto s = kumi::reindex<id>(t);
      TTS_EQUAL(s, (kumi::tuple{3.4f}) );
    }

    {
      constexpr auto id = kumi::indexes(3);
      auto s = kumi::reindex<id>(t);
      TTS_EQUAL(s, (kumi::tuple{'5'}) );
    }

    {
      constexpr auto id = kumi::indexes(0,1,2,3,2,1,0);
      auto s = kumi::reindex<id>(t);
      TTS_EQUAL(s, (kumi::tuple{1,2.,3.4f,'5',3.4f,2.,1}) );
    }
    {
      constexpr auto id = kumi::indexes(0,1,2,3,2,1,0);
      auto s = kumi::reindex<id>(std::move(t));
      TTS_EQUAL(s, (kumi::tuple{1,2.,3.4f,'5',3.4f,2.,1}) );
    }
    {
      constexpr auto id = kumi::indexes(0,1,2,3, kumi::indexes(3,2,1,0));
      auto s = kumi::reindex<id>(t);
      TTS_EQUAL(s, (kumi::tuple{1,2.,3.4f,'5',kumi::tuple{'5',3.4f,2.,1}}));
    }
  }
};

TTS_CASE("Check reindex<Indexes>(tuple) constexpr behavior")
{
  {
    constexpr auto t = kumi::tuple {1, 2., 3.4f, '5'};
    {
      constexpr auto id = kumi::indexes(0,1,2,3);
      constexpr auto s = kumi::reindex<id>(t);
      TTS_CONSTEXPR_EQUAL(s, t);
    }
    {
      constexpr auto id = kumi::indexes(3,2,1,0);
      constexpr auto s = kumi::reindex<id>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{'5',3.4f,2.,1}));
    }
    {
      constexpr auto id = kumi::indexes(0,1,2);
      constexpr auto s = kumi::reindex<id>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1,2.,3.4f}) );
    }
    {
      constexpr auto id = kumi::indexes(0,1);
      constexpr auto s = kumi::reindex<id>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1,2.}) );
    }
    {
      constexpr auto id = kumi::indexes(0);
      constexpr auto s = kumi::reindex<id>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1}) );
    }
    {
      constexpr auto id = kumi::indexes(1);
      constexpr auto s = kumi::reindex<id>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{2.}) );
    }
    {
      constexpr auto id = kumi::indexes(2);
      constexpr auto s = kumi::reindex<id>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{3.4f}) );
    }
    {
      constexpr auto id = kumi::indexes(3);
      constexpr auto s = kumi::reindex<id>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{'5'}) );
    }
    {
      constexpr auto id = kumi::indexes(0,1,2,3,2,1,0);
      constexpr auto s = kumi::reindex<id>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1,2.,3.4f,'5',3.4f,2.,1}) );
    }
    {
      constexpr auto id = kumi::indexes(0,1,2,3, kumi::indexes(3,2,1,0));
      constexpr auto s = kumi::reindex<id>(t);
      TTS_CONSTEXPR_EQUAL(s, (kumi::tuple{1,2.,3.4f,'5',kumi::tuple{'5',3.4f,2.,1}}));
    }
  }
};
