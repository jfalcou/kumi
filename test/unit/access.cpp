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

TTS_CASE("Check access to kumi::tuple via indexing")
{
  using namespace kumi::literals;

  kumi::tuple t1 = {1};
  kumi::tuple t2 = {1.f, 2};
  kumi::tuple t3 = {1., 2.f, 3};
  kumi::tuple t4 = {'1', 2., 3.f, 4};

  t1[0_c] = 42;
  TTS_EQUAL(t1[0_c], 42);

  t2[0_c] = 4.2f;
  t2[1_c] = 69;
  TTS_EQUAL(t2[0_c], 4.2f);
  TTS_EQUAL(t2[1_c], 69);

  t3[0_c] = 13.37;
  t3[1_c] = 4.2f;
  t3[2_c] = 40;
  TTS_EQUAL(t3[0_c], 13.37);
  TTS_EQUAL(t3[1_c], 4.2f);
  TTS_EQUAL(t3[2_c], 40);

  t4[0_c] = 'z';
  t4[1_c] = 6.9;
  t4[2_c] = 4.2f;
  t4[3_c] = 1337;
  TTS_EQUAL(t4[0_c], 'z');
  TTS_EQUAL(t4[1_c], 6.9);
  TTS_EQUAL(t4[2_c], 4.2f);
  TTS_EQUAL(t4[3_c], 1337);
};

TTS_CASE("Check access to kumi::tuple with named fields via indexing")
{
  using namespace kumi::literals;

  kumi::tuple t1 = {"x"_m = 1};
  kumi::tuple t2 = {"x"_m = 1.f, "y"_m = 2};
  kumi::tuple t3 = {"x"_m = 1., "y"_m = 2.f, "z"_m = 3};
  kumi::tuple t4 = {"x"_m = '1', "y"_m = 2., "z"_m = 3.f, "t"_m = 4};
  
  t1[0_c] = 42;
  TTS_EQUAL(t1[0_c], 42);

  t2[0_c] = 4.2f;
  t2[1_c] = 69;
  TTS_EQUAL(t2[0_c], 4.2f);
  TTS_EQUAL(t2[1_c], 69);

  t3[0_c] = 13.37;
  t3[1_c] = 4.2f;
  t3[2_c] = 40;
  TTS_EQUAL(t3[0_c], 13.37);
  TTS_EQUAL(t3[1_c], 4.2f);
  TTS_EQUAL(t3[2_c], 40);

  t4[0_c] = 'z';
  t4[1_c] = 6.9;
  t4[2_c] = 4.2f;
  t4[3_c] = 1337;
  TTS_EQUAL(t4[0_c], 'z');
  TTS_EQUAL(t4[1_c], 6.9);
  TTS_EQUAL(t4[2_c], 4.2f);
  TTS_EQUAL(t4[3_c], 1337);
};

TTS_CASE("Check access to kumi::tuple with names via names")
{
  using namespace kumi::literals;

  kumi::tuple t1 = {"x"_m = 1};
  kumi::tuple t2 = {"x"_m = 1.f, "y"_m = 2};
  kumi::tuple t3 = {"x"_m = 1., "y"_m = 2.f, "z"_m = 3};
  kumi::tuple t4 = {"x"_m = '1', "y"_m = 2., "z"_m = 3.f, "t"_m = 4};

  t1["x"_m] = 42;
  TTS_EQUAL(t1["x"_m], 42);

  t2["x"_m] = 4.2f;
  t2["y"_m] = 69;
  TTS_EQUAL(t2["x"_m], 4.2f);
  TTS_EQUAL(t2["y"_m], 69);

  t3["x"_m] = 13.37;
  t3["y"_m] = 4.2f;
  t3["z"_m] = 40;
  TTS_EQUAL(t3["x"_m], 13.37);
  TTS_EQUAL(t3["y"_m], 4.2f);
  TTS_EQUAL(t3["z"_m], 40);

  t4["x"_m] = 'z';
  t4["y"_m] = 6.9;
  t4["z"_m] = 4.2f;
  t4["t"_m] = 1337;
  TTS_EQUAL(t4["x"_m], 'z');
  TTS_EQUAL(t4["y"_m], 6.9);
  TTS_EQUAL(t4["z"_m], 4.2f);
  TTS_EQUAL(t4["t"_m], 1337);
};

TTS_CASE("Check constexpr access to kumi::tuple via indexing")
{
  using namespace kumi::literals;

  constexpr kumi::tuple t1 = {1};
  constexpr kumi::tuple t2 = {1.f, 2};
  constexpr kumi::tuple t3 = {1., 2.f, 3};
  constexpr kumi::tuple t4 = {'1', 2., 3.f, 4};

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

TTS_CASE("Check constexpr access to kumi::tuple with named fields via indexing")
{
  using namespace kumi::literals;

  constexpr kumi::tuple t1 = {"x"_m = 1};
  constexpr kumi::tuple t2 = {"x"_m = 1.f, "y"_m = 2};
  constexpr kumi::tuple t3 = {"x"_m = 1., "y"_m = 2.f, "z"_m = 3};
  constexpr kumi::tuple t4 = {"x"_m = '1', "y"_m = 2., "z"_m = 3.f, "t"_m = 4};
  
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

TTS_CASE("Check constexpr access to kumi::tuple with named fields via names")
{
  using namespace kumi::literals;

  constexpr kumi::tuple t1 = {"x"_m = 1};
  constexpr kumi::tuple t2 = {"x"_m = 1.f, "y"_m = 2};
  constexpr kumi::tuple t3 = {"x"_m = 1., "y"_m = 2.f, "z"_m = 3};
  constexpr kumi::tuple t4 = {"x"_m = '1', "y"_m = 2., "z"_m = 3.f, "t"_m = 4};
  
  TTS_CONSTEXPR_EQUAL(get<"x"_m>(t1), t1["x"_m]);

  TTS_CONSTEXPR_EQUAL(get<"x"_m>(t2), t2["x"_m]);
  TTS_CONSTEXPR_EQUAL(get<"y"_m>(t2), t2["y"_m]);

  TTS_CONSTEXPR_EQUAL(get<"x"_m>(t3), t3["x"_m]);
  TTS_CONSTEXPR_EQUAL(get<"y"_m>(t3), t3["y"_m]);
  TTS_CONSTEXPR_EQUAL(get<"z"_m>(t3), t3["z"_m]);

  TTS_CONSTEXPR_EQUAL(get<"x"_m>(t4), t4["x"_m]);
  TTS_CONSTEXPR_EQUAL(get<"y"_m>(t4), t4["y"_m]);
  TTS_CONSTEXPR_EQUAL(get<"z"_m>(t4), t4["z"_m]);
  TTS_CONSTEXPR_EQUAL(get<"t"_m>(t4), t4["t"_m]);
};
