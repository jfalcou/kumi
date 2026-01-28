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
#include <type_traits>
#include "test.hpp"

TTS_CASE("Check result::filter_not_t<Func,Tuple> behavior")
{
  TTS_TYPE_IS((kumi::result::filter_not_t<std::is_integral, kumi::tuple<>>), (kumi::tuple<>));

  TTS_TYPE_IS((kumi::result::filter_not_t<std::is_integral, kumi::tuple<int, float, double>>),
              (kumi::tuple<float, double>));

  TTS_TYPE_IS((kumi::result::filter_not_t<std::is_rvalue_reference, kumi::tuple<int&, float&&, double const&>>),
              (kumi::tuple<int&, double const&>));
};

TTS_CASE("Check filter_not(kumi::tuple<>{}) behavior")
{
  TTS_EQUAL((kumi::filter_not<std::is_pointer>(kumi::tuple{})), (kumi::tuple<>{}));
};

TTS_CASE("Check filter_not() behavior with values")
{
  int a = 4;
  double b = 3.1415;
  float c = 0.01f;

  auto original = kumi::tuple{a, &a, b, &b, c, &c, 'z', nullptr};

  TTS_EQUAL(kumi::filter_not<std::is_pointer>(original), (kumi::tuple{a, b, c, 'z', nullptr}));

  TTS_EQUAL(kumi::filter_not<std::is_floating_point>(original), (kumi::tuple{a, &a, &b, &c, 'z', nullptr}));

  TTS_EQUAL(kumi::filter_not<std::is_null_pointer>(original), (kumi::tuple{
                                                                a,
                                                                &a,
                                                                b,
                                                                &b,
                                                                c,
                                                                &c,
                                                                'z',
                                                              }));

  auto t = kumi::tuple{1.f, 2, 'x', moveonly{}};
  TTS_EXPECT_COMPILES(t, { kumi::filter_not<is_not_moveonly_type>(std::move(t)); });
};

TTS_CASE("Check filter_not() behavior with reference")
{
  int a = 4;
  double b = 3.1415;

  auto original = kumi::tuple<int, int&, double, double&>{a, a, b, b};

  TTS_EQUAL(kumi::filter_not<std::is_lvalue_reference>(original), (kumi::tuple{a, b}));
};
