//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/array.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

template<int I> auto f(auto& t) -> decltype(get<I>(t))
{
  return get<I>(t);
}

TTS_CASE("Check access to kumi::array via indexing")
{
  using namespace kumi::literals;

  kumi::array t1 = {1};
  kumi::array t2 = {1, 2};
  kumi::array t3 = {1, 2, 3};
  kumi::array t4 = {4, 8, 16, 32};

  t1[0_c] = 42;
  TTS_EQUAL(t1[0_c], 42);

  t2[0_c] = 4;
  t2[1_c] = 69;
  TTS_EQUAL(t2[0_c], 4);
  TTS_EQUAL(t2[1_c], 69);

  t3[0_c] = 13;
  t3[1_c] = 42;
  t3[2_c] = 40;
  TTS_EQUAL(t3[0_c], 13);
  TTS_EQUAL(t3[1_c], 42);
  TTS_EQUAL(t3[2_c], 40);

  t4[0_c] = 54;
  t4[1_c] = 69;
  t4[2_c] = 420;
  t4[3_c] = 1337;
  TTS_EQUAL(t4[0_c], 54);
  TTS_EQUAL(t4[1_c], 69);
  TTS_EQUAL(t4[2_c], 420);
  TTS_EQUAL(t4[3_c], 1337);

  TTS_EQUAL(kumi::get<0>(std::move(t3)), 13);
  TTS_EQUAL(std::move(t3)[1_c], 42);

  TTS_EXPECT_NOT_COMPILES(t1, { get<2>(t1); });
  TTS_EXPECT_NOT_COMPILES(t1, { get<-1>(t1); });

  TTS_EXPECT_NOT_COMPILES(t1, { f<2>(t1); });
  TTS_EXPECT_NOT_COMPILES(t1, { f<-1>(t1); });
};

TTS_CASE("Check constexpr access to kumi::array via indexing")
{
  using namespace kumi::literals;

  constexpr kumi::array t1 = {1};
  constexpr kumi::array t2 = {1, 2};
  constexpr kumi::array t3 = {1, 2, 3};
  constexpr kumi::array t4 = {4, 8, 16, 32};

  TTS_CONSTEXPR_EQUAL(get<0>(t1), t1[0_c]);

  TTS_CONSTEXPR_EQUAL(get<0>(t2), t2[0_c]);
  TTS_CONSTEXPR_EQUAL(get<1>(t2), t2[1_c]);

  TTS_CONSTEXPR_EQUAL(get<0>(t3), t3[0_c]);
  TTS_CONSTEXPR_EQUAL(get<1>(t3), t3[1_c]);
  TTS_CONSTEXPR_EQUAL(get<2>(t3), t3[2_c]);

  TTS_CONSTEXPR_EQUAL(get<0>(t4), t4[0_c]);
  TTS_CONSTEXPR_EQUAL(get<1>(t4), t4[1_c]);
  TTS_CONSTEXPR_EQUAL(get<2>(t4), t4[2_c]);
  TTS_CONSTEXPR_EQUAL(get<3>(t4), t4[3_c]);
};
