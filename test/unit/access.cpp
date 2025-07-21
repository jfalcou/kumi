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

  TTS_EQUAL(kumi::get<0>(std::move(t3)) , 13.37 );
  TTS_EQUAL(std::move(t3)[1_c]          , 4.2f  );
};

TTS_CASE("Check access to kumi::tuple with named fields via indexing")
{
  using namespace kumi::literals;

  kumi::tuple t1 = {"x"_f = 1};
  kumi::tuple t2 = {"x"_f = 1.f, "y"_f = 2};
  kumi::tuple t3 = {"x"_f = 1., "y"_f = 2.f, "z"_f = 3};
  kumi::tuple t4 = {"x"_f = '1', "y"_f = 2., "z"_f = 3.f, "t"_f = 4};
  
  t1[0_c] = ( "x"_f = 42    );
  TTS_EQUAL(t1[0_c].value, 42);
  TTS_EQUAL(t1[0_c].value, 42);

  t2[0_c] = ( "x"_f = 4.2f  );
  t2[1_c] = ( "y"_f = 69    );
  TTS_EQUAL(t2[0_c].value, 4.2f);
  TTS_EQUAL(t2[1_c].value, 69);

  t3[0_c] = ( "x"_f = 13.37 );
  t3[1_c] = ( "y"_f = 4.2f  );
  t3[2_c] = ( "z"_f = 40    );
  TTS_EQUAL(t3[0_c].value, 13.37);
  TTS_EQUAL(t3[1_c].value, 4.2f);
  TTS_EQUAL(t3[2_c].value, 40);

  t4[0_c] = ( "x"_f = 'z'   );
  t4[1_c] = ( "y"_f = 6.9   );
  t4[2_c] = ( "z"_f = 4.2f  );
  t4[3_c] = ( "t"_f = 1337  );
  TTS_EQUAL(t4[0_c].value, 'z');
  TTS_EQUAL(t4[1_c].value, 6.9);
  TTS_EQUAL(t4[2_c].value, 4.2f);
  TTS_EQUAL(t4[3_c].value, 1337);

  TTS_EQUAL(kumi::get<0>(std::move(t3)).value   , 13.37 );
  TTS_EQUAL(std::move(t3)[1_c].value            , 4.2f  );
};

TTS_CASE("Check access to kumi::tuple with names via names")
{
  using namespace kumi::literals;

  kumi::tuple t1 = {"x"_f = 1};
  kumi::tuple t2 = {"x"_f = 1.f, "y"_f = 2};
  kumi::tuple t3 = {"x"_f = 1., "y"_f = 2.f, "z"_f = 3};
  kumi::tuple t4 = {"x"_f = '1', "y"_f = 2., "z"_f = 3.f, "t"_f = 4};

  t1["x"_f] = 42;
  TTS_EQUAL(t1["x"_f], 42);

  t2["x"_f] = 4.2f;
  t2["y"_f] = 69;
  TTS_EQUAL(t2["x"_f], 4.2f);
  TTS_EQUAL(t2["y"_f], 69);

  t3["x"_f] = 13.37;
  t3["y"_f] = 4.2f;
  t3["z"_f] = 40;
  TTS_EQUAL(t3["x"_f], 13.37);
  TTS_EQUAL(t3["y"_f], 4.2f);
  TTS_EQUAL(t3["z"_f], 40);

  t4["x"_f] = 'z';
  t4["y"_f] = 6.9;
  t4["z"_f] = 4.2f;
  t4["t"_f] = 1337;
  TTS_EQUAL(t4["x"_f], 'z');
  TTS_EQUAL(t4["y"_f], 6.9);
  TTS_EQUAL(t4["z"_f], 4.2f);
  TTS_EQUAL(t4["t"_f], 1337);

  TTS_EQUAL(kumi::get<"x"_f>(std::move(t3)) , 13.37 );
  TTS_EQUAL(std::move(t3)["y"_f]            , 4.2f  );
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

TTS_CASE("Check constexpr access to kumi::tuple via types")
{
  using namespace kumi::literals;

  constexpr kumi::tuple t1 = {1};
  constexpr kumi::tuple t2 = {1.f, 2};
  constexpr kumi::tuple t3 = {1., 2.f, 3};
  constexpr kumi::tuple t4 = {'1', 2., 3.f, 4};

  TTS_CONSTEXPR_EQUAL(get<int>(t1), t1[0_c]);

  TTS_CONSTEXPR_EQUAL(get<float>(t2), t2[0_c]);
  TTS_CONSTEXPR_EQUAL(get<int>(t2), t2[1_c]);

  TTS_CONSTEXPR_EQUAL(get<double>(t3), t3[0_c]);
  TTS_CONSTEXPR_EQUAL(get<float>(t3), t3[1_c]);
  TTS_CONSTEXPR_EQUAL(get<int>(t3), t3[2_c]);

  TTS_CONSTEXPR_EQUAL(get<char>(t4), t4[0_c]);
  TTS_CONSTEXPR_EQUAL(get<double>(t4), t4[1_c]);
  TTS_CONSTEXPR_EQUAL(get<float>(t4), t4[2_c]);
  TTS_CONSTEXPR_EQUAL(get<int>(t4), t4[3_c]);
};

TTS_CASE("Check constexpr access to kumi::tuple with named fields via indexing")
{
  using namespace kumi::literals;

  constexpr kumi::tuple t1 = {"x"_f = 1};
  constexpr kumi::tuple t2 = {"x"_f = 1.f, "y"_f = 2};
  constexpr kumi::tuple t3 = {"x"_f = 1., "y"_f = 2.f, "z"_f = 3};
  constexpr kumi::tuple t4 = {"x"_f = '1', "y"_f = 2., "z"_f = 3.f, "t"_f = 4};
  
  TTS_CONSTEXPR_EQUAL(get<0>(t1).value, t1[0_c].value);

  TTS_CONSTEXPR_EQUAL(get<0>(t2).value, t2[0_c].value);
  TTS_CONSTEXPR_EQUAL(get<1>(t2).value, t2[1_c].value);

  TTS_CONSTEXPR_EQUAL(get<0>(t3).value, t3[0_c].value);
  TTS_CONSTEXPR_EQUAL(get<1>(t3).value, t3[1_c].value);
  TTS_CONSTEXPR_EQUAL(get<2>(t3).value, t3[2_c].value);

  TTS_CONSTEXPR_EQUAL(get<0>(t4).value, t4[0_c].value);
  TTS_CONSTEXPR_EQUAL(get<1>(t4).value, t4[1_c].value);
  TTS_CONSTEXPR_EQUAL(get<2>(t4).value, t4[2_c].value);
  TTS_CONSTEXPR_EQUAL(get<3>(t4).value, t4[3_c].value);
};

TTS_CASE("Check constexpr access to kumi::tuple with named fields via names")
{
  using namespace kumi::literals;

  constexpr kumi::tuple t1 = {"x"_f = 1};
  constexpr kumi::tuple t2 = {"x"_f = 1.f, "y"_f = 2};
  constexpr kumi::tuple t3 = {"x"_f = 1., "y"_f = 2.f, "z"_f = 3};
  constexpr kumi::tuple t4 = {"x"_f = '1', "y"_f = 2., "z"_f = 3.f, "t"_f = 4};
  
  TTS_CONSTEXPR_EQUAL(get<"x"_f>(t1), t1["x"_f]);

  TTS_CONSTEXPR_EQUAL(get<"x"_f>(t2), t2["x"_f]);
  TTS_CONSTEXPR_EQUAL(get<"y"_f>(t2), t2["y"_f]);

  TTS_CONSTEXPR_EQUAL(get<"x"_f>(t3), t3["x"_f]);
  TTS_CONSTEXPR_EQUAL(get<"y"_f>(t3), t3["y"_f]);
  TTS_CONSTEXPR_EQUAL(get<"z"_f>(t3), t3["z"_f]);

  TTS_CONSTEXPR_EQUAL(get<"x"_f>(t4), t4["x"_f]);
  TTS_CONSTEXPR_EQUAL(get<"y"_f>(t4), t4["y"_f]);
  TTS_CONSTEXPR_EQUAL(get<"z"_f>(t4), t4["z"_f]);
  TTS_CONSTEXPR_EQUAL(get<"t"_f>(t4), t4["t"_f]);
};
