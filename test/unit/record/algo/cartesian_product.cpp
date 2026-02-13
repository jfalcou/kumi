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
#include <string>

using namespace kumi::literals;

TTS_CASE("Check result::cartesian_product<Record...> behavior")
{
  using int_f = kumi::field_capture<"a", int>;
  using int_ref_f = kumi::field_capture<"b", int&>;
  using int_ptr_f = kumi::field_capture<"c", int*>;
  using float_f = kumi::field_capture<"d", float>;
  using float_ptr_f = kumi::field_capture<"e", float*>;
  using double_f = kumi::field_capture<"f", double>;
  using double_cref_f = kumi::field_capture<"g", double const&>;

  TTS_TYPE_IS(kumi::result::cartesian_product_t<>, kumi::tuple<>);

  TTS_TYPE_IS((kumi::result::cartesian_product_t<kumi::record<int_f, float_f, double_f>>),
              (kumi::tuple<kumi::record<int_f>, kumi::record<float_f>, kumi::record<double_f>>));

  TTS_TYPE_IS((kumi::result::cartesian_product_t<kumi::record<int_ref_f, float_f, double_cref_f>>),
              (kumi::tuple<kumi::record<int_ref_f>, kumi::record<float_f>, kumi::record<double_cref_f>>));

  TTS_TYPE_IS(
    (kumi::result::cartesian_product_t<kumi::record<int_f, float_f, double_f>, kumi::record<int_ptr_f, float_ptr_f>>),
    (kumi::tuple<kumi::record<int_f, int_ptr_f>, kumi::record<float_f, int_ptr_f>, kumi::record<double_f, int_ptr_f>,
                 kumi::record<int_f, float_ptr_f>, kumi::record<float_f, float_ptr_f>,
                 kumi::record<double_f, float_ptr_f>>));
};

TTS_CASE("Check cartesian_product() behavior")
{
  TTS_EQUAL(kumi::cartesian_product(), kumi::tuple<>{});
};

TTS_CASE("Check cartesian_product() behavior with references")
{
  using int_f = kumi::field_capture<"a", int>;
  using int_ref_f = kumi::field_capture<"b", int&>;
  using int_cref_f = kumi::field_capture<"c", int const&>;

  int a = 0;
  auto t0 = kumi::record<int_f, int_ref_f, int_cref_f>{a, a, a};
  auto cp0 = kumi::cartesian_product(t0);

  kumi::get<"a"_f>(kumi::get<0>(cp0))++;
  kumi::get<"b"_f>(kumi::get<1>(cp0)) = 10;

  TTS_EQUAL(a, 10);
  TTS_EQUAL(kumi::get<"a"_f>(kumi::get<0>(cp0)), 1);
  TTS_EQUAL(kumi::get<"c"_f>(kumi::get<2>(cp0)), 10);
};

TTS_CASE("Check cartesian_product(ts...) behavior")
{
  using namespace std::literals;
  using namespace kumi::literals;

  auto t1 = kumi::make_record("a"_f = 1, "b"_f = 2ULL);
  auto t2 = kumi::make_record("c"_f = 1.2, "d"_f = 3.4f, "e"_f = 5.6);
  auto t3 = kumi::make_record("f"_f = "first"s, "g"_f = "second"s, "h"_f = "third"s, "i"_f = "fourth"s);
  auto cp = kumi::cartesian_product(t1, t2, t3);

  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<0>(cp))), kumi::field_value_of(kumi::get<0>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<0>(cp))), kumi::field_value_of(kumi::get<0>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<0>(cp))), kumi::field_value_of(kumi::get<0>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<1>(cp))), kumi::field_value_of(kumi::get<1>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<1>(cp))), kumi::field_value_of(kumi::get<0>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<1>(cp))), kumi::field_value_of(kumi::get<0>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<2>(cp))), kumi::field_value_of(kumi::get<0>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<2>(cp))), kumi::field_value_of(kumi::get<1>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<2>(cp))), kumi::field_value_of(kumi::get<0>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<3>(cp))), kumi::field_value_of(kumi::get<1>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<3>(cp))), kumi::field_value_of(kumi::get<1>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<3>(cp))), kumi::field_value_of(kumi::get<0>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<4>(cp))), kumi::field_value_of(kumi::get<0>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<4>(cp))), kumi::field_value_of(kumi::get<2>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<4>(cp))), kumi::field_value_of(kumi::get<0>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<5>(cp))), kumi::field_value_of(kumi::get<1>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<5>(cp))), kumi::field_value_of(kumi::get<2>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<5>(cp))), kumi::field_value_of(kumi::get<0>(t3)));

  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<6>(cp))), kumi::field_value_of(kumi::get<0>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<6>(cp))), kumi::field_value_of(kumi::get<0>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<6>(cp))), kumi::field_value_of(kumi::get<1>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<7>(cp))), kumi::field_value_of(kumi::get<1>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<7>(cp))), kumi::field_value_of(kumi::get<0>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<7>(cp))), kumi::field_value_of(kumi::get<1>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<8>(cp))), kumi::field_value_of(kumi::get<0>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<8>(cp))), kumi::field_value_of(kumi::get<1>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<8>(cp))), kumi::field_value_of(kumi::get<1>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<9>(cp))), kumi::field_value_of(kumi::get<1>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<9>(cp))), kumi::field_value_of(kumi::get<1>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<9>(cp))), kumi::field_value_of(kumi::get<1>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<10>(cp))), kumi::field_value_of(kumi::get<0>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<10>(cp))), kumi::field_value_of(kumi::get<2>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<10>(cp))), kumi::field_value_of(kumi::get<1>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<11>(cp))), kumi::field_value_of(kumi::get<1>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<11>(cp))), kumi::field_value_of(kumi::get<2>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<11>(cp))), kumi::field_value_of(kumi::get<1>(t3)));

  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<12>(cp))), kumi::field_value_of(kumi::get<0>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<12>(cp))), kumi::field_value_of(kumi::get<0>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<12>(cp))), kumi::field_value_of(kumi::get<2>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<13>(cp))), kumi::field_value_of(kumi::get<1>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<13>(cp))), kumi::field_value_of(kumi::get<0>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<13>(cp))), kumi::field_value_of(kumi::get<2>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<14>(cp))), kumi::field_value_of(kumi::get<0>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<14>(cp))), kumi::field_value_of(kumi::get<1>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<14>(cp))), kumi::field_value_of(kumi::get<2>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<15>(cp))), kumi::field_value_of(kumi::get<1>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<15>(cp))), kumi::field_value_of(kumi::get<1>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<15>(cp))), kumi::field_value_of(kumi::get<2>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<16>(cp))), kumi::field_value_of(kumi::get<0>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<16>(cp))), kumi::field_value_of(kumi::get<2>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<16>(cp))), kumi::field_value_of(kumi::get<2>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<17>(cp))), kumi::field_value_of(kumi::get<1>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<17>(cp))), kumi::field_value_of(kumi::get<2>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<17>(cp))), kumi::field_value_of(kumi::get<2>(t3)));

  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<18>(cp))), kumi::field_value_of(kumi::get<0>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<18>(cp))), kumi::field_value_of(kumi::get<0>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<18>(cp))), kumi::field_value_of(kumi::get<3>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<19>(cp))), kumi::field_value_of(kumi::get<1>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<19>(cp))), kumi::field_value_of(kumi::get<0>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<19>(cp))), kumi::field_value_of(kumi::get<3>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<20>(cp))), kumi::field_value_of(kumi::get<0>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<20>(cp))), kumi::field_value_of(kumi::get<1>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<20>(cp))), kumi::field_value_of(kumi::get<3>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<21>(cp))), kumi::field_value_of(kumi::get<1>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<21>(cp))), kumi::field_value_of(kumi::get<1>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<21>(cp))), kumi::field_value_of(kumi::get<3>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<22>(cp))), kumi::field_value_of(kumi::get<0>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<22>(cp))), kumi::field_value_of(kumi::get<2>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<22>(cp))), kumi::field_value_of(kumi::get<3>(t3)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<0>(kumi::get<23>(cp))), kumi::field_value_of(kumi::get<1>(t1)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<1>(kumi::get<23>(cp))), kumi::field_value_of(kumi::get<2>(t2)));
  TTS_EQUAL(kumi::field_value_of(kumi::get<2>(kumi::get<23>(cp))), kumi::field_value_of(kumi::get<3>(t3)));
};
