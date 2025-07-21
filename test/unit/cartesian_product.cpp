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
#include <string>

TTS_CASE("Check result::cartesian_product<Tuple...> behavior")
{
  TTS_TYPE_IS( kumi::result::cartesian_product_t<>, kumi::tuple<>);

  TTS_TYPE_IS ( (kumi::result::cartesian_product_t<kumi::tuple<int,float,double>>)
              , (kumi::tuple<kumi::tuple<int>,kumi::tuple<float>,kumi::tuple<double>>)
              );

  TTS_TYPE_IS ( (kumi::result::cartesian_product_t<kumi::tuple<int&,float,double const&>>)
              , (kumi::tuple<kumi::tuple<int&>,kumi::tuple<float>,kumi::tuple<double const&>>)
              );

  TTS_TYPE_IS ( (kumi::result::cartesian_product_t<kumi::tuple<int,float,double>, kumi::tuple<int*,float*>>)
              , (kumi::tuple< kumi::tuple<int, int*>  , kumi::tuple<float, int*>  , kumi::tuple<double, int*>
                            , kumi::tuple<int, float*>, kumi::tuple<float, float*>, kumi::tuple<double, float*>
                            >)
              );
};

TTS_CASE("Check cartesian_product() behavior")
{
  TTS_EQUAL( kumi::cartesian_product(), kumi::tuple<>{} );
};

TTS_CASE("Check cartesian_product() behavior with references")
{
  int   a = 0;
  auto t0 = kumi::tuple<int,int&,int const&>{a,a,a};
  auto cp0 = kumi::cartesian_product(t0);

  kumi::get<0>(kumi::get<0>(cp0))++;
  kumi::get<0>(kumi::get<1>(cp0)) = 10;

  TTS_EQUAL(a, 10);
  TTS_EQUAL(kumi::get<0>(kumi::get<0>(cp0)), 1);
  TTS_EQUAL(kumi::get<0>(kumi::get<2>(cp0)), 10);
};

TTS_CASE("Check cartesian_product(ts...) behavior")
{
  using namespace std::literals;

  auto t1 = kumi::make_tuple(1,2ULL);
  auto t2 = kumi::make_tuple(1.2,3.4f,5.6);
  auto t3 = kumi::make_tuple("first"s, "second"s, "third"s, "fourth"s);
  auto cp = kumi::cartesian_product(t1,t2,t3);

  TTS_EQUAL( kumi::get<0>(kumi::get< 0>(cp)), kumi::get<0>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get< 0>(cp)), kumi::get<0>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get< 0>(cp)), kumi::get<0>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get< 1>(cp)), kumi::get<1>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get< 1>(cp)), kumi::get<0>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get< 1>(cp)), kumi::get<0>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get< 2>(cp)), kumi::get<0>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get< 2>(cp)), kumi::get<1>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get< 2>(cp)), kumi::get<0>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get< 3>(cp)), kumi::get<1>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get< 3>(cp)), kumi::get<1>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get< 3>(cp)), kumi::get<0>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get< 4>(cp)), kumi::get<0>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get< 4>(cp)), kumi::get<2>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get< 4>(cp)), kumi::get<0>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get< 5>(cp)), kumi::get<1>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get< 5>(cp)), kumi::get<2>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get< 5>(cp)), kumi::get<0>(t3) );

  TTS_EQUAL( kumi::get<0>(kumi::get< 6>(cp)), kumi::get<0>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get< 6>(cp)), kumi::get<0>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get< 6>(cp)), kumi::get<1>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get< 7>(cp)), kumi::get<1>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get< 7>(cp)), kumi::get<0>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get< 7>(cp)), kumi::get<1>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get< 8>(cp)), kumi::get<0>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get< 8>(cp)), kumi::get<1>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get< 8>(cp)), kumi::get<1>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get< 9>(cp)), kumi::get<1>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get< 9>(cp)), kumi::get<1>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get< 9>(cp)), kumi::get<1>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get<10>(cp)), kumi::get<0>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<10>(cp)), kumi::get<2>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<10>(cp)), kumi::get<1>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get<11>(cp)), kumi::get<1>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<11>(cp)), kumi::get<2>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<11>(cp)), kumi::get<1>(t3) );

  TTS_EQUAL( kumi::get<0>(kumi::get<12>(cp)), kumi::get<0>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<12>(cp)), kumi::get<0>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<12>(cp)), kumi::get<2>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get<13>(cp)), kumi::get<1>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<13>(cp)), kumi::get<0>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<13>(cp)), kumi::get<2>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get<14>(cp)), kumi::get<0>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<14>(cp)), kumi::get<1>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<14>(cp)), kumi::get<2>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get<15>(cp)), kumi::get<1>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<15>(cp)), kumi::get<1>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<15>(cp)), kumi::get<2>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get<16>(cp)), kumi::get<0>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<16>(cp)), kumi::get<2>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<16>(cp)), kumi::get<2>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get<17>(cp)), kumi::get<1>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<17>(cp)), kumi::get<2>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<17>(cp)), kumi::get<2>(t3) );

  TTS_EQUAL( kumi::get<0>(kumi::get<18>(cp)), kumi::get<0>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<18>(cp)), kumi::get<0>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<18>(cp)), kumi::get<3>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get<19>(cp)), kumi::get<1>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<19>(cp)), kumi::get<0>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<19>(cp)), kumi::get<3>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get<20>(cp)), kumi::get<0>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<20>(cp)), kumi::get<1>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<20>(cp)), kumi::get<3>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get<21>(cp)), kumi::get<1>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<21>(cp)), kumi::get<1>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<21>(cp)), kumi::get<3>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get<22>(cp)), kumi::get<0>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<22>(cp)), kumi::get<2>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<22>(cp)), kumi::get<3>(t3) );
  TTS_EQUAL( kumi::get<0>(kumi::get<23>(cp)), kumi::get<1>(t1) );
  TTS_EQUAL( kumi::get<1>(kumi::get<23>(cp)), kumi::get<2>(t2) );
  TTS_EQUAL( kumi::get<2>(kumi::get<23>(cp)), kumi::get<3>(t3) );
};
