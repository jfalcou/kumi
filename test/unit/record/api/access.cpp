//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/record.hpp>
#include <kumi/algorithm.hpp>
#include <tts/tts.hpp>
#include "test.hpp"

template<int I> auto f(auto& t) -> decltype(get<I>(t))
{
  return get<I>(t);
}

template<kumi::str S> auto g(auto& t) -> decltype(get<S>(t))
{
  return get<S>(t);
}

using namespace kumi::literals;

TTS_CASE("Check access to kumi::record via indexing")
{
  kumi::record t1 = {"x"_n = 1};
  kumi::record t2 = {"x"_n = 1.f, "y"_n = 2};
  kumi::record t3 = {"x"_n = 1., "y"_n = 2.f, "z"_n = 3};
  kumi::record t4 = {"x"_n = '1', "y"_n = 2., "z"_n = 3.f, "t"_n = 4};
  kumi::record t5 = {custom_ = 1.0f, coord_ = kumi::none, is_transparent_, is_modal_, unroll<8>};

  kumi::field_value_of(t1[0_c]) = 42;
  TTS_EQUAL(kumi::field_value_of(t1[0_c]), 42);
  TTS_EQUAL(kumi::field_value_of(t1[0_c]), 42);

  kumi::field_value_of(t2[0_c]) = 4.2f;
  kumi::field_value_of(t2[1_c]) = 69;
  TTS_EQUAL(kumi::field_value_of(t2[0_c]), 4.2f);
  TTS_EQUAL(kumi::field_value_of(t2[1_c]), 69);

  kumi::field_value_of(t3[0_c]) = 13.37;
  kumi::field_value_of(t3[1_c]) = 4.2f;
  kumi::field_value_of(t3[2_c]) = 40;

  TTS_EQUAL(kumi::field_value_of(t3[0_c]), 13.37);
  TTS_EQUAL(kumi::field_value_of(t3[1_c]), 4.2f);
  TTS_EQUAL(kumi::field_value_of(t3[2_c]), 40);

  kumi::field_value_of(t4[0_c]) = 'z';
  kumi::field_value_of(t4[1_c]) = 6.9;
  kumi::field_value_of(t4[2_c]) = 4.2f;
  kumi::field_value_of(t4[3_c]) = 1337;

  TTS_EQUAL(kumi::field_value_of(t4[0_c]), 'z');
  TTS_EQUAL(kumi::field_value_of(t4[1_c]), 6.9);
  TTS_EQUAL(kumi::field_value_of(t4[2_c]), 4.2f);
  TTS_EQUAL(kumi::field_value_of(t4[3_c]), 1337);

  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(std::move(t3))), 13.37);
  TTS_EQUAL(kumi::field_value_of(std::move(t3)[1_c]), 4.2f);

  TTS_EQUAL(kumi::field_value_of(t5[0_c]), 1.0f);
  TTS_EQUAL(kumi::field_value_of(t5[1_c]), kumi::none);
  TTS_EQUAL(kumi::field_value_of(t5[2_c]), true);
  TTS_EQUAL(kumi::field_value_of(t5[3_c]), true);
  TTS_EQUAL(kumi::field_value_of(t5[4_c]), 8);

  TTS_EXPECT_NOT_COMPILES(t1, { get<2>(t1); });
  TTS_EXPECT_NOT_COMPILES(t1, { get<-1>(t1); });

  TTS_EXPECT_NOT_COMPILES(t1, { f<2>(t1); });
  TTS_EXPECT_NOT_COMPILES(t1, { f<-1>(t1); });
};

TTS_CASE("Check access to kumi::record via names")
{
  kumi::record t1 = {"x"_n = 1};
  kumi::record t2 = {"x"_n = 1.f, "y"_n = 2};
  kumi::record t3 = {"x"_n = 1., "y"_n = 2.f, "z"_n = 3};
  kumi::record t4 = {"x"_n = '1', "y"_n = 2., "z"_n = 3.f, "t"_n = 4};
  kumi::record t5 = {custom_ = 1.0f, coord_ = kumi::none, is_transparent_, is_modal_, unroll<8>};

  t1["x"_n] = 42;
  TTS_EQUAL(t1["x"_n], 42);

  t2["x"_n] = 4.2f;
  t2["y"_n] = 69;
  TTS_EQUAL(t2["x"_n], 4.2f);
  TTS_EQUAL(t2["y"_n], 69);

  t3["x"_n] = 13.37;
  t3["y"_n] = 4.2f;
  t3["z"_n] = 40;
  TTS_EQUAL(t3["x"_n], 13.37);
  TTS_EQUAL(t3["y"_n], 4.2f);
  TTS_EQUAL(t3["z"_n], 40);

  t4["x"_n] = 'z';
  t4["y"_n] = 6.9;
  t4["z"_n] = 4.2f;
  t4["t"_n] = 1337;
  TTS_EQUAL(t4["x"_n], 'z');
  TTS_EQUAL(t4["y"_n], 6.9);
  TTS_EQUAL(t4["z"_n], 4.2f);
  TTS_EQUAL(t4["t"_n], 1337);

  TTS_EQUAL(t5[custom_], 1.0f);
  TTS_EQUAL(t5[coord_], kumi::none);
  TTS_EQUAL(t5["is_transparent_"_id], true);
  TTS_EQUAL(t5["is_modal_"_id], true);
  TTS_EQUAL(t5[unrolling{}], 8);

  TTS_EQUAL(kumi::get<"x"_n>(std::move(t3)), 13.37);
  TTS_EQUAL(std::move(t3)["y"_n], 4.2f);

  TTS_EXPECT_NOT_COMPILES(t1, { get<"y"_n>(t1); });
  TTS_EXPECT_NOT_COMPILES(t1, { g<"y"_n>(t1); });
};

TTS_CASE("Check constexpr access to kumi::record with named fields via indexing")
{
  constexpr kumi::record t1 = {"x"_n = 1};
  constexpr kumi::record t2 = {"x"_n = 1.f, "y"_n = 2};
  constexpr kumi::record t3 = {"x"_n = 1., "y"_n = 2.f, "z"_n = 3};
  constexpr kumi::record t4 = {"x"_n = '1', "y"_n = 2., "z"_n = 3.f, "t"_n = 4};
  constexpr kumi::record t5 = {custom_ = 1.0f, coord_ = kumi::none, is_transparent_, is_modal_, unroll<8>};

  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<0>(t1)), kumi::field_value_of(t1[0_c]));

  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<0>(t2)), kumi::field_value_of(t2[0_c]));
  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<1>(t2)), kumi::field_value_of(t2[1_c]));

  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<0>(t3)), kumi::field_value_of(t3[0_c]));
  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<1>(t3)), kumi::field_value_of(t3[1_c]));
  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<2>(t3)), kumi::field_value_of(t3[2_c]));

  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<0>(t4)), kumi::field_value_of(t4[0_c]));
  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<1>(t4)), kumi::field_value_of(t4[1_c]));
  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<2>(t4)), kumi::field_value_of(t4[2_c]));
  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<3>(t4)), kumi::field_value_of(t4[3_c]));

  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<0>(t5)), kumi::field_value_of(t5[0_c]));
  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<1>(t5)), kumi::field_value_of(t5[1_c]));
  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<2>(t5)), kumi::field_value_of(t5[2_c]));
  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<3>(t5)), kumi::field_value_of(t5[3_c]));
  TTS_CONSTEXPR_EQUAL(kumi::field_value_of(get<3>(t5)), kumi::field_value_of(t5[3_c]));
};

TTS_CASE("Check constexpr access to kumi::record with named fields via names")
{
  constexpr kumi::record t1 = {"x"_n = 1};
  constexpr kumi::record t2 = {"x"_n = 1.f, "y"_n = 2};
  constexpr kumi::record t3 = {"x"_n = 1., "y"_n = 2.f, "z"_n = 3};
  constexpr kumi::record t4 = {"x"_n = '1', "y"_n = 2., "z"_n = 3.f, "t"_n = 4};
  constexpr kumi::record t5 = {custom_ = 1.0f, coord_ = kumi::none, is_transparent_, is_modal_, unroll<8>};

  TTS_CONSTEXPR_EQUAL(get<"x"_n>(t1), t1["x"_n]);

  TTS_CONSTEXPR_EQUAL(get<"x"_n>(t2), t2["x"_n]);
  TTS_CONSTEXPR_EQUAL(get<"y"_n>(t2), t2["y"_n]);

  TTS_CONSTEXPR_EQUAL(get<"x"_n>(t3), t3["x"_n]);
  TTS_CONSTEXPR_EQUAL(get<"y"_n>(t3), t3["y"_n]);
  TTS_CONSTEXPR_EQUAL(get<"z"_n>(t3), t3["z"_n]);

  TTS_CONSTEXPR_EQUAL(get<"x"_n>(t4), t4["x"_n]);
  TTS_CONSTEXPR_EQUAL(get<"y"_n>(t4), t4["y"_n]);
  TTS_CONSTEXPR_EQUAL(get<"z"_n>(t4), t4["z"_n]);
  TTS_CONSTEXPR_EQUAL(get<"t"_n>(t4), t4["t"_n]);

  TTS_CONSTEXPR_EQUAL(get<custom_>(t5), t5[custom_]);
  TTS_CONSTEXPR_EQUAL(get<coord_>(t5), t5[coord_]);
  TTS_CONSTEXPR_EQUAL(get<"is_transparent_"_id>(t5), t5["is_transparent_"_id]);
  TTS_CONSTEXPR_EQUAL(get<"is_modal_"_id>(t5), t5["is_modal_"_id]);
  TTS_CONSTEXPR_EQUAL(get<unrolling{}>(t5), t5[unrolling{}]);
};
