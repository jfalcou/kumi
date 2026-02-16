//==================================================================================================
/*
  KUMI - Compact Tuple Tools
  Copyright : KUMI Project Contributors
  SPDX-License-Identifier: BSL-1.0
*/
//==================================================================================================
#define TTS_MAIN
#include <kumi/product_types/tuple.hpp>
#include <kumi/algorithm.hpp>
#include "test.hpp"
#include <tts/tts.hpp>

template<int I> auto f(auto& t) -> decltype(get<I>(t))
{
  return get<I>(t);
}

template<kumi::str S> auto g(auto& t) -> decltype(get<S>(t))
{
  return get<S>(t);
}

template<typename U> auto h(auto& t) -> decltype(get<U>(t))
{
  return get<U>(t);
}

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

  TTS_EQUAL(kumi::get<0>(std::move(t3)), 13.37);
  TTS_EQUAL(std::move(t3)[1_c], 4.2f);

  TTS_EXPECT_NOT_COMPILES(t1, { get<2>(t1); });
  TTS_EXPECT_NOT_COMPILES(t1, { get<-1>(t1); });

  TTS_EXPECT_NOT_COMPILES(t1, { f<2>(t1); });
  TTS_EXPECT_NOT_COMPILES(t1, { f<-1>(t1); });
};

TTS_CASE("Check access to kumi::tuple with named fields via indexing")
{
  using namespace kumi::literals;

  kumi::tuple t1 = {"x"_id = 1};
  kumi::tuple t2 = {"x"_id = 1.f, "y"_id = 2};
  kumi::tuple t3 = {"x"_id = 1., "y"_id = 2.f, "z"_id = 3};
  kumi::tuple t4 = {"x"_id = '1', "y"_id = 2., "z"_id = 3.f, "t"_id = 4};
  kumi::tuple t5 = {custom_ = 1.0f, coord_ = kumi::none, is_transparent_, is_modal_, unroll<8>};

  t1[0_c] = ("x"_id = 42);
  TTS_EQUAL(kumi::field_value_of(t1[0_c]), 42);
  TTS_EQUAL(kumi::field_value_of(t1[0_c]), 42);

  t2[0_c] = ("x"_id = 4.2f);
  t2[1_c] = ("y"_id = 69);
  TTS_EQUAL(kumi::field_value_of(t2[0_c]), 4.2f);
  TTS_EQUAL(kumi::field_value_of(t2[1_c]), 69);

  t3[0_c] = ("x"_id = 13.37);
  t3[1_c] = ("y"_id = 4.2f);
  t3[2_c] = ("z"_id = 40);

  TTS_EQUAL(kumi::field_value_of(t3[0_c]), 13.37);
  TTS_EQUAL(kumi::field_value_of(t3[1_c]), 4.2f);
  TTS_EQUAL(kumi::field_value_of(t3[2_c]), 40);

  t4[0_c] = ("x"_id = 'z');
  t4[1_c] = ("y"_id = 6.9);
  t4[2_c] = ("z"_id = 4.2f);
  t4[3_c] = ("t"_id = 1337);

  TTS_EQUAL(kumi::field_value_of(t4[0_c]), 'z');
  TTS_EQUAL(kumi::field_value_of(t4[1_c]), 6.9);
  TTS_EQUAL(kumi::field_value_of(t4[2_c]), 4.2f);
  TTS_EQUAL(kumi::field_value_of(t4[3_c]), 1337);

  TTS_EQUAL(kumi::get<0>(std::move(t3)).value, 13.37);
  TTS_EQUAL(kumi::field_value_of(std::move(t3)[1_c]), 4.2f);

  TTS_EQUAL(kumi::field_value_of(t5[0_c]), 1.0f);
  TTS_EQUAL(kumi::field_value_of(t5[1_c]), kumi::none);
  TTS_EQUAL(kumi::field_value_of(t5[2_c]), true);
  TTS_EQUAL(kumi::field_value_of(t5[3_c]), true);
  TTS_EQUAL(kumi::field_value_of(t5[4_c]), 8);

  TTS_EXPECT_NOT_COMPILES(t1, { f<2>(t1); });
  TTS_EXPECT_NOT_COMPILES(t1, { f<-1>(t1); });
};

TTS_CASE("Check access to kumi::tuple with names via names")
{
  using namespace kumi::literals;

  kumi::tuple t1 = {"x"_id = 1};
  kumi::tuple t2 = {"x"_id = 1.f, "y"_id = 2};
  kumi::tuple t3 = {"x"_id = 1., "y"_id = 2.f, "z"_id = 3};
  kumi::tuple t4 = {"x"_id = '1', "y"_id = 2., "z"_id = 3.f, "t"_id = 4};
  kumi::tuple t5 = {"x"_id = '1', 2., "z"_id = 3.f, 4};
  kumi::tuple t6 = {custom_ = 1.0f, coord_ = kumi::none, is_transparent_, is_modal_, unroll<8>};

  t1["x"_id] = 42;
  TTS_EQUAL(t1["x"_id], 42);

  t2["x"_id] = 4.2f;
  t2["y"_id] = 69;
  TTS_EQUAL(t2["x"_id], 4.2f);
  TTS_EQUAL(t2["y"_id], 69);

  t3["x"_id] = 13.37;
  t3["y"_id] = 4.2f;
  t3["z"_id] = 40;
  TTS_EQUAL(t3["x"_id], 13.37);
  TTS_EQUAL(t3["y"_id], 4.2f);
  TTS_EQUAL(t3["z"_id], 40);

  t4["x"_id] = 'z';
  t4["y"_id] = 6.9;
  t4["z"_id] = 4.2f;
  t4["t"_id] = 1337;
  TTS_EQUAL(t4["x"_id], 'z');
  TTS_EQUAL(t4["y"_id], 6.9);
  TTS_EQUAL(t4["z"_id], 4.2f);
  TTS_EQUAL(t4["t"_id], 1337);

  t5["x"_id] = 'z';
  t5[1_c] = 6.9;
  t5["z"_id] = 4.2f;
  t5[3_c] = 1337;
  TTS_EQUAL(t5["x"_id], 'z');
  TTS_EQUAL(t5[1_c], 6.9);
  TTS_EQUAL(t5["z"_id], 4.2f);
  TTS_EQUAL(t5[3_c], 1337);

  TTS_EQUAL(kumi::get<"x"_id>(std::move(t3)), 13.37);
  TTS_EQUAL(std::move(t3)["y"_id], 4.2f);

  TTS_EQUAL(t6[custom_], 1.0f);
  TTS_EQUAL(t6[coord_], kumi::none);
  TTS_EQUAL(t6["is_transparent_"_id], true);
  TTS_EQUAL(t6["is_modal_"_id], true);
  TTS_EQUAL(t6[unrolling{}], 8);

  TTS_EXPECT_NOT_COMPILES(t1, { get<"y"_id>(t1); });
  TTS_EXPECT_NOT_COMPILES(t1, { g<"y"_id>(t1); });
};

TTS_CASE("Check access to kumi::tuple via types")
{
  using namespace kumi::literals;

  kumi::tuple t1 = {1};
  kumi::tuple t2 = {1.f, 2};
  kumi::tuple t3 = {1., 2.f, 3};
  kumi::tuple t4 = {'1', 2., 3.f, 4};

  TTS_EQUAL(get<int>(t1), t1[0_c]);

  TTS_EQUAL(get<float>(t2), t2[0_c]);
  TTS_EQUAL(get<int>(t2), t2[1_c]);

  TTS_EQUAL(get<double>(t3), t3[0_c]);
  TTS_EQUAL(get<float>(t3), t3[1_c]);
  TTS_EQUAL(get<int>(t3), t3[2_c]);

  TTS_EQUAL(get<char>(t4), t4[0_c]);
  TTS_EQUAL(get<double>(t4), t4[1_c]);
  TTS_EQUAL(get<float>(t4), t4[2_c]);
  TTS_EQUAL(get<int>(t4), t4[3_c]);

  TTS_EXPECT_NOT_COMPILES(t1, { get<float>(t1); });
  TTS_EXPECT_NOT_COMPILES(t1, { h<float>(t1); });
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

  constexpr kumi::tuple t1 = {"x"_id = 1};
  constexpr kumi::tuple t2 = {"x"_id = 1.f, "y"_id = 2};
  constexpr kumi::tuple t3 = {"x"_id = 1., "y"_id = 2.f, "z"_id = 3};
  constexpr kumi::tuple t4 = {"x"_id = '1', "y"_id = 2., "z"_id = 3.f, "t"_id = 4};
  constexpr kumi::tuple t5 = {custom_ = 1.0f, coord_ = kumi::none, is_transparent_, is_modal_, unroll<8>};

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

TTS_CASE("Check constexpr access to kumi::tuple with named fields via names")
{
  using namespace kumi::literals;

  constexpr kumi::tuple t1 = {"x"_id = 1};
  constexpr kumi::tuple t2 = {"x"_id = 1.f, "y"_id = 2};
  constexpr kumi::tuple t3 = {"x"_id = 1., "y"_id = 2.f, "z"_id = 3};
  constexpr kumi::tuple t4 = {"x"_id = '1', "y"_id = 2., "z"_id = 3.f, "t"_id = 4};
  constexpr kumi::tuple t5 = {"x"_id = '1', 2, "z"_id = 3.f, 4};
  constexpr kumi::tuple t6 = {custom_ = 1.0f, coord_ = kumi::none, is_transparent_, is_modal_, unroll<8>};

  TTS_CONSTEXPR_EQUAL(get<"x"_id>(t1), t1["x"_id]);

  TTS_CONSTEXPR_EQUAL(get<"x"_id>(t2), t2["x"_id]);
  TTS_CONSTEXPR_EQUAL(get<"y"_id>(t2), t2["y"_id]);

  TTS_CONSTEXPR_EQUAL(get<"x"_id>(t3), t3["x"_id]);
  TTS_CONSTEXPR_EQUAL(get<"y"_id>(t3), t3["y"_id]);
  TTS_CONSTEXPR_EQUAL(get<"z"_id>(t3), t3["z"_id]);

  TTS_CONSTEXPR_EQUAL(get<"x"_id>(t4), t4["x"_id]);
  TTS_CONSTEXPR_EQUAL(get<"y"_id>(t4), t4["y"_id]);
  TTS_CONSTEXPR_EQUAL(get<"z"_id>(t4), t4["z"_id]);
  TTS_CONSTEXPR_EQUAL(get<"t"_id>(t4), t4["t"_id]);

  TTS_CONSTEXPR_EQUAL(get<"x"_id>(t5), t5["x"_id]);
  TTS_CONSTEXPR_EQUAL(get<1_c>(t5), t5[1_c]);
  TTS_CONSTEXPR_EQUAL(get<"z"_id>(t5), t5["z"_id]);
  TTS_CONSTEXPR_EQUAL(get<3_c>(t5), t5[3_c]);

  TTS_CONSTEXPR_EQUAL(get<custom_>(t6), t6[custom_]);
  TTS_CONSTEXPR_EQUAL(get<coord_>(t6), t6[coord_]);
  TTS_CONSTEXPR_EQUAL(get<"is_transparent_"_id>(t6), t6["is_transparent_"_id]);
  TTS_CONSTEXPR_EQUAL(get<"is_modal_"_id>(t6), t6["is_modal_"_id]);
  TTS_CONSTEXPR_EQUAL(get<unrolling{}>(t6), t6[unrolling{}]);
};
